
// Led Pin
int ledPin = 13;

// set Pin 0-3 to Input and Pin 4-6 to Output
int inputPin[] = {INPUT,INPUT,INPUT,INPUT,OUTPUT,OUTPUT,OUTPUT};

// set Pin 0-12 to Output
int outputPins = 12;

// set Numbers
int dig[] = {0,0,0,0};

// GameModes
int mode = 0;
int modeNone = 0;
int modeSet = 1;
int modedef = 2;

void setup(){
  setPins(0, 13, OUTPUT);
}

void loop(){
  
}


int input(){
 // activate input
 
 for(int i = 0 ; i < sizeof(inputPin) ; i++){
   pinMode(i ,inputPin[i]);
 }
 
 digitalWrite();
 
}

void output(){
  
  setPins(0, outputPins);
  
  //digitalWrite(LOW);
  //digitalWrite(HIGH);
  
}

void setPins(int from, int to, int mode){
  for(int i = from ; i < to ; i++){
    pinMode(i, mode);
  }
}
