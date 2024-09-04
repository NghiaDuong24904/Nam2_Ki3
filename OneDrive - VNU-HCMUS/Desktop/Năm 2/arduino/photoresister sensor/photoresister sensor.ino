int light_pin = 7;
int trig = 2;
int echo = 3;
void setup() {
  // put your setup code here, to run once:
  pinMode(light_pin, INPUT);
  pinMode(11, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}
long getDistance() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);

  long distanceCm = duration * 0.034 / 2;

  return distanceCm;
}
void loop() {
  // put your main code here, to run repeatedly:
  int distanceCm = getDistance();
  int value = digitalRead(light_pin);
  if (value == 1) {
    if (distanceCm < 20) {
      digitalWrite(11, HIGH);
      delay(500);
      digitalWrite(11, LOW);
      delay(500);
    } else {
      digitalWrite(11, HIGH);
    }
  } else {
    digitalWrite(11, LOW);
  }
  delay(100);
}
