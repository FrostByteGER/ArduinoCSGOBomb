#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))


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
int digitDisplayArray0[] = {4,5,6,7,8,9};
int digitDisplayArray1[] = {5,6};
int digitDisplayArray2[] = {4,5,7,8,10};
int digitDisplayArray3[] = {4,5,6,7,10};
int digitDisplayArray4[] = {5,6,9,10};
int digitDisplayArray5[] = {4,6,7,9,10};
int digitDisplayArray6[] = {4,6,7,8,9,10};
int digitDisplayArray7[] = {4,5,6};
int digitDisplayArray8[] = {4,5,6,7,8,9,10};
int digitDisplayArray9[] = {4,5,6,7,9,10};



void setup(){
/*
  // Setup constant pins.
  for(int i = 0; i <= outputPins; ++i){
    pinMode(i, OUTPUT);
  }
  pinMode(9, OUTPUT); //TODO: Verify!
  pinMode(10, OUTPUT);
  pinMode(outputSoundPin, OUTPUT);*/
}

void loop(){
  drawNumber(0,0);
  delay(100);
}

/*
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
    
  }
}*/

void drawNumber(int number, int digit){
  //Reset all Digits
  for(int i = 0; i < 3;++i){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  //Reset all Digitsegments
  for(int i = 4; i < 10;++i){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  if(number == 0){
    for(int i = 0; i < NELEMS(digitDisplayArray0); ++i){
      pinMode(digitDisplayArray1[i], OUTPUT);
      digitalWrite(digitDisplayArray1[i], LOW);
    }
  }else if(number == 1){
    for(int i = 0; i < NELEMS(digitDisplayArray1); ++i){
      pinMode(digitDisplayArray1[i], INPUT);
    }
  }else if(number == 2){
    for(int i = 0; i < NELEMS(digitDisplayArray2); ++i){
      pinMode(digitDisplayArray2[i], INPUT);
    }
  }else if(number == 3){
    for(int i = 0; i < NELEMS(digitDisplayArray3); ++i){
      pinMode(digitDisplayArray3[i], INPUT);
    }
  }else if(number == 4){
    for(int i = 0; i < NELEMS(digitDisplayArray4); ++i){
      pinMode(digitDisplayArray4[i], INPUT);
    }
  }else if(number == 5){
    for(int i = 0; i < NELEMS(digitDisplayArray5); ++i){
      pinMode(digitDisplayArray5[i], INPUT);
    }
  }else if(number == 6){
    for(int i = 0; i < NELEMS(digitDisplayArray6); ++i){
      pinMode(digitDisplayArray6[i], INPUT);
    }
  }else if(number == 7){
    for(int i = 0; i < NELEMS(digitDisplayArray7); ++i){
      pinMode(digitDisplayArray7[i], INPUT);
    }
  }else if(number == 8){
    for(int i = 0; i < NELEMS(digitDisplayArray8); ++i){
      pinMode(digitDisplayArray8[i], INPUT);
    }
  }else if(number == 9){
    for(int i = 0; i < NELEMS(digitDisplayArray9); ++i){
      pinMode(digitDisplayArray9[i], INPUT);
    }
  }

  pinMode(digit, OUTPUT);
  digitalWrite(digit, HIGH);
}

