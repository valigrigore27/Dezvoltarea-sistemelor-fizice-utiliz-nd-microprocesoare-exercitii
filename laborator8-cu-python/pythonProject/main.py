import serial
import time

ser = serial.Serial('COM6', 9600)


def send_line_to_arduino(line):
    ser.write(line.encode())
    time.sleep(1)


file_path = 'file.txt'

with open(file_path, 'r') as file:
    lines = file.readlines()

for line in lines:
    send_line_to_arduino(line)

ser.close()
