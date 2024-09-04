// C++ code
//
int Photoregistor = A0;
int Led = 3;
int val;
void setup()
{
  pinMode(Photoregistor, INPUT);
  pinMode(Led, OUTPUT);
}

void loop()
{
  val = analogRead(Photoregistor);
  if(val < 800)
  {
  	digitalWrite(Led, HIGH);
  }
  else
  {
    digitalWrite(Led, LOW);
  }

}