#include<TinyGPSPlus.h>
#include<SoftwareSerial.h>

int RxPin = 2;
int TxPin = 3;

TinyGPSPlus gps;


SoftwareSerial gpsSerial(RxPin,TxPin);

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
}

void disp(){
  if(gps.location.isValid()){
    Serial.print("Latitude: ");
    Serial.println(gps.location.lat());
    Serial.print("Longitude: ");
    Serial.println(gps.location.lng());
    Serial.print("Altitude: ");
    Serial.println(gps.altitude.meters());
  }
  else{
    Serial.println("No valid location");
  }

  if(gps.time.isValid()){
    Serial.print("time: ");
    Serial.print(gps.time.hour());
    Serial.print(":");
    Serial.print(gps.time.minute());
    Serial.print(":");
    Serial.print(gps.time.second());
  }
  else{
    Serial.println("No valid time");
  }
}

void loop(){
  //Serial.print("val");
  while(gpsSerial.available()>0)
    if(gps.encode(gpsSerial.read()))
    {Serial.println("GPS detected\n");
    disp();}

  if(millis()>5000 && gps.charsProcessed()<10){
    Serial.println("no GPS detected");
  }
  //delay(1000);
}