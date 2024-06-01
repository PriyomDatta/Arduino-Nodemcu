#define onboardLED 2//D4 on board
#define Switch 0 //D3 on board
void setup() {
  // put your setup code here, to run once:
pinMode(onboardLED,OUTPUT);
pinMode(Switch,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

bool i = digitalRead(Switch);
if(0 != i)
  digitalWrite(onboardLED,LOW);
else
  digitalWrite(onboardLED,HIGH);
}
