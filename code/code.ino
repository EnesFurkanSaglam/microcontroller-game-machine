#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0,U8X8_PIN_NONE);

byte secmeButonu = 22;
byte yukariButonu = 23;
byte asagiButonu = 24;

byte menuSecengi = 0;

const byte ledA = 11;
const byte ledB = 12;
const byte ledC = 13;

const byte BOYUT = 16;

const byte pedalYukseklik = 3;
const byte pedalGenislik = 128;
int pedalX = 64;
int pedalY = 60;

const byte topBoyutu = 3;
byte topX = 64;
byte topY = 48;
byte topHizX = 2;
byte topHizY = -2;

byte toplam = 1;
byte seviyeToplam = 1;
byte canSayisi = 3;
byte segmentToplam = 1;
byte aktifSeviye = 1;

struct Item {
  byte x;
  byte y;
  byte boyut;
  byte hiz;
  bool aktif;
};

struct Kutu {
  byte x;
  byte y;
  uint8_t genislik;
  uint8_t yukseklik;
  bool aktif;
};

Kutu level1[] = {
  { 2, 2, 16, 3, true },
  { 20, 2, 16, 3, true },
  { 38, 2, 16, 3, true },
  { 56, 2, 16, 3, true },
  { 74, 2, 16, 3, true },
  { 92, 2, 16, 3, true },
  { 110, 2, 16, 3, true },
  { 20, 7, 16, 3, true },
  { 38, 7, 16, 3, true },
  { 56, 7, 16, 3, true },
  { 74, 7, 16, 3, true },
  { 92, 7, 16, 3, true },
  { 38, 12, 16, 3, true },
  { 56, 12, 16, 3, true },
  { 74, 12, 16, 3, true },
  { 56, 17, 16, 3, true },
};

Kutu level2[] = {
  { 56, 2, 16, 3, true },
  { 38, 7, 16, 3, true },
  { 56, 7, 16, 3, true },
  { 74, 7, 16, 3, true },
  { 20, 12, 16, 3, true },
  { 38, 12, 16, 3, true },
  { 56, 12, 16, 3, true },
  { 74, 12, 16, 3, true },
  { 92, 12, 16, 3, true },
  { 2, 17, 16, 3, true },
  { 20, 17, 16, 3, true },
  { 38, 17, 16, 3, true },
  { 56, 17, 16, 3, true },
  { 74, 17, 16, 3, true },
  { 92, 17, 16, 3, true },
  { 110, 17, 16, 3, true },
};

Kutu level3[] = {
  { 29, 2, 16, 3, true },
  { 47, 2, 16, 3, true },
  { 65, 2, 16, 3, true },
  { 83, 2, 16, 3, true },
  { 29, 7, 16, 3, true },
  { 83, 7, 16, 3, true },
  { 29, 12, 16, 3, true },
  { 83, 12, 16, 3, true },
  { 29, 17, 16, 3, true },
  { 47, 17, 16, 3, true },
  { 65, 17, 16, 3, true },
  { 83, 17, 16, 3, true },
  { 47, 22, 16, 3, true },
  { 65, 22, 16, 3, true },
  { 29, 27, 16, 3, true },
  { 83, 27, 16, 3, true },
};

Kutu level4[] = {
  { 29, 2, 16, 3, true },
  { 47, 2, 16, 3, true },
  { 65, 2, 16, 3, true },
  { 83, 2, 16, 3, true },
  { 11, 7, 16, 3, true },
  { 101, 7, 16, 3, true },
  { 11, 12, 16, 3, true },
  { 47, 12, 16, 3, true },
  { 65, 12, 16, 3, true },
  { 101, 12, 16, 3, true },
  { 11, 17, 16, 3, true },
  { 101, 17, 16, 3, true },
  { 29, 22, 16, 3, true },
  { 47, 22, 16, 3, true },
  { 65, 22, 16, 3, true },
  { 83, 22, 16, 3, true },
};

Kutu level5[] = {
  { 2, 2, 16, 3, true },
  { 56, 2, 16, 3, true },
  { 110, 2, 16, 3, true },
  { 20, 7, 16, 3, true },
  { 38, 7, 16, 3, true },
  { 74, 7, 16, 3, true },
  { 92, 7, 16, 3, true },
  { 2, 12, 16, 3, true },
  { 56, 12, 16, 3, true },
  { 110, 12, 16, 3, true },
  { 20, 17, 16, 3, true },
  { 38, 17, 16, 3, true },
  { 74, 17, 16, 3, true },
  { 92, 17, 16, 3, true },
  { 2, 22, 16, 3, true },
  { 110, 22, 16, 3, true },
};

