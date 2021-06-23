import cv2
import time
import serial
from sys import argv
from PIL import Image
from pyzbar import pyzbar

arduino = serial.Serial('COM14', 9600, timeout=1)

q = 0
i = 0
b = 0
# Включаем первую камеру
cap = cv2.VideoCapture(0)

while i == 0:
    # Делаем снимок
    ret, frame = cap.read()
    # Записываем в файл
    cv2.imwrite('c.png', frame)

    img = Image.open('c.png')
    output = pyzbar.decode(img)

    if output:
        data = output[0].data
        if data.decode("utf-8") == 'START':
            print("Hello!")
            x = 0
            while x == 0:
                ret, frame = cap.read()
                cv2.imwrite('x.png', frame)
                img = Image.open('x.png')
                output = pyzbar.decode(img)
                if output:
                    data = output[0].data
                    if data.decode("utf-8") == 'STOP':
                        arduino.write(b'X')
                        print("Goodbye!")
                        x = 1
                        i = 1
                        q = 1
                    else:
                        print(data.decode("utf-8"))
                        if data.decode("utf-8") == '1':
                            arduino.write(b'A')
                            print("sent")
                            time.sleep(1)
                        if data.decode("utf-8") == '2':
                            arduino.write(b'B')
                            print("sent")
                            time.sleep(1)
                        if data.decode("utf-8") == '3':
                            arduino.write(b'C')
                            print("sent")
                            time.sleep(1)
                        if data.decode("utf-8") == '4':
                            arduino.write(b'D')
                            print("sent")
                            time.sleep(1)
                        if data.decode("utf-8") == '5':
                            arduino.write(b'E')
                            print("sent")
                            time.sleep(1)
                        if data.decode("utf-8") == '6':
                            arduino.write(b'F')
                            print("sent")
                            time.sleep(1)
                        if data.decode("utf-8") == '7':
                            arduino.write(b'G')
                            print("sent")
                            time.sleep(1)
                        if data.decode("utf-8") == '8':
                            arduino.write(b'H')
                            print("sent")
                            time.sleep(1)
                        if data.decode("utf-8") == '9':
                            arduino.write(b'I')
                            print("sent")
                            time.sleep(1)
                        if data.decode("utf-8") == '10':
                            arduino.write(b'J')
                            print("sent")
                            time.sleep(1)
                        if data.decode("utf-8") == '11':
                            arduino.write(b'K')
                            print("sent")
                            time.sleep(1)
                        if data.decode("utf-8") == '12':
                            arduino.write(b'L')
                            print("sent")
                            time.sleep(1)
                        if data.decode("utf-8") == '13':
                            arduino.write(b'M')
                            print("sent")
                            time.sleep(1)
                        if data.decode("utf-8") == '14':
                            arduino.write(b'N')
                            print("sent")
                            time.sleep(1)
                        if data.decode("utf-8") == '15':
                            arduino.write(b'O')
                            print("sent")
                            time.sleep(1)
                        if data.decode("utf-8") == '16':
                            arduino.write(b'P')
                            print("sent")
                            time.sleep(1)
                        if data.decode("utf-8") == 'LEFT':
                            arduino.write(b'Y')
                            print("sent")
                            time.sleep(1)
                        if data.decode("utf-8") == 'RIGHT':
                            arduino.write(b'Z')
                            print("sent")
                            time.sleep(1)
#                       img.show()
    b += 1
    if b == 100:
        i = 1
arduino.close()
print("This is the end")
if q != 1:
    # Отключаем камеру
    cap.release()
    if len(argv) < 2:
        exit(1)
