#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

const byte SIZE = 16;

const byte ballSize = 3;
byte ballPositionX = 64;
byte ballPositionY = 48;

byte ballSpeedX = 1;
byte ballSpeedY = -1;

const byte paddleHeight = 3;
const byte paddleWidth = 40;

byte paddleX = 59;
byte paddleY = 54;

const byte led1 = 40;
const byte led2 = 41;
const byte led3 = 42;

byte total = 1;
byte livesNumber = 3;
byte totalNext = 1;

byte buttonSelect = 22;
byte buttonUp = 23;
byte buttonDown = 24;

byte menuOption = 0;

int heartCount = 0;

int a =30;
int b =31;
int c =32;
int d =33;
int e =34;
int f =35;
int g =36;

struct Box {
  byte x;
  byte y;
  byte width;
  byte height;
};

struct Heart{
  int x;
  int y;
};

Heart heartArray[] = {

  {200,200},
  {200,200},
  {200,200},
  {200,200},
  {200,200},
  {200,200},
  {200,200},
  {200,200},
  {200,200},
  {200,200},
  {200,200},
  {200,200},
  {200,200},
  {200,200},
  {200,200},
  {200,200},

};


Box level1[] = {
  {2, 2, 16, 3},
  {20, 2, 16, 3},
  {38, 2, 16, 3},
  {56, 2, 16, 3},
  {74, 2, 16, 3},
  {92, 2, 16, 3},
  {110, 2, 16, 3},
  {20, 7, 16, 3},
  {38, 7, 16, 3},
  {56, 7, 16, 3},
  {74, 7, 16, 3},
  {92, 7, 16, 3},
  {38, 12, 16, 3},
  {56, 12, 16, 3},
  {74, 12, 16, 3},
  {56, 17, 16, 3},
};

Box level1_raw[] = {
  {2, 2, 16, 3},
  {20, 2, 16, 3},
  {38, 2, 16, 3},
  {56, 2, 16, 3},
  {74, 2, 16, 3},
  {92, 2, 16, 3},
  {110, 2, 16, 3},
  {20, 7, 16, 3},
  {38, 7, 16, 3},
  {56, 7, 16, 3},
  {74, 7, 16, 3},
  {92, 7, 16, 3},
  {38, 12, 16, 3},
  {56, 12, 16, 3},
  {74, 12, 16, 3},
  {56, 17, 16, 3},
};

Box level2[] = {
  {56, 2, 16, 3},
  {38, 7, 16, 3},
  {56, 7, 16, 3},
  {74, 7, 16, 3},
  {20, 12, 16, 3},
  {38, 12, 16, 3},
  {56, 12, 16, 3},
  {74, 12, 16, 3},
  {92, 12, 16, 3},
  {2, 17, 16, 3},
  {20, 17, 16, 3},
  {38, 17, 16, 3},
  {56, 17, 16, 3},
  {74, 17, 16, 3},
  {92, 17, 16, 3},
  {110, 17, 16, 3},
};

Box level2_raw[] = {
  {56, 2, 16, 3},
  {38, 7, 16, 3},
  {56, 7, 16, 3},
  {74, 7, 16, 3},
  {20, 12, 16, 3},
  {38, 12, 16, 3},
  {56, 12, 16, 3},
  {74, 12, 16, 3},
  {92, 12, 16, 3},
  {2, 17, 16, 3},
  {20, 17, 16, 3},
  {38, 17, 16, 3},
  {56, 17, 16, 3},
  {74, 17, 16, 3},
  {92, 17, 16, 3},
  {110, 17, 16, 3},
};


Box level3[] = {
  {29, 2, 16, 3},
  {47, 2, 16, 3},
  {65, 2, 16, 3},
  {83, 2, 16, 3},
  {29, 7, 16, 3},
  {83, 7, 16, 3},
  {29, 12, 16, 3},
  {83, 12, 16, 3},
  {29, 17, 16, 3},
  {47, 17, 16, 3},
  {65, 17, 16, 3},
  {83, 17, 16, 3},
  {47, 22, 16, 3},
  {65, 22, 16, 3},
  {29, 27, 16, 3},
  {83, 27, 16, 3},
};

