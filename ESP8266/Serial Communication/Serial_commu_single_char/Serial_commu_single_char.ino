void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0)
  {
    char var[4];
    memset(var,'\0',4);
    Serial.readBytes(var, 3);
    Serial.printf("\n%x\t%d\t%c\n",var[2],var[2],var[2]);
    Serial.printf("%s\n",var);
  }
  delay(500);
}
