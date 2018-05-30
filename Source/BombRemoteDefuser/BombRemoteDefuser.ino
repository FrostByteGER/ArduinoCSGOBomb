#include <VirtualWire.h>

int sendPin = 2;
int bitsPerSecond = 2000;

char* message = "Y";

void setup() {

  //Debug Print
  Serial.begin(9600);
  vw_setup(bitsPerSecond);
  vw_set_tx_pin(sendPin);
}

void loop() {

  //TODO: Check Button State here
  
  vw_send((uint8_t *)message, strlen(message)); // Send message
  vw_wait_tx();                                 // Wait for transmit, ITS OPTIONAL!
  Serial.println("Code sent!");
  
}
