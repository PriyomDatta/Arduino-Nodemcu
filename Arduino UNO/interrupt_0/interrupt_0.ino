//Example of HW Interrupt
#include"Arduino.h"
//LED and switch connections
const uint8_t ledpin = 13;
const uint8_t buttonpin = 2;

volatile uint8_t togglestate = false;

void checkswitch()
{
  if(LOW == digitalRead(buttonpin))
  {
    //delay(200);
    togglestate = !togglestate;
    digitalWrite(ledpin,togglestate);
  }
}
void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin,OUTPUT);
  pinMode(buttonpin,INPUT_PULLUP);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(buttonpin),checkswitch,FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  //checkswitch();
  Serial.println("delay started");
  delay(5000);
  Serial.println("Delay Finished");
  Serial.println(".........");
}