Item item = { 0, 0, 0, 0, false };



void sifir() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  delay(1000);
}

void bir() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  delay(1000);
}

void iki() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  delay(1000);
}

void uc() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  delay(1000);
}

void dort() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  delay(1000);
}

void bes() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  delay(1000);
}

void alti() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  delay(1000);
}

void yedi() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  delay(1000);
}

void sekiz() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  delay(1000);
}

void dokuz() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  delay(1000);
}

void SayiGoster(int sayi) {
  switch (sayi) {
    case 1:
      bir();
      break;
    case 2:
      iki();
      break;
    case 3:
      uc();
      break;
    case 4:
      dort();
      break;
    case 5:
      bes();
      break;
    case 6:
      alti();
      break;
    case 7:
      yedi();
      break;
    case 8:
      sekiz();
      break;
    case 9:
      dokuz();
      break;
    default:
      break;
  }
}

void LedGuncelle() {
  if (canSayisi >= 1)
    digitalWrite(ledA, HIGH);
  else
    digitalWrite(ledA, LOW);
  if (canSayisi >= 2)
    digitalWrite(ledB, HIGH);
  else
    digitalWrite(ledB, LOW);
  if (canSayisi >= 3)
    digitalWrite(ledC, HIGH);
  else
    digitalWrite(ledC, LOW);
}


void topCiz() {
  u8g2.drawBox(topX, topY, topBoyutu, topBoyutu);
}

void pedalCiz() {
  u8g2.drawBox(pedalX, pedalY, pedalGenislik, pedalYukseklik);
}

void levelCiz(Kutu level[]) {
  for (int i = 0; i < BOYUT; i++) {
    if (level[i].aktif) {
      u8g2.drawBox(level[i].x, level[i].y, level[i].genislik, level[i].yukseklik);
    }
  }
}

void itemCiz() {
  if (item.aktif) {
    u8g2.drawBox(item.x, item.y, item.boyut, item.boyut);
  }
}

void itemOlustur(byte x, byte y) {
  if (random(0, 10) == 0) {
    item.aktif = true;

    item.x = x;
    item.y = y;
    item.boyut = 3;
    item.hiz = 1;
  }
}

void topuGuncelle(Kutu level[]) {

  topX += topHizX;
  topY += topHizY;

  if (topX <= 0 || topX >= 127) {
    topHizX = -topHizX;
  }

  if (topY <= 0) {
    topHizY = -topHizY;
  }

  if (topY + topBoyutu >= pedalY && topX >= pedalX && topX <= pedalX + pedalGenislik) {
    topHizY = -topHizY;
  }

  bool seviyeBittiMi = true;

  for (int i = 0; i < BOYUT; i++) {

    if (level[i].aktif && topX + topBoyutu >= level[i].x && topX <= level[i].x + level[i].genislik && topY + topBoyutu >= level[i].y && topY <= level[i].y + level[i].yukseklik) {
      level[i].aktif = false;
      itemOlustur(level[i].x, level[i].y);
      topHizY = -topHizY;

      if (segmentToplam < 10) {
        SayiGoster(segmentToplam);
      } else {
        segmentToplam = 1;
        bir();
      }

      segmentToplam++;
      toplam = toplam + 1;
      seviyeToplam++;

      if (seviyeToplam == 17) {
        seviyeToplam = 0;
        sifir();
        delay(3000);
        aktifSeviye++;
        topX = 64;
        topY = 48;
        topHizY = -topHizY;
      }
    }

    if (level[i].aktif) {
      seviyeBittiMi = false;
    }
  }


  if (seviyeBittiMi && seviyeToplam != 0) {
    aktifSeviye++;
    topX = 64;
    topY = 48;
    topHizY = -topHizY;

    topHizX = topHizX * 0.2 + topHizX;
    topHizY = topHizY * 0.2 + topHizY;
  }

  if (topY >= 63) {
    canSayisi--;
    if (canSayisi == 2) {
      digitalWrite(ledC, LOW);
      topX = 64;
      topY = 48;
      topHizY = -topHizY;
    } else if (canSayisi == 1) {
      digitalWrite(ledB, LOW);
      topX = 64;
      topY = 48;
      topHizY = -topHizY;
    } else if (canSayisi == 0) {
      digitalWrite(ledA, LOW);
      topX = 200;
      topY = 200;
    }
  }
}

