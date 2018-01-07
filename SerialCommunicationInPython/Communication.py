# import pySerial
import serial

def read():
    ser = serial.Serial('/dev/ttyACM0', 9600)
    # ser = serial.Serial('/dev/tty.usbserial', 9600)
    while True:
        ser.write(b"2")
        print (ser.readline())


read()
