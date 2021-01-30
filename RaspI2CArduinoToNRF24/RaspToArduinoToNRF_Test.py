#Raspberry Pi Connected through I2C To a Master Arduino

import smbus
import time
import sys

bus = smbus.SMBus(1)
address = 0x69  # Arduino I2C Address
onByte = 0x20   # On Byte
offByte = 0x21  # Off Byte
TargetOneArduino = 0x01 # Arduino Thats being targeted
TargetTwoArduino = 0x02 # Arduino Thats being targeted

def main():
    i2cData = 0x00
    sendTarget = i2cData;
    sendState = "";
    while 1:
        # send data
        decision = int(input("What Arduino To target: [1,2]"))
        if(decision == 1):
            sendTarget = TargetOneArduino;
        elif(decision == 2):
            sendTarget = TargetTwoArduino;
        onoroff = input("On or Off?")
        if(onoroff == "on"):
            sendState = onByte;
        elif(onoroff== "off"):
            sendState = offByte;
        print("Decision: {} and state: {}".format(decision, onoroff))
        #bus.write_byte(address,onByte)
        bus.write_i2c_block_data(address, 48, [sendTarget, sendState] )
        # request data
        print ("Arduino answer to RPi:", bus.read_byte(address))

        time.sleep(1)

def SendDataPair(targetArduino, byte):
    bytePair = [targetArduino, byte]
    return bytePair


if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        gpio.cleanup()
        sys.exit(0)
