void setup() {
  // put your setup code here, to run once:
  for (int pin = 2; pin <= 8; pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int n0[10][8] = {
    { 1, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 1, 0, 0, 0, 0 },
    { 1, 1, 0, 1, 1, 0, 1 },
    { 1, 1, 1, 1, 0, 0, 1 },
    { 0, 1, 1, 0, 0, 1, 1 },
    { 1, 0, 1, 1, 0, 1, 1 },
    { 1, 0, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 0, 1, 1 }
  };
  for (int i = 0; i < 10; i++) {
    for (int pin = 2; pin <= 8; pin++) {
      digitalWrite(pin, n0[i][pin - 2]);
    }
    delay(300);
  }
}
