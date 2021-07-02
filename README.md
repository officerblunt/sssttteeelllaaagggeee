# sssttteeelllaaagggeee

## Учебный проект по РПМ.

Создание системы распознавания, каталогизации (штрих-коды) и зависимой системы управления светодиодами.

___

## How-to

#### Dependencies:

- MySQL
- Python

##### MySQL:

1. Установите MySQL.

2. Любыми средствами (командная строка, Workbench, phpMyAdmin, etc.) восстановите БД из дампа "cpp_led_control"

3. В командной выполните следующие команды:

   ```
   pip install mysql-connector-python
   ```

4.  Проверьте соединение с помощью:

      ```
      python
      import mysql.connector
      connection = mysql.connector.connect(user='root', password='*', host='*', database='cpp_led_control')
      print(connection.is_connected())
      ```

   - В зависимости от метода установки MySQL поля `password` и `host` будут различатся. Вот некоторые рекомендации:
   - Стандартные значения для XAMPP -  `password="", host="localhost"`
   - [Мини-руководство](https://coderoad.ru/4093603/%D0%9A%D0%B0%D0%BA-%D0%BC%D0%BD%D0%B5-%D1%83%D0%B7%D0%BD%D0%B0%D1%82%D1%8C-%D1%81%D0%B2%D0%BE%D0%B9-MySQL-URL-%D1%85%D0%BE%D1%81%D1%82-%D0%BF%D0%BE%D1%80%D1%82-%D0%B8-%D0%B8%D0%BC%D1%8F-%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8F) по поиску этих значений в MySQL

5. В зависимости от результата повторите пункты 1-5 до получения желаемого результата

##### Python:

1. В командной строке выполните следующие команды:

   ```python
   pip install opencv-python
   pip install pyzbar
   pip install serial
   ```

2. Для проверки корректности установки используйте:

   ```python
   python
   
   import cv2
   cv2.__version__
   
   import pyzbar
   pyzbar.__version__
   
   import serial
   serial.__version__
   ```

3. В случае отсутствия желаемого результата ищите пути установки библиотек самостоятельно.

4. Или если вам лень... воспользуетесь следующими ссылками: 

   - [Установка OpenCV](https://g.zeos.in/?q=how%20to%20install%20opencv-python%3F)
   - [Установка pyzbar](https://g.zeos.in/?q=how%20to%20install%20pyzbar%3F)
   - [Установка serial](https://g.zeos.in/?q=how%20to%20install%20serial%20library%20in%20python%3F)

------

## Используемые библиотеки

##### Генерация qr-кода:
1. http://qrcoder.ru/
##### Распознавание qr-кода:
1. https://github.com/opencv/opencv
2. http://zbar.sourceforge.net/api/
3. https://pypi.org/project/pyzbar/
##### Управление LED-лентой:
1. https://github.com/FastLED/FastLED

   
