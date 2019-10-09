int sw = 10;
int led = 12;
void setup() {
  Serial.begin(9600);
  pinMode(sw, INPUT);
  pinMode(led, OUTPUT);

}

void loop() {
 int val = digitalRead(sw);
 if(val == 0){
  digitalWrite(led,1);
 }else{
  digitalWrite(led,0);
 }
 delay(500);
}
