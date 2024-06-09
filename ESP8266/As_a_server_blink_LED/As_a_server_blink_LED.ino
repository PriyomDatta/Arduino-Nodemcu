/*
Author:-priyom Datta
Date:-06/02/24
Note:- Select generic ESP8266 Module
*/
#include<ESP8266WiFi.h>

#define OnboardLED 2  //On board LED is connected to D4 pin
WiFiClient Client;
WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                         /*Start serial communication*/
  WiFi.mode(WIFI_STA);
  WiFi.begin("Priyom's phone","Priyom123");
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print("..");
    delay(500);
  }
  Serial.println("");
  Serial.println("NodeMCU is connected");
  Serial.println(WiFi.localIP());
  server.begin();

  pinMode(OnboardLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Client = server.available();
  if(Client == 1)
  {
    String request = Client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if(request == "GET /ledon HTTP/1.1")
    {
      digitalWrite(OnboardLED, LOW);  //Something Fissy
    }
    
    if(request == "GET /ledoff HTTP/1.1")
    {
      digitalWrite(OnboardLED, HIGH);    //Something Fissy
    }
  }
}
