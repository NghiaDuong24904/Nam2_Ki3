// C++ code
//
int Green = 2;
int Yellow = 3;
int Red = 4;
void setup()
{
  pinMode(Green, OUTPUT);
  pinMode(Yellow, OUTPUT);  
  pinMode(Red, OUTPUT);
}

void loop()
{
  digitalWrite(Green, HIGH);
  delay(10000); // Wait for 3000 millisecond(s)
  digitalWrite(Green, LOW);
  
  digitalWrite(Yellow, HIGH);
  delay(7000); // Wait for 3000 millisecond(s)
  digitalWrite(Yellow, LOW);
    
  digitalWrite(Red, HIGH);
  delay(3000); // Wait for 3000 millisecond(s)
  digitalWrite(Red, LOW);
}