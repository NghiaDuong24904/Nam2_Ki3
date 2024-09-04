int trig = 2;
int echo = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(11,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}
// TRANSMITTER
// RECEIVER
// 340 m/s -> 0.034 cm/micros
long getDistance(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  long duration = pulseIn(echo,HIGH);

  long distanceCm = duration * 0.034 / 2;

  return distanceCm;
}
void loop() {
  // put your main code here, to run repeatedly:
  int distanceCm = getDistance();
  int value = map(distanceCm,0,20,0,200);
  if(distanceCm < 20){
    digitalWrite(11,HIGH);
    delay(value);
    digitalWrite(11,LOW);
    delay(value);
  }
  Serial.println(distanceCm);
}
