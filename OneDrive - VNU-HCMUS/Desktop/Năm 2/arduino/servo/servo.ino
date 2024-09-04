#include<Servo.h>
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  pinMode(A1,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potentiometer_value = analogRead(A1);
  int servo_value = map(potentiometer_value,0,1023,0,180);
  myservo.write(servo_value);
}
