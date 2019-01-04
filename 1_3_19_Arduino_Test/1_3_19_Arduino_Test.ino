const int GPIO_PIN_1 = 2;
const int GPIO_PIN_2 = 3;
const int GPIO_PIN_3 = 4;
const int GPIO_PIN_4 = 5;

const int LED_PIN_1 = 6;
const int LED_PIN_2 = 7;
const int LED_PIN_3 = 8;
const int LED_PIN_4 = 9;

const int SERVO_PIN = 11;

#include <Servo.h>
Servo lock;
void setup() {
  pinMode(GPIO_PIN_1, INPUT);
  pinMode(GPIO_PIN_2, INPUT);
  pinMode(GPIO_PIN_3, INPUT);
  pinMode(GPIO_PIN_4, INPUT);

  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(LED_PIN_4, OUTPUT);

  digitalWrite(LED_PIN_1, LOW);
  digitalWrite(LED_PIN_2, LOW);
  digitalWrite(LED_PIN_3, LOW);
  digitalWrite(LED_PIN_4, LOW);
  
  lock.attach(11);
  lock.write(140);

}

void loop() {
  test_GPIO();

}

void test_GPIO(){
  if(digitalRead(GPIO_PIN_1) == HIGH){
    digitalWrite(LED_PIN_1, HIGH);
    latch(); 
  }else{
    digitalWrite(LED_PIN_1, LOW);
  }
  if(digitalRead(GPIO_PIN_2) == HIGH){
    digitalWrite(LED_PIN_2, HIGH); 
    latch();
  }else{
    digitalWrite(LED_PIN_2, LOW);
  }
  if(digitalRead(GPIO_PIN_3) == HIGH){
    digitalWrite(LED_PIN_3, HIGH); 
    latch();
  }else{
    digitalWrite(LED_PIN_3, LOW);
  }
  if(digitalRead(GPIO_PIN_4) == HIGH){
    digitalWrite(LED_PIN_4, HIGH);
    latch(); 
  }else{
    digitalWrite(LED_PIN_4, LOW);
  }
  
}

void latch(){
  lock.write(50);
  delay(3000);
  lock.write(140);
}
