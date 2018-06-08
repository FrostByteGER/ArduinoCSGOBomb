#include <Time.h>

// debug
int timer = 0;
int selectNumber = 63;

// NumPad (uses pin 12 to 19, 12-15 Out, 16-19 In)
//may change 
int inZero = 1024;
int inOne = 1;
int inTwo = 2;
int inThree = 4;
int inFoure = 8;
int inFive = 16;
int inSix = 32;
int inSeven = 64;
int inEight = 128;
int inNine = 256;
int inStar = 512;
int inCross = 2048;

int inputAmount = 0; // used to count the amount of inputs only works with rows (multiple columns will return no input)
int inputNumber = 0; // all inputs
int inputNumberLast = 0; // is needed to deteced a click of on Button. (press and release)

int tempInput = 0; // input from SlavePin
int tempCount = 0; // used to collect all inputs (from inputNumber)

int debugMaster = 0; // curent Master Pin
int debugSlave = 0; // curent Slave Pin


// 7 Segment (uses pin 0 to 11 ,0-7 Master ,8-11 Slave)
// this "Numbers" get displayed
int displayNum[] = {6,91,79,255};

// index zu tile
//   -1-
// 6|   |2
//   -7-
// 5|   |3
//   -4-
//      p8
int seg[] = {1,2,4,8,16,32,64,128,256}; // segment zuordnung

// Segment Numbers Preset
// Number to index (not filled yet)
// plus 128 for point
int numbers[] = {63,6,91,79,102,109,125,7,127,111}; 

// Master Pins
int masterPins[] = {12, 13, 14, 15};

// Slave Pins
int slavePins[] = {16, 17, 18};

// over Symbols
int lineMid = 64; // -
int lineTop = 1;
int lineBot = 8;
int simA = 119;
int simH = 118;

// Beper Pin

int bepPin = 19;

// Game Values

double bombTotalTime = 60000; // 1min
double bombTimer = 60000; // 1min

double bepTemp = 0;
double bepTimer = 1000; // beps per sec in relation to the bombTimer (bombTimer / bepTimer) = sec

bool bepMode = false;
 
// Mode
int mode = 1;

int inputMode = 1; // Player inputs Numbers
int defNorm = 2; // Player trys to defuse the Bomb with the num Pad
int defDefuser = 3; // Player trys to defuse the Bomb with the Defuser

int selectedNumber = 0; 
int selectedNumbers[] = {-1, -1, -1, -1};

// Timer
int timeStemp = 0; // Used for Timers
int timeTemp = 0;


// segNumber see "seg"
// deg 1,2,3,4
void showNumber(int segNumber, int deg){
  if(deg < 0 or deg > 3){
    return;
  }
  for(int i = 0; i < 8; i++){
    digitalWrite(i, LOW);
  }
  
  for(int i = 8; i < 12 ;i++){
    digitalWrite(i, HIGH);
  }
  
  for(int i = 0; i < 8; i++){
    if((segNumber & seg[i]) > 0){
      digitalWrite(i, HIGH);
    }else{
      digitalWrite(i, LOW);
    }
  }

  digitalWrite(deg+8, LOW);
  //delay(10);
}

// is called if a Butten is pressed and released
void clicked(int inputClick){

  // change Selected Segment
  if(inputClick & inStar){
    displayNum[selectedNumber] = displayNum[selectedNumber]&(!128);
    selectedNumber = (selectedNumber+3)%4;
    displayNum[selectedNumber] = displayNum[selectedNumber]|128;
  }else if(inputClick & inCross){
    displayNum[selectedNumber] = displayNum[selectedNumber]&(!128);
    selectedNumber = (selectedNumber+1)%4;
    displayNum[selectedNumber] = displayNum[selectedNumber]|128;
  }
  
  if(mode == inputMode){

    // change to defusemode
    if(inputClick & inStar && inputClick & inCross){
      mode = defNorm;
      
      for(int i=0; i < 4; i++){
        selectedNumbers[i] = displayNum[i] & (!128);
        displayNum[i] = lineMid | (displayNum[i] & 128);
      }
      return;
    }

    // change Number of selected Number
    if(inputClick & inZero){
      displayNum[selectedNumber] = numbers[0]+128;
    }else if(inputClick & inOne){
      displayNum[selectedNumber] = numbers[1]+128;
    }else if(inputClick & inTwo){
      displayNum[selectedNumber] = numbers[2]+128;
    }else if(inputClick & inThree) {
      displayNum[selectedNumber] = numbers[3]+128;
    }else if(inputClick & inFoure) {
      displayNum[selectedNumber] = numbers[4]+128;
    }else if(inputClick & inFive) {
      displayNum[selectedNumber] = numbers[5]+128;
    }else if(inputClick & inSix) {
      displayNum[selectedNumber] = numbers[6]+128;
    }else if(inputClick & inSeven) {
      displayNum[selectedNumber] = numbers[7]+128;
    }else if(inputClick & inEight) {
      displayNum[selectedNumber] = numbers[8]+128;
    }else if(inputClick & inNine) {
      displayNum[selectedNumber] = numbers[9]+128;
    }
  }else if(mode == defNorm){
    if(inputClick == inStar || inputClick == inCross){
      
    }else if(displayNum[selectedNumber]&(!128) != lineMid && false){
      
    }else if(inputNumToDisplayNum(inputClick) == selectedNumbers[selectedNumber] || true){
      displayNum[selectedNumber] = numbers[0];//selectedNumbers[selectedNumber] | 128;
    }else if(inputNumToDisplayNum(inputClick) != selectedNumbers[selectedNumber]){
      for(int i=0; i < 4; i++){
        selectedNumbers[i] = displayNum[i] & (!128);
        displayNum[i] = lineMid | (displayNum[i] & 128);
      }
    }
  }
  
  // exampel
  if((inputClick == (inOne | inTwo)) >= 1 && false){
    displayNum[2] = numbers[3];
  }
}