Box level3_raw[] = {
  {29, 2, 16, 3},
  {47, 2, 16, 3},
  {65, 2, 16, 3},
  {83, 2, 16, 3},
  {29, 7, 16, 3},
  {83, 7, 16, 3},
  {29, 12, 16, 3},
  {83, 12, 16, 3},
  {29, 17, 16, 3},
  {47, 17, 16, 3},
  {65, 17, 16, 3},
  {83, 17, 16, 3},
  {47, 22, 16, 3},
  {65, 22, 16, 3},
  {29, 27, 16, 3},
  {83, 27, 16, 3},
};

Box level4[] = {
  {29, 2, 16, 3},
  {47, 2, 16, 3},
  {65, 2, 16, 3},
  {83, 2, 16, 3},
  {11, 7, 16, 3},
  {101, 7, 16, 3},
  {11, 12, 16, 3},
  {47, 12, 16, 3},
  {65, 12, 16, 3},
  {101, 12, 16, 3},
  {11, 17, 16, 3},
  {101, 17, 16, 3},
  {29, 22, 16, 3},
  {47, 22, 16, 3},
  {65, 22, 16, 3},
  {83, 22, 16, 3},
};

Box level4_raw[] = {
  {29, 2, 16, 3},
  {47, 2, 16, 3},
  {65, 2, 16, 3},
  {83, 2, 16, 3},
  {11, 7, 16, 3},
  {101, 7, 16, 3},
  {11, 12, 16, 3},
  {47, 12, 16, 3},
  {65, 12, 16, 3},
  {101, 12, 16, 3},
  {11, 17, 16, 3},
  {101, 17, 16, 3},
  {29, 22, 16, 3},
  {47, 22, 16, 3},
  {65, 22, 16, 3},
  {83, 22, 16, 3},
};

Box level5[] = {
  {2, 2, 16, 3},
  {56, 2, 16, 3},
  {110, 2, 16, 3},
  {20, 7, 16, 3},
  {38, 7, 16, 3},
  {74, 7, 16, 3},
  {92, 7, 16, 3},
  {2, 12, 16, 3},
  {56, 12, 16, 3},
  {110, 12, 16, 3},
  {20, 17, 16, 3},
  {38, 17, 16, 3},
  {74, 17, 16, 3},
  {92, 17, 16, 3},
  {2, 22, 16, 3},
  {110, 22, 16, 3},

};

Box level5_raw[] = {
  {2, 2, 16, 3},
  {56, 2, 16, 3},
  {110, 2, 16, 3},
  {20, 7, 16, 3},
  {38, 7, 16, 3},
  {74, 7, 16, 3},
  {92, 7, 16, 3},
  {2, 12, 16, 3},
  {56, 12, 16, 3},
  {110, 12, 16, 3},
  {20, 17, 16, 3},
  {38, 17, 16, 3},
  {74, 17, 16, 3},
  {92, 17, 16, 3},
  {2, 22, 16, 3},
  {110, 22, 16, 3},

};


void zero() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
  delay(1000);
}
void one(){
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  delay(1000);
  
}

void two() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
  delay(1000);
}

 void three() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
  delay(1000);
  
 }

void four() {

  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  delay(1000);
  
}

void five() {
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  delay(1000);
  
}

void six() {
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  delay(1000);
}

void seven() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  delay(1000);
}

void eight() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  delay(1000);
  
}

void nine() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  delay(1000);
}

void displayNumber(int num) {
  switch(num) {
    case 1:
      one();
      break;
    case 2:
      two();
      break;
    case 3:
      three();
      break;
    case 4:
      four();
      break;
    case 5:
      five();
      break;
    case 6:
      six();
      break;
    case 7:
      seven();
      break;
    case 8:
      eight();
      break;
    case 9:
      nine();
      break;
    default:
     
      break;
  }
}


