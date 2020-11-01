//////////////////////////////////////////////////////////////////////////// 
//               Pumpkin Radio Transmitter (Part 2 - Emisor)              //
// This code was made during the "Hack or Treat?" Hackaton hosted by MLH. //
// Here you will find all the digital structure we made for our hardware. //
// Team: Citlali Capiz, Cristian Aguíñiga and Fernando Guerrero.          //
////////////////////////////////////////////////////////////////////////////

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Pin Declaration
#define CE_PIN 10
#define CSN_PIN 11

// Channel
byte channel[5] ={'a','b','c','d','e'}; 

// Object Radio
RF24 radio(CE_PIN, CSN_PIN);

// Number of data received
bool data[1];

bool lect1, lect2;
int onoff = 3;

void setup() {

  // Start radio transmitter module 
  radio.begin();
  // Start serial module
  Serial.begin(9600); 
  // Searching channel
  radio.openWritingPipe(channel);

  pinMode(onoff, INPUT);
  pinMode(5, OUTPUT);
  
}

void loop() {
  
  lect1 = digitalRead(onoff);
  // Loading data
  data[0] = false;
  // Sending data
  bool correct = radio.write(data, sizeof(data));
  if(lect1!=lect2){
    bool correct = false;
  }
  if(correct){
    digitalWrite(5, LOW);
    Serial.print("Data send: "); 
    Serial.println(data[0]); 
    }else{
    digitalWrite(5, HIGH); 
    Serial.println("Data couldn't be send.");
  }
  lect2 = lect1;
  delay(1000);
  
}