void tick(int delta){

  if(mode == defNorm || mode == defDefuser){

    bombTimer -= delta;
    bepTemp -= delta;
    
    if(bombTimer <= 0){
      //TODO Lose
      mode = inputMode; // change Mode
      digitalWrite(bepPin,LOW); // turn bep of
      turnBepOff();
    }
    
    if(bepMode){
      turnBepOff();
    }
    
    if(bepTemp < 0){  
      trunBepOn();      
      bepTemp = (bombTimer/ bombTotalTime) * bepTimer;
    }
  } 
}

void turnBepOff(){
  digitalWrite(bepPin,LOW);
  bepMode = false;
}

void trunBepOn(){
  digitalWrite(bepPin,HIGH);
  bepMode = true;
}

int inputNumToDisplayNum(int inputNum){
  return inputNumToDisplayNum(inputNum, false);
}

int inputNumToDisplayNum(int inputNum, bool point){

  int addPoint = 0;

  if(point){
    addPoint = 128;
  }
  
  if(inputNum == inZero){
    return numbers[0]|addPoint;
  }else if(inputNum == inOne){
    return numbers[1]|addPoint;
  }else if(inputNum == inTwo){
    return numbers[2]|addPoint;
  }else if(inputNum == inThree) {
    return numbers[3]|addPoint;
  }else if(inputNum == inFoure) {
    return numbers[4]|addPoint;
  }else if(inputNum == inFive) {
    return numbers[5]|addPoint;
  }else if(inputNum == inSix) {
    return numbers[6]|addPoint;
  }else if(inputNum == inSeven) {
    return numbers[7]|addPoint;
  }else if(inputNum == inEight) {
    return numbers[8]|addPoint;
  }else if(inputNum == inNine) {
    return numbers[9]|addPoint;
  }
}

int displayNumToInputNum(int displayNum){

  if(displayNum == numbers[0]){
    return inZero;
  }else if(displayNum == numbers[1]){
    return inOne;
  }else if(displayNum == numbers[2]){
    return inTwo;
  }else if(displayNum == numbers[3]) {
    return inThree;
  }else if(displayNum == numbers[4]) {
    return inFoure;
  }else if(displayNum == numbers[5]) {
    return inFive;
  }else if(displayNum == numbers[6]) {
    return inSix;
  }else if(displayNum == numbers[7]) {
    return inSeven;
  }else if(displayNum == numbers[8]) {
    return inEight;
  }else if(displayNum == numbers[9]) {
    return inNine;
  }
  
  return 0;
}

void setup() {

  // 7 Segment
  for(int i = 0; i < 12; i++){
      pinMode(i,OUTPUT);
  }

  // Numpad 12
  for(int i = 0; i < 4; i++){
      pinMode(masterPins[i],OUTPUT);
      digitalWrite(masterPins[i],HIGH);
  }

  for(int i = 0; i < 3; i++){
      pinMode(slavePins[i],INPUT_PULLUP);
  }

  pinMode(bepPin,OUTPUT);

  //debug
}

void loop() {

  // keypadinput
  tempCount = 1; // used to collect all inputs (from inputNumber)
  tempInput = 1; // input from SlavePin
  debugMaster = 0; // curent Master Pin
  debugSlave = 0; // curent Slave Pin
  inputAmount = 0; // number of inputs only works with rows (multiple columns will return no input)
  inputNumber = 0;
  
  for(int i = 0; i < 4; i++){
    debugMaster++;
    debugSlave = 0;
    digitalWrite(masterPins[i],LOW);
    for(int j = 0; j < 3; j++){
      debugSlave++;
      tempInput = digitalRead(slavePins[j]);
      
      if(tempInput == LOW){
        inputAmount += 1;

        //displayNum[1] = numbers[debugMaster];
        //displayNum[3] = numbers[debugSlave];
        
        inputNumber = inputNumber + tempCount;
      }

      tempCount = tempCount + tempCount;
    }
    digitalWrite(masterPins[i],HIGH);
  }

  if(inputNumber < inputNumberLast && inputNumber == 0){
    //displayNum[2] = numbers[0];
    clicked(inputNumberLast);
    inputNumberLast = 0;
  }
  
  if(inputNumber > inputNumberLast){
    inputNumberLast |= inputNumber;
  }

  // Timer
   
  timeStemp = abs(millis() - timeTemp);
  timeTemp = millis();

  tick(timeStemp);
  
  // Displays the Numbers in displayNum;
  showNumber(displayNum[0],0);
  delay(3);
  showNumber(displayNum[1],1);
  delay(3);
  showNumber(displayNum[2],2);
  delay(3);
  showNumber(displayNum[3],3);
  delay(3);
}
