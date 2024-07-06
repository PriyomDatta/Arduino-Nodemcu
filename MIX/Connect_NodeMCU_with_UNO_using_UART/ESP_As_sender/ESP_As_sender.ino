#include<ESP8266WiFi.h>

const int button = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button,INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(button)== LOW)
{
  Serial.write(0x11);
  //Serial.println("LOW");
  delay(1000);
}
else
{
  Serial.write(0x12);
  //9Serial.println("High");
  delay(1000);
}
}
