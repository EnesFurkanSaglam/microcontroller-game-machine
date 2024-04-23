#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

const byte SIZE = 16;

const byte ballSize = 3;
byte ballPositionX = 64;
byte ballPositionY = 48;
byte ballSpeedX = 2;
byte ballSpeedY = -2;

const byte paddleHeight = 3;
const byte paddleWidth = 30;
int paddleX = 64;
int paddleY = 60;

//ledlerin bağlandığı pinler
const byte led1 = 11;
const byte led2 = 12;
const byte led3 = 13;

byte total = 1;
byte levelTotal = 1;
byte livesNumber = 3;
byte segmentTotal= 1;
byte activeLevel = 1;

byte buttonSelect = 22;
byte buttonUp = 23;
byte buttonDown = 24;

byte menuOption = 0;


struct Box {
  byte x;
  byte y;
  uint8_t width;
  uint8_t height;
  bool active; 
};


// düşen itemın tanımlanması
struct Item {
  byte x;
  byte y;
  byte size;
  byte speed;
  bool active;
};

Item item = {0, 0, 0, 0, false};


//bütün bölümler ve bölüm tasarımları
Box level1[] = {
  {2, 2, 16, 3,true},
  {20, 2, 16, 3,true},
  {38, 2, 16, 3,true},
  {56, 2, 16, 3,true},
  {74, 2, 16, 3,true},
  {92, 2, 16, 3,true},
  {110, 2, 16, 3,true},
  {20, 7, 16, 3,true},
  {38, 7, 16, 3,true},
  {56, 7, 16, 3,true},
  {74, 7, 16, 3,true},
  {92, 7, 16, 3,true},
  {38, 12, 16, 3,true},
  {56, 12, 16, 3,true},
  {74, 12, 16, 3,true},
  {56, 17, 16, 3,true},
};

Box level2[] = {
  {56, 2, 16, 3,true},
  {38, 7, 16, 3,true},
  {56, 7, 16, 3,true},
  {74, 7, 16, 3,true},
  {20, 12, 16, 3,true},
  {38, 12, 16, 3,true},
  {56, 12, 16, 3,true},
  {74, 12, 16, 3,true},
  {92, 12, 16, 3,true},
  {2, 17, 16, 3,true},
  {20, 17, 16, 3,true},
  {38, 17, 16, 3,true},
  {56, 17, 16, 3,true},
  {74, 17, 16, 3,true},
  {92, 17, 16, 3,true},
  {110, 17, 16, 3,true},
};

Box level3[] = {
  {29, 2, 16, 3,true},
  {47, 2, 16, 3,true},
  {65, 2, 16, 3,true},
  {83, 2, 16, 3,true},
  {29, 7, 16, 3,true},
  {83, 7, 16, 3,true},
  {29, 12, 16, 3,true},
  {83, 12, 16, 3,true},
  {29, 17, 16, 3,true},
  {47, 17, 16, 3,true},
  {65, 17, 16, 3,true},
  {83, 17, 16, 3,true},
  {47, 22, 16, 3,true},
  {65, 22, 16, 3,true},
  {29, 27, 16, 3,true},
  {83, 27, 16, 3,true},
};

Box level4[] = {
  {29, 2, 16, 3,true},
  {47, 2, 16, 3,true},
  {65, 2, 16, 3,true},
  {83, 2, 16, 3,true},
  {11, 7, 16, 3,true},
  {101, 7, 16, 3,true},
  {11, 12, 16, 3,true},
  {47, 12, 16, 3,true},
  {65, 12, 16, 3,true},
  {101, 12, 16, 3,true},
  {11, 17, 16, 3,true},
  {101, 17, 16, 3,true},
  {29, 22, 16, 3,true},
  {47, 22, 16, 3,true},
  {65, 22, 16, 3,true},
  {83, 22, 16, 3,true},
};

Box level5[] = {
  {2, 2, 16, 3,true},
  {56, 2, 16, 3,true},
  {110, 2, 16, 3,true},
  {20, 7, 16, 3,true},
  {38, 7, 16, 3,true},
  {74, 7, 16, 3,true},
  {92, 7, 16, 3,true},
  {2, 12, 16, 3,true},
  {56, 12, 16, 3,true},
  {110, 12, 16, 3,true},
  {20, 17, 16, 3,true},
  {38, 17, 16, 3,true},
  {74, 17, 16, 3,true},
  {92, 17, 16, 3,true},
  {2, 22, 16, 3,true},
  {110, 22, 16, 3,true},
};


