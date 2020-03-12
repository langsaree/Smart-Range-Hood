#include <TridentTD_LineNotify.h>
#include <MQ2.h>

#define SSID        "Nafah kt"
#define PASSWORD    "00001111"
#define LINE_TOKEN  "SLtwiBg66sYDVUZKoUcckPpwkIxfg9HERx0jog5RV6X"

int led = 26;
int pir = 14;

int fan = 13;
int smokeA0 = 36;
int buzzer = 12;

void setup() {
  Serial.begin(115200); Serial.println();
  Serial.println(LINE.getVersion());
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(400);
  }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());
  LINE.setToken(LINE_TOKEN);

  pinMode(led, OUTPUT);
  pinMode(pir, INPUT);

  pinMode(fan, OUTPUT);
  pinMode(smokeA0, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  
  //////////////   Motion   //////////////////

  int sensorval = digitalRead(pir);
// Serial.println("PIR STATE :");

  if (sensorval == HIGH) {
    digitalWrite(led, LOW);
    Serial.println("Motion Detected");
    delay(10000);
  }
  
  else {
    digitalWrite(led, HIGH);
    Serial.println("Can't Detected human movement .. Please!! try again");
  }


  int analogSensor = analogRead(smokeA0);
  smoke(analogSensor);
  Serial.println(analogSensor);
}


void smoke(int value) {

  //////////////   smoke   //////////////////
  if (value > 300 && value < 1000) {
    Serial.println("Smoke Detected");
    digitalWrite(fan, HIGH);

  } else {
    Serial.println("Haven't Smoke ..!! Try to deetect again");
    digitalWrite(fan, LOW);

  }


  //////////////   gas   //////////////////
  if (value > 1200) {
    Serial.println("Gas Leakage");
    digitalWrite(buzzer , HIGH);
    LINE.notify("we has Detected Gas !!! Please check out");

  } else {
    Serial.println("Haven't Gas");
    digitalWrite(buzzer , LOW);

  }
  delay(500);
}
