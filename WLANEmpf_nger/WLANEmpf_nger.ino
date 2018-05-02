#include <RCSwitch.h>

int dataPin = 3;

RCSwitch mySwitch = RCSwitch();

int testPin = 12;

int value = 0;

void setup() {

  mySwitch.enableReceive(dataPin);
}

void loop() {
  
  if (mySwitch.available())
  {
    value = mySwitch.getReceivedValue();
    
    digitalWrite(testPin, LOW);
    delay(100);
    digitalWrite(testPin, HIGH);
    delay(100);

    if (value == 0) // Wenn die Empfangenen Daten "0" sind, wird "Unbekannter Code" angezeigt.
    {

    }else if(value == 1234){

    }
    mySwitch.resetAvailable();
  }

  

}
