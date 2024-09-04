#define PIR_PIN 7
#define LED_PIN 13

// Thời gian debounce
const int debounceTime = 50;  // milliseconds
// Ngưỡng phát hiện
const int motionThreshold = 5;  // số lần đọc liên tiếp

bool motionDetected = false;
int motionCount = 0;
unsigned long lastDebounceTime = 0;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(PIR_PIN);
  
  // Xử lý debounce
  if (sensorValue == HIGH) {
    if (millis() - lastDebounceTime > debounceTime) {
      motionCount++;
      lastDebounceTime = millis();
    }
  } else {
    motionCount = 0;
  }
  
  if (motionCount >= motionThreshold) {
    if (!motionDetected) {
      motionDetected = true;
      Serial.println("Motion detected!");
      digitalWrite(LED_PIN, HIGH);
    }
  } else {
    if (motionDetected) {
      motionDetected = false;
      Serial.println("No motion.");
      digitalWrite(LED_PIN, LOW);
    }
  }
}