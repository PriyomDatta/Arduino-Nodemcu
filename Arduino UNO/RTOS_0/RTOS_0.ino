#include <Arduino_FreeRTOS.h>

#define YellowLED 2
#define BlueLED 9

void Task1(void *pvParameter);
void Task2(void *pvParameter);

void setup() {
  // put your setup code here, to run once:
  pinMode(YellowLED,OUTPUT); 
  pinMode(BlueLED,OUTPUT); 
  xTaskCreate(task1,"task1",128,NULL,1,NULL);
  xTaskCreate(task2,"task2",128,NULL,2,NULL);  
  vTaskStartScheduler();
}

void loop() {
  // put your main code here, to run repeatedly:
//digitalWrite(BlueLED,1);
}

void task1(void *pvParameters)  
{
  static char status1 = 0;
  while(1) {
    digitalWrite(BlueLED,status1);
    status1 = !status1;
    vTaskDelay( 500 / portTICK_PERIOD_MS ); 
  }
}

void task2(void *pvParameters)  
{
  static char status2 = 0;
  while(1) {
    digitalWrite(YellowLED,status2);
    status2 = !status2;
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); 
  }
}
