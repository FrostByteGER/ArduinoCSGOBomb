#include <RCSwitch.h>

int dataPin = 2;

RCSwitch mySwitch = RCSwitch();

int testPin = 12;

void setup() {

  //pinMode(dataPin,OUTPUT);
  //pinMode(VCCPin,OUTPUT);

  pinMode(testPin,OUTPUT);
  
  mySwitch.enableTransmit(dataPin);
}

void loop() {

  digitalWrite(testPin, HIGH);

  mySwitch.send(1234, 24);
  delay(975);

  digitalWrite(testPin, LOW);
  delay(25);
  
}
