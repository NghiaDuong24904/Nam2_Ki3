int light_pin = A0;
#include <Servo.h>
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(light_pin, INPUT);
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(light_pin);
  if (value > 360) {
    myservo.write(180);
  }
  else{
    myservo.write(100);
  }
}