void itemGuncelle() {
  if (item.aktif) {
    item.y += item.hiz;

    if (item.y + item.boyut >= pedalY && item.x >= pedalX && item.x <= pedalX + pedalGenislik) {
      item.aktif = false;
      canSayisi++;
      LedGuncelle();
    }

    if (item.y > 64) {
      item.aktif = false;
    }
  }
}

void MenuCiz() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.setCursor(10, 20);
  u8g2.print("Baslat");
  u8g2.setCursor(10, 40);
  u8g2.print("Cikis");

  u8g2.setCursor(0, menuSecengi == 0 ? 20 : 40);
  u8g2.print(">");
  u8g2.sendBuffer();
}


void hareketEt() {

  int yeniPaletX = map(analogRead(A0), 0, 1023, 0, 128);
  pedalX = yeniPaletX;
}

void MesajGoster(const char* message, byte boyut) {

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x12_tr);
  u8g2.setCursor(0, 10 + boyut);
  u8g2.print(message);

  u8g2.sendBuffer();
}

void ToplamGoster() {

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x12_tr);
  u8g2.setCursor(0, 30);
  u8g2.print(toplam - 1);

  u8g2.sendBuffer();

  delay(3000);
}

void OyunuBaslat() {

  while (0 < canSayisi) {

    if (aktifSeviye == 1) {
      u8g2.clearBuffer();
      hareketEt();
      pedalCiz();
      topCiz();
      levelCiz(level1);
      topuGuncelle(level1);
      itemGuncelle();
      itemCiz();
      u8g2.sendBuffer();
    } else if (aktifSeviye == 2) {
      u8g2.clearBuffer();
      hareketEt();
      pedalCiz();
      topCiz();
      levelCiz(level2);
      topuGuncelle(level2);
      itemGuncelle();
      itemCiz();
      u8g2.sendBuffer();
    } else if (aktifSeviye == 3) {
      u8g2.clearBuffer();
      hareketEt();
      pedalCiz();
      topCiz();
      topuGuncelle(level3);
      itemGuncelle();
      itemCiz();
      levelCiz(level3);
      u8g2.sendBuffer();
    } else if (aktifSeviye == 4) {
      u8g2.clearBuffer();
      hareketEt();
      pedalCiz();
      topCiz();
      topuGuncelle(level4);
      itemGuncelle();
      itemCiz();
      levelCiz(level4);
      u8g2.sendBuffer();
    } else if (aktifSeviye == 5) {
      u8g2.clearBuffer();
      hareketEt();
      pedalCiz();
      topCiz();
      topuGuncelle(level5);
      itemGuncelle();
      itemCiz();
      levelCiz(level5);
      u8g2.sendBuffer();
    }

    if (canSayisi == 0) {
      MesajGoster("Oyun Bitti", 30);
      delay(2000);
      ToplamGoster();

      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);

      toplam = 1;
      seviyeToplam = 1;
      canSayisi = 3;
      segmentToplam = 1;
      aktifSeviye = 1;

      sifir();

      for (int i = 0; i < BOYUT; i++) {
        level1[i].aktif = true;
        level2[i].aktif = true;
        level3[i].aktif = true;
        level4[i].aktif = true;
        level5[i].aktif = true;
      }

      topX = 64;
      topY = 48;
      topHizY = -topHizY;

      break;
    }
  }
}

void setup() {

  u8g2.begin();
  Serial.begin(9600);

  delay(500);

  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);

  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  pinMode(yukariButonu, INPUT_PULLUP);
  pinMode(asagiButonu, INPUT_PULLUP);
  pinMode(secmeButonu, INPUT_PULLUP);

  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledC, HIGH);

  sifir();
  pedalCiz();
}

void loop() {

  MenuCiz();

  if (digitalRead(yukariButonu) == LOW) {

    menuSecengi = (menuSecengi == 0) ? 1 : 0;
    delay(200);
  }

  if (digitalRead(asagiButonu) == LOW) {

    menuSecengi = (menuSecengi == 0) ? 1 : 0;
    delay(200);
  }

  if (digitalRead(secmeButonu) == LOW) {

    if (menuSecengi == 0) {

      OyunuBaslat();

    } else {

      MesajGoster("Oynadiginiz icin", 5);
      delay(2000);
      MesajGoster("Tesekkurler", 30);
      delay(2000);
      MesajGoster("Hosca kalin", 40);
      while (true)
        ;
    }
  }
}