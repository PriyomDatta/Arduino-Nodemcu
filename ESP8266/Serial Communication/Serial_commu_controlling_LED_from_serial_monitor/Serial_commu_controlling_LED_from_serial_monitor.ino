/*As the ON board LED switches in reverse order*/
#define LEDON LOW;
#define LEDOFF HIGH;

int LED = 2;
int state = LEDOFF;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  while(Serial.available()==0){  }

  String str = Serial.readString();   /*Reads string fron serial monitor*/
  str.trim();                         /*Trim the string*/
  
  /*If on/off is received from serial monitor switches LED accoerdingly*/
  if(str == "on")
    {state = LEDON;}
  else if(str == "off")
    {state = LEDOFF;}
  else
   Serial.println(str);

  digitalWrite(LED,state);
  delay(500);
}
