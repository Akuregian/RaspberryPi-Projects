#include "nRF24L01.h" 
#include "RF24.h"
#include "SPI.h"



int ReceivedMessage[1] = {000}; // Used to store value received by the NRF24L01

RF24 radio(9, 10); // NRF24L01 used SPI pins + Pin 9 and 10 on the UNO

const uint64_t pipe = 0xE5E5E5E5E5E5; // Needs to be the same for communicating between 2 NRF24L01


void setup(void) {

  Serial.begin(9600);
  Serial.println("Radio Begin");
  radio.begin(); // Start the NRF24L01

  radio.openReadingPipe(1, pipe); // Get NRF24L01 ready to receive

  radio.startListening(); // Listen to see if information received

  pinMode(2, OUTPUT);

}

void loop(void) {

  while (radio.available())
  {
    radio.read(ReceivedMessage, 1); // Read information from the NRF24L01

    if (ReceivedMessage[0] == 111) // Indicates switch is pressed
    {
      Serial.println("Light Turned On: ");
      Serial.println(ReceivedMessage[0]);
      
      digitalWrite(2, HIGH);
    }
    else if(ReceivedMessage[0] == 000)
    {
      Serial.println("Light Turned Off: ");
      Serial.println(ReceivedMessage[0]);
      digitalWrite(2, LOW);

    }
    delay(1000);
  }
}
