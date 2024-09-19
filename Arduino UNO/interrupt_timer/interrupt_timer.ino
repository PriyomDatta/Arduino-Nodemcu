
#define ledpin 13

int timer1_compare_match;

ISR(TIMER1_COMPA_vect)
{
  TCNT1 = timer1_compare_match;

  digitalWrite(ledpin,digitalRead(ledpin)^1);
}
void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin,OUTPUT);
  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  timer1_compare_match = 31249;
  TCNT1 = timer1_compare_match;
  TCCR1B |= (1<<0x02);
  TIMSK1 |= (1<<0x01);

  interrupts();

}

void loop() {
  // put your main code here, to run repeatedly:

}
