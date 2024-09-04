#define echoPin 2
#define trigPin 3

#define Led1 8
#define Led2 9
#define Led3 10
#define Led4 11
#define Led5 12

long duration;
int distance; 

long getDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; 
  return distance;
}

void setup() 
{
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);
  pinMode(Led5, OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
}
void loop() 
{
  int distanceCM = getDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
    
  if(distanceCM <= 50)
  {
    digitalWrite(Led1, HIGH);
    digitalWrite(Led2, HIGH);
    digitalWrite(Led3, HIGH);
    digitalWrite(Led4, HIGH);
    digitalWrite(Led5, HIGH);
    delay(100);
  }
  else if(distanceCM > 50 && distanceCM <= 100)
  {
    digitalWrite(Led1, HIGH);
    digitalWrite(Led2, HIGH);
    digitalWrite(Led3, HIGH);
    digitalWrite(Led4, HIGH);
    digitalWrite(Led5, LOW);
    delay(100);
  }
    else if(distanceCM > 100 && distanceCM <= 150)
  {
    digitalWrite(Led1, HIGH);
    digitalWrite(Led2, HIGH);
    digitalWrite(Led3, HIGH);
    digitalWrite(Led4, LOW);
    digitalWrite(Led5, LOW);
    delay(100);
  }
    else if(distanceCM > 150 && distanceCM <= 200)
  {
    digitalWrite(Led1, HIGH);
    digitalWrite(Led2, HIGH);
    digitalWrite(Led3, LOW);
    digitalWrite(Led4, LOW);
    digitalWrite(Led5, LOW);
    delay(100);
  }
    else if(distanceCM > 200)
  {
    digitalWrite(Led1, HIGH);
    digitalWrite(Led2, LOW);
    digitalWrite(Led3, LOW);
    digitalWrite(Led4, LOW);
    digitalWrite(Led5, LOW);
    delay(100);
  }
}