//7 seg için gerekli kodlar
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

//hangi bölümün aktif olduğuna göre o bölümü ekrana çizme
void drawLevel(Box level[]) {
  for (int i = 0; i < SIZE; i++) {
    if (level[i].active) {
      u8g2.drawBox(level[i].x, level[i].y, level[i].width, level[i].height);
    }
  }
}



// topu çizme
void drawBall() {
  u8g2.drawBox(ballPositionX, ballPositionY, ballSize, ballSize); // Topu çiz
}




void updateBall(Box level[]) {
  //topun x ve y ekseninde hareket etmesini sağlayan yer
  ballPositionX += ballSpeedX;
  ballPositionY += ballSpeedY;

 //topun ekranın x sınırlarını kontrol et
  if (ballPositionX <= 0 || ballPositionX >= 127) {
    ballSpeedX = -ballSpeedX; 
  }
//top ekranın üstüne çarparsa yönü ters çevir
  if (ballPositionY <= 0) {
    ballSpeedY = -ballSpeedY; 
  }
//topun paddle'a çarpma kontrolü
  if (ballPositionY + ballSize >= paddleY && ballPositionX >= paddleX && ballPositionX <= paddleX + paddleWidth) {
    ballSpeedY = -ballSpeedY; 
  }

  bool allBlocksDestroyed = true; //tüm blokların olup olmadığı kontrol et
  for (int i = 0; i < SIZE; i++) {
    //topun bloğa çarpma kontrolü
    if (level[i].active &&
        ballPositionX + ballSize >= level[i].x && ballPositionX <= level[i].x + level[i].width &&
        ballPositionY + ballSize >= level[i].y && ballPositionY <= level[i].y + level[i].height) {
      level[i].active = false; //ekrandan bloğu sil
      itemOlustur(level[i].x, level[i].y); //item oluştur
      ballSpeedY = -ballSpeedY; 
//7segmentte gösterilecek blok sayısı için
      if (segmentTotal < 10) {
       displayNumber(segmentTotal);
      }else{
        segmentTotal = 1;
        one();
      }
      segmentTotal++;
       total = total + 1;
      levelTotal++; 
      //bir bölümde kırılan toplam blok sayısı 17
      if (levelTotal == 17) {
        levelTotal = 0; 
        zero(); // 7 segmenti sıfırla
        delay(3000); 
        activeLevel++; // sonraki bölüme geç
        ballPositionX = 64; // topu başlangıç yerine getir
        ballPositionY = 48;
        ballSpeedY = -ballSpeedY;
      }
    }
    //ekranda blok var mı yok mu kontrolü
    if (level[i].active) {
      allBlocksDestroyed = false;
    }
  }

//bölüm bitti mi bitmedi mi kontrolü biterse sonraki bölüme geçiriyor
  if (allBlocksDestroyed && levelTotal != 0) {
    activeLevel++; 
    ballPositionX = 64;
    ballPositionY = 48;
    ballSpeedY = -ballSpeedY; 
    
    //seviye değişince topun hızı %20 artırdığımız yer
    ballSpeedX =ballSpeedX*0.2+ballSpeedX;
    ballSpeedY = ballSpeedY*0.2+ballSpeedY;
}

//topun ekranın altına düştüğünde çalışacak yer
  if (ballPositionY >= 63 ) {
    livesNumber--; 
    if (livesNumber == 2) {
      digitalWrite(led3, LOW);//ledi kapatır
      ballPositionX = 64; 
    ballPositionY = 48; 
    ballSpeedY = -ballSpeedY; 
    } else if (livesNumber == 1) {
      digitalWrite(led2, LOW); 
      ballPositionX = 64; 
    ballPositionY = 48; 
    ballSpeedY = -ballSpeedY; 
    } else if (livesNumber == 0) {
      digitalWrite(led1, LOW); 
      ballPositionX = 200; // topu ekrandan siler
      ballPositionY = 200;
      

    }
  }
}


// 7 segment displayde ekrana sayı yazdırma
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


// peddle çizer sonra loop ile tekrarlanır bu method sürekli
void drawPaddle(){
  u8g2.drawBox(paddleX, paddleY, paddleWidth, paddleHeight);
}


//can veren item'ı çizme
void drawItem() {
  if (item.active) {
    u8g2.drawBox(item.x, item.y, item.size, item.size);
  }
}

