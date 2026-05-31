const int sensorPin = A0;
const int ledPin = 3;
const int buzzerPin = 4;
const int relayPin = 5;
const int threshold = 400;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  digitalWrite(relayPin, HIGH);
  Serial.begin(9600);
}
void loop() {
  int gasValue = analogRead(sensorPin);
  Serial.println(gasValue);
  if (gasValue > threshold) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);
    digitalWrite(relayPin, LOW);
  } else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
    digitalWrite(relayPin, HIGH);
  }
  delay(200);
}
