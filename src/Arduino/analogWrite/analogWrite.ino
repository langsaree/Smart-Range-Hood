int led = 11;
void setup(){
  pinMode(led, OUTPUT);
}
void loop(){
analogWrite (led,255);
delay(500);
analogWrite (led,127);
delay(500);
analogWrite (led,0);
delay(500);
}
