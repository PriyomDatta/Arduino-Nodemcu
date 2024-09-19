//Example of Pin Change Interrupt

#include"Arduino.h"
//LED and switch connections
const uint8_t ledpin = 13;
const uint8_t buttonpin = 7;  //Pin 7 PORTD

volatile uint8_t togglestate = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin,OUTPUT);
  pinMode(buttonpin,INPUT_PULLUP);
  //Enable PCIE2  Bit2 =1
  PCICR |= B00000100;

  //Select PCINT23 Bit7 = 1 D7
  PCMSK2|=B10000000;
}


void loop() {
  // put your main code here, to run repeatedly:
}

ISR(PCINT2_vect){
  togglestate = !togglestate;
  digitalWrite(ledpin,togglestate);
}