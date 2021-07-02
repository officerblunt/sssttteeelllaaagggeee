import cv2
import serial
from pyzbar import pyzbar
from mysql.connector import connect, Error

# Задаём стандартный флаг "Отсутствие соединения"
flag = 2

# Создаём список всех возможных портов
ports = ['COM%s' % (i + 1) for i in range(256)]
# Пытаемся подключится ко всем по очереди
for port in ports:
    # Обработка исключений
    try:
        arduino = serial.Serial('COM14', 9600, timeout=1)
        print("\nWelcome to STELLAGE!\n")
        # Выставляем флаг 0 для входа в цикл
        flag = 0
        iterations = 0
    except serial.SerialException as e:
        if e.errno == 13:
            raise e
        pass
    except OSError:
        pass

while flag == 0:
    # Включаем первую камеру
    cap = cv2.VideoCapture(1, cv2.CAP_DSHOW)
    # Делаем снимок
    ret, frame = cap.read()
    # Расшифровываем снимок
    output = pyzbar.decode(frame)
    if output:
        data = output[0].data
        if data.decode("utf-8") == 'START':
            print("\nLet's begin!\n")
            # Задаём второй флаг для зацикливания
            flag_two = 0
            # Задаём стандартный SQL запрос для выбора соответствия из таблицы
            query_select = 'SELECT led FROM word_to_led WHERE word = "'
            while flag_two < 300:
                flag_two += 1
                # Делаем снимок
                ret, frame = cap.read()
                # Расшифровываем снимок
                output = pyzbar.decode(frame)
                if output:
                    data = output[0].data
                    decoded = data.decode("utf-8")
                    print(decoded)
                    # Обработка ошибок
                    try:
                        # Создание соединение с базой данных
                        with connect(
                                host="localhost",
                                user="root",
                                password="",
                                database="cpp_led_control",
                        ) as connection:
                            # Генерируем запрос на основе расшифрованного QR-кода
                            true_query = query_select + decoded + '";'
                            with connection.cursor() as cursor:
                                # Выполняем сгенерированный SQL-запрос
                                cursor.execute(true_query)
                                # Проверяем, получили ли мы соответствие
                                if cursor.fetchall():
                                    cursor.execute(true_query)
                                    ((message,),) = cursor.fetchall()
                                    # Перекодируем полученное соответствие в байты для передачи
                                    b = message.encode('utf-8')
                                    # Передаём запрос на вывод в Ардуино
                                    arduino.write(b)
                                    # Обнуление счёта итераций без ввода данных
                                    flag_two = 0
                                    print("Sent to A")
                                else:
                                    # Обнуление счёта итераций без ввода данных
                                    flag_two = 0
                                    print("The QR code has no match")
                    except Error as e:
                        print("Houston, we've run into an error!")
                        print(e)
                    # реализация локального выхода из программы
                    if data.decode("utf-8") == 'STOP':
                        print("\nGoodbye!\n")
                        flag_two = 301
                        flag = 1
                        cap.release()
                    # В случае если прошло уже 300 итераций без ввода данных
                    # произойдёт выход из цикла и установка флага на позицию 3:
                    # "Сообщение о длительном бездействии"
                    if flag_two == 300:
                        flag = 3
                    # Возможен вывод получаемых кадров на экран с помощью:
                    # cv2.imshow('frame', frame)
    iterations += 1
    if iterations == 200:
        # В случае если прошло уже 200 итераций без команды старт
        # произойдёт выход из цикла и установка флага на позицию 3:
        # "Сообщение о длительном бездействии"
        flag = 3
if flag == 3:
    # Закрываем соединение с Ардуино
    arduino.close()
    # Отключаем камеру
    cap.release()
    print("There was no input:")
    print("\tProcess self destructed")
if flag == 2:
    print("Seems like there was no connection:")
    print("\tTry to reconnect the Arduino")
if flag == 1:
    arduino.close()
    print("This is the end")
