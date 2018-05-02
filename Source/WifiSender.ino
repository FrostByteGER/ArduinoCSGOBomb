#include <VirtualWire.h>

int dataPin = 2;

int testPin = 12;

char* message = "ON";

void setup() {

  Serial.begin(9600);
  //pinMode(dataPin,OUTPUT);
  //pinMode(VCCPin,OUTPUT);
  vw_set_ptt_inverted(true);
  vw_setup(2000);
  vw_set_tx_pin(dataPin);

  pinMode(testPin,OUTPUT);
}

void loop() {

  digitalWrite(testPin, HIGH);

  vw_send((uint8_t *)message, strlen(message)); // Message an Empfänger senden
  vw_wait_tx();                                 // Auf den Abschluss der Übertragung warten
  Serial.println("Code sent!");

  digitalWrite(testPin, LOW);
  
}
