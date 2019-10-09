
int buzzPin=8;

int frequency=1000; //Specified in Hz 
int timeOn=1000; //specified in milliseconds
int timeOff=1000; //specified in millisecods

void setup(){
  Serial.begin(9600); 
}
void loop(){

tone(buzzPin, frequency);
delay(timeOn);
noTone(buzzPin);
delay(timeOff);

}
