/*
   Arduino code to send and receive I2C data

   Raspi | Arduino | Purpose
   0x01 ----> 0x01 : Signal to radio 1st Arduino
   0x02 ----> 0x02 : Signal to radio 2nd Arduino
   0x03 ----> 0x03 : Signal to radio 3rd Arduino
   0x04 ----> 0x04 : Signal to radio 4th Arduino

   0x20 ----> 0x20 : On Bit
   0x21 ----> 0x20 : Off Bit

*/
#include <Wire.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define SLAVE_ADDRESS 0x69       // I2C address for Arduino  
#define LED LED_BUILTIN                   // Built-in LED just for testing
#define arduinoOne 0x01
#define arduinoTwo 0x02

byte i2cData = 0x00; // the I2C data received initially set to 0
byte dataArray[] = {};
const uint64_t slaveOnePipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01
const uint64_t slaveTwoPipe = 0xE5E5E5E5E5E5; // Needs to be the same for communicating between 2 NRF24L01
int SentMessage[1] = {000}; // Used to store value before being sent through the NRF24L01

RF24 radio(9, 10); // CE, CSN

void setup() {
  Serial.begin(9600);
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(handleData);  // Sets up an Interrupt - Executes whenever data is recieved
  Wire.onRequest(sendData);  // Sets up an Interrupt - Executes whenever data is sent
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);

  // ---- Radio Setup ----
  radio.begin(); // Start the NRF24L01

}

void loop() {
  // Everything happens in the interrupts
}

void handleData(int byteCount) {
  while (Wire.available()) {
    for (int i = 0; i < 3; i++) {
      i2cData = Wire.read();
      // Make sure a negative one is not being recieved
      if (i2cData == -1) {
        Serial.println("Read a Negative Value, Break");
        break;
      } else {
        dataArray[i] = i2cData;
      }
    }
  }

  // Check Which Arduino To Radio
  byte slaveNumber = dataArray[1];
  // Grab setState variable: [HIGH or LOW] --> dataArray[2]
  byte setState = dataArray[2];
  // Radio That Arduino Specified instructions to do what you want it too --
  RadioArduino(slaveNumber, setState);

  // Print The Data Received
  SerialPrintReceivedData();

}

void RadioArduino(byte slavenum, byte state) {
  if (slavenum == 0x01) {
      PointRadioToArduino(slaveOnePipe, state);
  }
  else if (slavenum == 0x02) {
       PointRadioToArduino(slaveTwoPipe, state);
  }
  else {
    Serial.println("Another Value Received, breaking");
    return;
  }
}

void PointRadioToArduino(const uint64_t addy, const byte state){
    radio.openWritingPipe(addy); // Get NRF24L01 ready to transmit
    if (state == 32) { // 32 on bit
      SentMessage[0] = 111;
      radio.write(SentMessage, 1); // Send value through NRF24L01
    }
    else if (state == 33) { // 33 off bit
      SentMessage[0] = 000;
      radio.write(SentMessage, 1);
    } else {
      Serial.println("Something else was passed in for setState byte");
      return;
    }
}


void SerialPrintReceivedData() {
  for (int i = 1; i < 3; i++) {
    Serial.print("Value(");
    Serial.print(i);
    Serial.print("): ");
    Serial.println(dataArray[i]);
  }
}

// Handle request to send I2C data
void sendData() {
  Wire.write(i2cData);
}