void changeHeartPosition(){

  for (int i = 0; i < SIZE; i++) {
    if(heartArray[i].y < 65){ 
    
      if(heartArray[i].y + 1 >= paddleY && heartArray[i].x >= paddleX && heartArray[i].x <= paddleX + paddleWidth){
     
        heartArray[i].y = 200;
        heartArray[i].x = 200;

        if(livesNumber <3){
          livesNumber++;
          ledYak();
        }
      }

      u8g2.clearBuffer();
      u8g2.drawBox(heartArray[i].x, heartArray[i].y, 2, 2); 
      heartArray[i].y++; 
      u8g2.sendBuffer(); 
    }
  }

}


void drawLevel(Box level[]) {

  //u8g2.clearBuffer();
  
  for (int i = 0; i < SIZE; i++) {
    u8g2.drawBox(level[i].x, level[i].y, level[i].width, level[i].height);
  }
  
  u8g2.sendBuffer();

}


void drawPaddle(){

  int potansiyometreDegeri = analogRead(A0);
  int ekranGenislik = 128 - paddleWidth;
  int newPaddleX = map(potansiyometreDegeri, 0, 1023, 0, ekranGenislik);

  u8g2.clearBuffer();
  u8g2.drawBox(newPaddleX, paddleY, paddleWidth, paddleHeight);
  u8g2.sendBuffer();
  
  paddleX = newPaddleX;

}


void ledYak(){

  if(livesNumber == 3){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);

  }
  if(livesNumber == 2){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    
  }
  if(livesNumber == 1){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    
  }
  if(livesNumber == 0){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }

}


void drawMenu() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.setCursor(10, 20);
  u8g2.print("Start");
  u8g2.setCursor(10, 40);
  u8g2.print("Exit");

  u8g2.setCursor(0, menuOption == 0 ? 20 : 40);
  u8g2.print(">");
  u8g2.sendBuffer();

}

void showTotal(){

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x12_tr);
  u8g2.setCursor(0, 30);
  u8g2.print(totalNext-1);
  
  u8g2.sendBuffer();

  delay(3000);
}


void displayMessage(const char* message,byte size) {

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x12_tr);
  u8g2.setCursor(0, 10+size);
  u8g2.print(message);
  
  u8g2.sendBuffer();

}

void updateBall(Box level[]) {

  //u8g2.clearBuffer();
  u8g2.drawBox(ballPositionX, ballPositionY, ballSize, ballSize); 
  u8g2.sendBuffer();
  
  ballPositionX += ballSpeedX; 
  ballPositionY += ballSpeedY; 

  
  
  if (ballPositionX <= 0 || ballPositionX >= 127) {
    ballSpeedX = -ballSpeedX; 
  }

  
  if(ballPositionY <= 0){
        ballSpeedY = -ballSpeedY; 
  }

  if(ballPositionY >= 63){
    livesNumber = livesNumber - 1;
    if(livesNumber == 2){
      ledYak();
    ballPositionX = 64; 
    ballPositionY = 48; 
    ballSpeedY = -ballSpeedY;
    }else if(livesNumber == 1){
      ledYak();
    ballPositionX = 64; 
    ballPositionY = 48; 
    ballSpeedY = -ballSpeedY; 
    }else if(livesNumber == 0){
      ledYak();
    ballPositionX = 200;
    ballPositionY = 200;
    }
  }

  
  if (ballPositionY + ballSize >= paddleY && ballPositionX >= paddleX && ballPositionX <= paddleX + paddleWidth) {
    ballSpeedY = -ballSpeedY; 
  }

  
  for (int i = 0; i < SIZE; i++) {

    if (ballPositionX + ballSize >= level[i].x && ballPositionX <= level[i].x + level[i].width && ballPositionY + ballSize >= level[i].y && ballPositionY <= level[i].y + level[i].height) {

      int x = level[i].x;
      int y = level[i].y;

      
      level[i].x =+ 200; 
      level[i].y =+ 200; 
      ballSpeedY = -ballSpeedY; 

      if (true) {

        heartArray[heartCount].x = x;
        heartArray[heartCount].y = y;
        heartCount++;

      }
      
      if(total < 10){
        displayNumber(total);
      }else{
        total = 1;
        one();
      }
      total = total + 1;
      totalNext = totalNext + 1;

      break;

    }

  }
}

