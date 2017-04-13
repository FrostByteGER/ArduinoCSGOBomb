


int mode = 0;

int noneMode = 0;
int inputMode = 1;
int outputMode = 2;

int outputPins = 3;
int outputSoundPin = 11;

int gameMode = 0;
int noneGameMode = 0;
int setGameMode = 1;
int playGameMode = 2;

int bombCode[] = {-1, -1, -1, -1};
int bombCodeActiveIndex = 3;

int defuseDecrease = 13;
int defuseIncrease = 14;

int digitArray[] = {12, 9, 8, 6};



void setup(){

  // Setup constant pins.
  for(int i = 0; i <= outputPins; ++i){
    pinMode(i, OUTPUT);
  }
  pinMode(9, OUTPUT); //TODO: Verify!
  pinMode(10, OUTPUT);
  pinMode(outputSoundPin, OUTPUT);
}

void loop(){
  
}

void setMode(int m){
  mode = m;
  if(mode == inputMode){
    for(int i = 4; i <= 8; ++i){
      pinMode(i, INPUT);
    }
  }else if(mode == outputMode){
        for(int i = 4; i <= 8; ++i){
      pinMode(i, OUTPUT);
    }
  }else{
    mode == noneMode;
    for(int i = 0; i <= 13; ++i){
      pinMode(i, INPUT);
    }
  }
}

int input(){
  setMode(inputMode);
  digitalWrite(0, HIGH);
  if(digitalRead(7) == HIGH){
    return defuseDecrease;
  }else if(digitalRead(8) == HIGH){
    return defuseIncrease;
  }
  for(int i = 0; i <= 3; ++i){
    if(i > 0){
      digitalWrite(i-1, LOW);
    }
    for(int j = 4; j <= 6; ++j){
      if(digitalRead(j) == HIGH){
        if(i == 3 && j == 5){
          return 0;
        }
        return i * 3 + j;
      }
    }
  }
  digitalWrite(3, LOW);
}

void output(){
  setMode(outputMode);
  for(int i = 0; i < 4; ++i){
    //TODO
  }
}

