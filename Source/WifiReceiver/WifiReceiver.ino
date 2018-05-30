#include <VirtualWire.h>

int receivePin = 3;
int bitsPerSecond = 2000;
int value = 0;

void setup() {
  Serial.begin(9600);
  vw_setup(bitsPerSecond);    
  vw_set_rx_pin(receivePin); 
  vw_rx_start();
  }

void loop() 
{
  uint8_t buf[VW_MAX_MESSAGE_LEN]; // Raw Message Data
  uint8_t buflen = VW_MAX_MESSAGE_LEN; // Message Data Length

  char receivedData[VW_MAX_MESSAGE_LEN+1]; // Converted Message Data(Make it readable as raw data is made of integers!)

  // Check for new Message
  if(vw_get_message(buf, &buflen))
  {
    Serial.println("Received Message!");
    memset(receivedData, 0, VW_MAX_MESSAGE_LEN+1); // Set all values to zero.

    // Convert raw data from integers to chars.
    for (int i = 0; i < buflen; i++) 
    {
      receivedData[i] = (char)buf[i];
    } 

    // Add Null Terminator as transmitted data doesn't have one.
    receivedData[VW_MAX_MESSAGE_LEN+1] = '\0';
    // Debug print the Message
    Serial.println(receivedData);

    
  }
}
