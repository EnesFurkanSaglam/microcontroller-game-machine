#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

const int SIZE = 16;

const int ballSize = 1;
int ballPositionX = 64;
int ballPositionY = 48;
int ballSpeedX = 1;
int ballSpeedY = -1;

const int paddleHeight = 3;
const int paddleWidth = 10;
int paddleX = 59;
int paddleY = 54;

const int led1 = 11;
const int led2 = 12;
const int led3 = 13;

struct Box {
  int x;
  int y;
  int width;
  int height;
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


void drawLevel(Box level[]) {
  u8g2.clearBuffer();
  for (int i = 0; i < SIZE; i++) {
    u8g2.drawBox(level[i].x, level[i].y, level[i].width, level[i].height);
  }
  u8g2.sendBuffer();
}


void ledAc(int led){
  digitalWrite(led, HIGH);
}
void ledKapat(int led){
  digitalWrite(led, LOW);

}

void drawBall() {
  u8g2.clearBuffer(); // Önceki çizimleri temizle
  u8g2.drawDisc(ballPositionX, ballPositionY, ballSize); // Topu çiz
  u8g2.sendBuffer(); // Çizimi ekrana gönder
}




void updateBall() {
  u8g2.clearBuffer();
  u8g2.drawDisc(ballPositionX, ballPositionY, ballSize); // Topu çiz
  u8g2.sendBuffer();

  ballPositionX += ballSpeedX; // Topun x konumunu güncelle
  ballPositionY += ballSpeedY; // Topun y konumunu güncelle

  // Topun ekran sınırlarına çarpmasını kontrol et
  if (ballPositionX <= 0 || ballPositionX >= 127) {
    ballSpeedX = -ballSpeedX; // X yönlü hızı tersine çevir
  }
  if (ballPositionY <= 0 || ballPositionY >= 63) {
    ballSpeedY = -ballSpeedY; // Y yönlü hızı tersine çevir
  }

  // Topun paddle'a çarpmasını kontrol et
  // sıkıntı var
  if (ballPositionY >= paddleY - ballSize && ballPositionX >= paddleX && ballPositionX <= paddleX + paddleWidth) {
    ballSpeedY = -ballSpeedY; // Y yönlü hızı tersine çevir
  }
}

void drawPaddle(){
  int potansiyometreDegeri = analogRead(A0); // Potansiyometrenin değerini oku (0-1023 arası)
  int ekranGenislik = 128 - paddleWidth; // Ekran genişliğini hesapla
  int newPaddleX = map(potansiyometreDegeri, 0, 1023, 0, ekranGenislik); // Potansiyometre değerini ekran genişliğine dönüştür
  u8g2.clearBuffer();
  u8g2.drawBox(newPaddleX, paddleY, paddleWidth, paddleHeight); // Yeni konumda kutuyu çiz
  u8g2.sendBuffer();
  paddleX = newPaddleX; // Kutunun yeni konumunu sakla
}




void setup() {
  u8g2.begin();
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {

  updateBall();
  drawPaddle();
  drawLevel(level1);
  delay(20); // Topun hareket hızını ayarlar
  
}




