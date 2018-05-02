#include <VirtualWire.h>

int dataPin = 3;


int testPin = 12;

int value = 0;

void setup() {
  Serial.begin(9600);
  vw_setup(2000);    
  vw_set_rx_pin(dataPin); 
  vw_rx_start();
  
  pinMode(testPin, OUTPUT);
}

void loop() 
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  char receivedData[VW_MAX_MESSAGE_LEN+1]; 

  // Checke auf neue Nachricht
  if(vw_get_message(buf, &buflen))
  {
    Serial.println("Received Message!");
    memset(receivedData, 0, VW_MAX_MESSAGE_LEN+1);
    for (int i = 0; i < buflen; i++) 
    {
      receivedData[i] = (char)buf[i];
    } 

    receivedData[VW_MAX_MESSAGE_LEN+1] = '\0';
    Serial.println(receivedData);

    
  }
}
