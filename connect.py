# this code will read the touch values from the ESP32 and echo them on the command line

# pip install pyserial 
import serial
from playsound import playsound

# change the port as necessary by your OS
ser = serial.Serial('/dev/cu.wchusbserial531C0151591', 250000)

while(True):
  play = False

  a = str(ser.readline().strip(), 'ascii')
  print(a)
  print("ok")
  print("  ")

  b = str(ser.readline().strip(), 'ascii')
  print(b)
  print("ok")
  print("  ")

  if int(b)-int(a)>4:
    play = True
    
  if play:
    print("play")
    playsound('path_to_your_audio.mp3')
    print(" ")

