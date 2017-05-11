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
  // Set All Digits to Output
  for(int i = 0; i <= 3;++i){
    pinMode(i, OUTPUT);
  }
  //Set all Digitsegments to Output
  for(int i = 4; i <= 10;++i){
    pinMode(i, OUTPUT);
  }
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
  drawNumber(4,3);
  drawNumber(7,2);
  drawNumber(1,1);
  drawNumber(8,0);
  /*
  for(int i = 0; i < 10; i++){
  drawNumber(i,0);
  delay(250);
  drawNumber(i,1);
  delay(250);
  drawNumber(i,2);
  delay(250);
  drawNumber(i,3);
  delay(250);
  }*/

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
  for(int i = 0; i <= 3;++i){
    digitalWrite(i, HIGH);
  }
  //Reset all Digitsegments
  for(int i = 4; i <= 10;++i){
    digitalWrite(i, LOW);
  }
  if(number == 0){
    for(int i = 0; i < NELEMS(digitDisplayArray0); ++i){
      digitalWrite(digitDisplayArray0[i], HIGH);
    }
  }else if(number == 1){
    for(int i = 0; i < NELEMS(digitDisplayArray1); ++i){
      digitalWrite(digitDisplayArray1[i], HIGH);
    }
  }else if(number == 2){
    for(int i = 0; i < NELEMS(digitDisplayArray2); ++i){
      digitalWrite(digitDisplayArray2[i], HIGH);
    }
  }else if(number == 3){
    for(int i = 0; i < NELEMS(digitDisplayArray3); ++i){
      digitalWrite(digitDisplayArray3[i], HIGH);
    }
  }else if(number == 4){
    for(int i = 0; i < NELEMS(digitDisplayArray4); ++i){
      digitalWrite(digitDisplayArray4[i], HIGH);
    }
  }else if(number == 5){
    for(int i = 0; i < NELEMS(digitDisplayArray5); ++i){
      digitalWrite(digitDisplayArray5[i], HIGH);
    }
  }else if(number == 6){
    for(int i = 0; i < NELEMS(digitDisplayArray6); ++i){
      digitalWrite(digitDisplayArray6[i], HIGH);
    }
  }else if(number == 7){
    for(int i = 0; i < NELEMS(digitDisplayArray7); ++i){
      digitalWrite(digitDisplayArray7[i], HIGH);
    }
  }else if(number == 8){
    for(int i = 0; i < NELEMS(digitDisplayArray8); ++i){
      digitalWrite(digitDisplayArray8[i], HIGH);
    }
  }else if(number == 9){
    for(int i = 0; i < NELEMS(digitDisplayArray9); ++i){
      digitalWrite(digitDisplayArray9[i], HIGH);
    }
  }
  digitalWrite(digit, LOW);
  delay(1);
  //if(number == 8) delay(3);
}

