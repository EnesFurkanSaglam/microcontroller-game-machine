#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);


const int ballSize = 2;
int ballPositionX = 64;
int ballPositionY = 48;



void setup() {
  u8g2.begin();
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop() {

  drawLevel_1();
  delay(1000);
  drawLevel_2();
  delay(1000);
  drawLevel_3();
  delay(1000);
  drawLevel_4();
  delay(1000);
  drawLevel_5();
  delay(1000);
  //drawBall();
  delay(1000);
}


void drawBall() {

  u8g2.drawBox(ballPositionX, ballPositionY, ballSize, ballSize);
  u8g2.sendBuffer();
  
}

void drawLevel_1(){

  u8g2.clearBuffer();

  u8g2.drawBox(2, 2, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(20, 2, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(38, 2, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(56, 2, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(74, 2, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(92, 2, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(110, 2, 16, 3); // 3. paramtre genişlik

  u8g2.drawBox(20, 7, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(38, 7, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(56, 7, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(74, 7, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(92, 7, 16, 3); // 3. paramtre genişlik

  u8g2.drawBox(38, 12, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(56, 12, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(74, 12, 16, 3); // 3. paramtre genişlik

  u8g2.drawBox(56, 17, 16, 3); // 3. paramtre genişlik

  u8g2.sendBuffer();

}
void drawLevel_2(){

  u8g2.clearBuffer();

  //üstten başladık
  u8g2.drawBox(56, 2, 16, 3); // 3. paramtre genişlik

  u8g2.drawBox(38, 7, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(56, 7, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(74, 7, 16, 3); // 3. paramtre genişlik

  u8g2.drawBox(20, 12, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(38, 12, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(56, 12, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(74, 12, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(92, 12, 16, 3); // 3. paramtre genişlik

  u8g2.drawBox(2, 17, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(20, 17, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(38, 17, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(56, 17, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(74, 17, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(92, 17, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(110, 17, 16, 3); // 3. paramtre genişlik

  u8g2.sendBuffer();


}
void drawLevel_3(){

  u8g2.clearBuffer();

  u8g2.drawBox(29, 2, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(47, 2, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(65, 2, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(83, 2, 16, 3); // 3. paramtre genişlik

  u8g2.drawBox(29, 7, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(83, 7, 16, 3); // 3. paramtre genişlik

  u8g2.drawBox(29, 12, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(83, 12, 16, 3); // 3. paramtre genişlik

  u8g2.drawBox(29, 17, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(47, 17, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(65, 17, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(83, 17, 16, 3); // 3. paramtre genişlik

  u8g2.drawBox(47, 22, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(65, 22, 16, 3); // 3. paramtre genişlik

  u8g2.drawBox(29, 27, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(83, 27, 16, 3); // 3. paramtre genişlik

  u8g2.sendBuffer();

}
void drawLevel_4(){

  u8g2.clearBuffer();

  u8g2.drawBox(29, 2, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(47, 2, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(65, 2, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(83, 2, 16, 3); // 3. paramtre genişlik

  u8g2.drawBox(11, 7, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(101, 7, 16, 3); // 3. paramtre genişlik

  u8g2.drawBox(11, 12, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(47, 12, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(65, 12, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(101, 12, 16, 3); // 3. paramtre genişlik

  u8g2.drawBox(11, 17, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(101, 17, 16, 3); // 3. paramtre genişlik

  u8g2.drawBox(29, 22, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(47, 22, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(65, 22, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(83, 22, 16, 3); // 3. paramtre genişlik

  u8g2.sendBuffer();

}
void drawLevel_5(){

  u8g2.clearBuffer();

  u8g2.drawBox(2, 2, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(56, 2, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(110, 2, 16, 3); // 3. paramtre genişlik

  u8g2.drawBox(20, 7, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(38, 7, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(74, 7, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(92, 7, 16, 3); // 3. paramtre genişlik

  u8g2.drawBox(2, 12, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(56, 12, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(110, 12, 16, 3); // 3. paramtre genişlik

  u8g2.drawBox(20, 17, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(38, 17, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(74, 17, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(92, 17, 16, 3); // 3. paramtre genişlik

  u8g2.drawBox(2, 22, 16, 3); // 3. paramtre genişlik
  u8g2.drawBox(110, 22, 16, 3); // 3. paramtre genişlik

  

  u8g2.sendBuffer();

}











void zero() {
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  delay(1000);
}
void one(){
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  delay(1000);
  
}

void two() {
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  delay(1000);
}

 void three() {
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  delay(1000);
  
 }

void four() {
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  delay(1000);
  
}

void five() {
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  delay(1000);
  
}

void six() {
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  delay(1000);
}

void seven() {
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  delay(1000);
  }

void eight() {
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  delay(1000);
  
}

void nine() {
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  delay(1000);
}
