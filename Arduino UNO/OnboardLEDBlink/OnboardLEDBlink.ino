#define onBoardLED 13

void setup() {
  // put your setup code here, to run once:
pinMode(onBoardLED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(onBoardLED,HIGH);
delay(2000);
digitalWrite(onBoardLED,LOW);
delay(2000);
}
