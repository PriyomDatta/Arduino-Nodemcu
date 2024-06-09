#define onboardLED 2 //D4 on board
void setup() {
  // put your setup code here, to run once:
pinMode(onboardLED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(onboardLED,HIGH);
delay(3000);
digitalWrite(onboardLED,LOW);
delay(3000);
}