void itemOlustur(byte x, byte y) {
  if (random(0, 10) == 0) { //blok kırılınca yüzde 10 ihtimalle çıkma kısmı
    item.active = true;
    //çıkan itemın koordinatları
    item.x = x; 
    item.y = y; 
    item.size = 3; 
    item.speed = 1; 
  }
  
}



void updateItem() {
  if (item.active) {
    item.y += item.speed;//itemı sadece y ekseninde hareket ettir
    // itemın paddle ile çarpışma kontrolü
    if (item.y + item.size >= paddleY && item.x >= paddleX && item.x <= paddleX + paddleWidth) {
      item.active = false; // itemı sil
      livesNumber++; // oyuncuya can ver
      updateLivesLED(); 
    }
    // item ekrandan dışarı çıkarsa
    if (item.y > 64) {
      item.active = false; 
    }
  }
}


// item alımnasına göre led düzenleme
void updateLivesLED() {
  if(livesNumber>=1)
  digitalWrite(led1,HIGH);
  else
  digitalWrite(led1,LOW);
  if(livesNumber>=2)
  digitalWrite(led2,HIGH);
  else
  digitalWrite(led2,LOW);
  if(livesNumber>=3)
  digitalWrite(led3,HIGH);
  else
  digitalWrite(led3,LOW);
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



// program ilk çalışmaya başladığında bu çalışır
void setup() {
  u8g2.begin();
  Serial.begin(9600);
  delay(500);
 //pin girişleri
  pinMode(A0,INPUT);
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

   pinMode(buttonUp, INPUT_PULLUP);
  pinMode(buttonDown, INPUT_PULLUP);
  pinMode(buttonSelect, INPUT_PULLUP);


  //tüm ledler başta açık
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);

  // başta 7 seg 0
  zero();
//oyun başınd paddle çizer
      drawPaddle();
}

void hareketEt(){
//potansiyometreden gelen değere göre her defasında paddleın konumunu düzenler
  int yeniPaletX = map(analogRead(A0), 0, 1023, 0, 128);
  paddleX = yeniPaletX; // Paletin X konumunu güncelle
 
}

void displayMessage(const char* message,byte size) {

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x12_tr);
  u8g2.setCursor(0, 10+size);
  u8g2.print(message);
  
  u8g2.sendBuffer();

}

void showTotal(){

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x12_tr);
  u8g2.setCursor(0, 30);
  u8g2.print(total-1);
  
  u8g2.sendBuffer();

  delay(3000);
}


void startGame(){

while(0 <livesNumber){

if(activeLevel == 1){
    u8g2.clearBuffer();//ekranı sil
  hareketEt();
  drawPaddle();
  drawBall();
  drawLevel(level1);
  updateBall(level1);
  updateItem(); 
  drawItem(); 
  u8g2.sendBuffer();//ekrana gönderme
  }else if(activeLevel == 2){
    u8g2.clearBuffer();
   hareketEt();
  drawPaddle();
  drawBall();
      drawLevel(level2);
      updateBall(level2);
      updateItem(); 
      drawItem(); 
       u8g2.sendBuffer(); 
  }else if(activeLevel == 3){
    u8g2.clearBuffer();
   hareketEt();
  drawPaddle();
  drawBall();
      updateBall(level3);
      updateItem(); 
     drawItem(); 
      drawLevel(level3);
       u8g2.sendBuffer(); 
  }else if(activeLevel == 4){
    u8g2.clearBuffer();
   hareketEt();
  drawPaddle();
  drawBall();
      updateBall(level4);
      updateItem(); 
     drawItem(); 
      drawLevel(level4);
       u8g2.sendBuffer(); 
  }else if(activeLevel == 5){
    u8g2.clearBuffer();
   hareketEt();
  drawPaddle();
  drawBall();
  updateBall(level5);
  updateItem(); 
     drawItem(); 
      drawLevel(level5);
       u8g2.sendBuffer(); 
  }


  if (livesNumber == 0) {
      displayMessage("Game Over", 30);
      delay(2000);
      showTotal();

     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH);

   

   total = 1;
   levelTotal = 1;
   livesNumber = 3;
   segmentTotal= 1;
   activeLevel = 1;


  // başta 7 seg 0
  zero();

  for(int i= 0;i<SIZE;i++){
    level1[i].active = true;
    level2[i].active = true;
    level3[i].active = true;
    level4[i].active = true;
    level5[i].active = true;
  }

   ballPositionX = 64;
   ballPositionY = 48;
   ballSpeedY = -ballSpeedY; 

      break;
  }



  }

  

}


void loop() {
  
  
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