void reDrawLevel(){

  u8g2.clearBuffer();
  

   for (int i = 0; i < SIZE; i++) {
   
    level1[i].x = level1_raw[i].x;
    level1[i].y = level1_raw[i].y;

    level2[i].x = level2_raw[i].x;
    level2[i].y = level2_raw[i].y;

    level3[i].x = level3_raw[i].x;
    level3[i].y = level3_raw[i].y;

    level4[i].x = level4_raw[i].x;
    level4[i].y = level4_raw[i].y;

    level5[i].x = level5_raw[i].x;
    level5[i].y = level5_raw[i].y;

  
  }

  for (int i = 0; i < SIZE; i++) {
    heartArray[i].x = 200;
    heartArray[i].y = 200;
  }

  u8g2.sendBuffer();

  zero(); 

  livesNumber=3;
  total = 1;
  totalNext = 1;
  int heartCount = 0;
  ballPositionX = 64; 
  ballPositionY = 48; 


}

void startGame() {

  

  while (livesNumber > 0) {

    changeHeartPosition();

  
    if(totalNext >=1 && totalNext < 4){


      drawLevel(level1);
      updateBall(level1);
      drawPaddle();
      
    }

     if(totalNext > 4 && totalNext < 8){

      updateBall(level2);
      drawLevel(level2);
      drawPaddle();
      
    }

    if(totalNext > 8 && totalNext < 12){

      updateBall(level3);
      drawLevel(level3);
      drawPaddle();
      
    }
    if(totalNext > 12 && totalNext < 16){

    
      updateBall(level4);
      drawLevel(level4);
      drawPaddle();
      
    }
    if(totalNext > 16 && totalNext < 20){

      
      updateBall(level5);
      drawLevel(level5);
      drawPaddle();
      
    }

     if (totalNext == 4 || totalNext == 8 || totalNext == 12 || totalNext == 16) {
      ballPositionX = 64;
      ballPositionY = 48; 
      ballSpeedY = -ballSpeedY; 
      totalNext = totalNext + 1;
     
      delay(5000);

    }



    if (livesNumber == 0) {
      displayMessage("Game Over", 30);
      delay(2000);
      showTotal();
      delay(3000);
      break;
    }
  }

 
  reDrawLevel();

}

void setup() {

  Serial.begin(9600);

  u8g2.begin();

  pinMode(A0,INPUT);
  
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(buttonUp, INPUT_PULLUP);
  pinMode(buttonDown, INPUT_PULLUP);
  pinMode(buttonSelect, INPUT_PULLUP);

  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);

  zero(); 

}

void loop() {

  ledYak();
  drawMenu();

  if (digitalRead(buttonUp) == LOW) {
    
    menuOption = (menuOption == 0) ? 1 : 0;
    delay(200); 
  }

  if (digitalRead(buttonDown) == LOW) {
   
    menuOption = (menuOption == 0) ? 1 : 0;
    delay(200); 
  }

  if (digitalRead(buttonSelect) == LOW) {


    if (menuOption == 0) {
      
      startGame();
    

    } else {
      
      displayMessage("Thank you for your",5);
      delay(2000);
      displayMessage("interest in our game",30);
      delay(2000);
      displayMessage("BB",40);
      while (true); 
    }
  }

}






