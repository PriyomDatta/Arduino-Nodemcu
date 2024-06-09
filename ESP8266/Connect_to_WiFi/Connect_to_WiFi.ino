/*
Author:-priyom Datta
Date:-06/02/24
Note:- Select generic ESP8266 Module
*/
#include<ESP8266WiFi.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin("Priyom's WiFi","Priyom123");
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print("..");
    delay(500);
  }
  Serial.println("");
  Serial.println("NodeMCU is connected");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
}
