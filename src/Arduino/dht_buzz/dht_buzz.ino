#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <DHT.h>;

#define DHTPIN 5
#define Led 7  //ขา led
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

float temp;
float set_temp;
int buzzer = 8;

void setup()
{
dht.begin();
Serial.begin(9600);
pinMode(buzzer, OUTPUT);
 pinMode(Led, OUTPUT);
set_temp = 35;
}

void loop(){

temp = dht.readTemperature();

if (temp >= set_temp) {

Serial.print("TEMP: = " + String(temp) + " C\n");
Serial.print("SET : = " + String(set_temp) + " C\n\n");
buzzer_on();
}

else {
Serial.print("TEMP: = " + String(temp) + " C\n");
Serial.print("SET : = " + String(set_temp) + " C\n\n");
}
delay(1);
}

void buzzer_on()

{ unsigned char i, j;
{ for (i = 0; i < 80; i++)
{ digitalWrite(buzzer, HIGH);
digitalWrite(Led, HIGH);
delay(1);//delay1ms

digitalWrite(buzzer, LOW);
digitalWrite(Led, HIGH);
delay(1);//ms delay
}

for (i = 0; i < 100; i++)
{
digitalWrite(buzzer, HIGH);
digitalWrite(buzzer, LOW);
digitalWrite(Led, HIGH);
digitalWrite(Led, LOW);

delay(2);
}
}
}
