int ledPin = 13;
int pirPin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
}

void loop() {
  int value = digitalRead(pirPin);


  if (value == HIGH)
  {
    digitalWrite(ledPin, HIGH);
    Serial.println("Detected human movement");
    delay(1000);
  }

  else
  {
    digitalWrite(ledPin, LOW);
    Serial.println("Do not detected human movement .. Try to detected again !!!!! ");
  }
}
