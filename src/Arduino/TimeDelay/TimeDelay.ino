unsigned long a = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), rst_timer, FALLING);
}

void rst_timer() {
  a = millis();
  Serial.println(a);
}

void loop() {
  if (millis() - a >= 5000) {
    Serial.println("Hello");
    a = millis();
    Serial.println(millis());
  }
}
