#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

byte buttonSelection = 22;
byte buttonUp = 23;
byte buttonDown = 24;

byte menuOption = 0;

const byte ledA = 11;
const byte ledB = 12;
const byte ledC = 13;

const byte SIZE = 16;

const byte pedalHeight = 3;
const byte pedalWidth = 128;
int pedalX = 64;
int pedalY = 60;

const byte ballSize = 3;
byte ballX = 64;
byte ballY = 48;
byte ballSpeedX = 2;
byte ballSpeedY = -2;

byte total = 1;
byte totalLevel = 1;
byte totalHeart = 3;
byte totalSegment = 1;
byte activeLevel = 1;

struct Item {
  byte x;
  byte y;
  byte size;
  byte speed;
  bool active;
};

struct Box {
  byte x;
  byte y;
  uint8_t width;
  uint8_t height;
  bool active;
};

Box level1[] = {
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

Box level2[] = {
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

Box level3[] = {
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

Box level4[] = {
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

Box level5[] = {
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



void zero() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  delay(1000);
}

void one() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  delay(1000);
}

void two() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  delay(1000);
}

void three() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  delay(1000);
}

void four() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  delay(1000);
}

void five() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  delay(1000);
}

void six() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  delay(1000);
}

void seven() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  delay(1000);
}

void eight() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  delay(1000);
}

void nine() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  delay(1000);
}

void showNumber(int number) {
  switch (number) {
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

void UpdateLED() {
  if (totalHeart >= 1)
    digitalWrite(ledA, HIGH);
  else
    digitalWrite(ledA, LOW);
  if (totalHeart >= 2)
    digitalWrite(ledB, HIGH);
  else
    digitalWrite(ledB, LOW);
  if (totalHeart >= 3)
    digitalWrite(ledC, HIGH);
  else
    digitalWrite(ledC, LOW);
}


void DrawBall() {
  u8g2.drawBox(ballX, ballY, ballSize, ballSize);
}

void DrawPedal() {
  u8g2.drawBox(pedalX, pedalY, pedalWidth, pedalHeight);
}

void DrawLevel(Box level[]) {
  for (int i = 0; i < SIZE; i++) {
    if (level[i].active) {
      u8g2.drawBox(level[i].x, level[i].y, level[i].width, level[i].height);
    }
  }
}

void DrawItem() {
  if (item.active) {
    u8g2.drawBox(item.x, item.y, item.size, item.size);
  }
}

void CreateItem(byte x, byte y) {
  if (random(0, 10) == 0) {
    item.active = true;

    item.x = x;
    item.y = y;
    item.size = 3;
    item.speed = 1;
  }
}

void UpdateBall(Box level[]) {

  ballX += ballSpeedX;
  ballY += ballSpeedY;

  if (ballX <= 0 || ballX >= 127) {
    ballSpeedX = -ballSpeedX;
  }

  if (ballY <= 0) {
    ballSpeedY = -ballSpeedY;
  }

  if (ballY + ballSize >= pedalY && ballX >= pedalX && ballX <= pedalX + pedalWidth) {
    ballSpeedY = -ballSpeedY;
  }

  bool isLevelFinished = true;

  for (int i = 0; i < SIZE; i++) {

    if (level[i].active && ballX + ballSize >= level[i].x && ballX <= level[i].x + level[i].width && ballY + ballSize >= level[i].y && ballY <= level[i].y + level[i].height) {
      level[i].active = false;
      CreateItem(level[i].x, level[i].y);
      ballSpeedY = -ballSpeedY;

      if (totalSegment < 10) {
        showNumber(totalSegment);
      } else {
        totalSegment = 1;
        one();
      }

      totalSegment++;
      total = total + 1;
      totalLevel++;

      if (totalLevel == 17) {
        totalLevel = 0;
        zero();
        delay(3000);
        activeLevel++;
        ballX = 64;
        ballY = 48;
        ballSpeedY = -ballSpeedY;
      }
    }

    if (level[i].active) {
      isLevelFinished = false;
    }
  }


  if (isLevelFinished && totalLevel != 0) {
    activeLevel++;
    ballX = 64;
    ballY = 48;
    ballSpeedY = -ballSpeedY;

    ballSpeedX = ballSpeedX * 0.2 + ballSpeedX;
    ballSpeedY = ballSpeedY * 0.2 + ballSpeedY;
  }

  if (ballY >= 63) {
    totalHeart--;
    if (totalHeart == 2) {
      digitalWrite(ledC, LOW);
      ballX = 64;
      ballY = 48;
      ballSpeedY = -ballSpeedY;
    } else if (totalHeart == 1) {
      digitalWrite(ledB, LOW);
      ballX = 64;
      ballY = 48;
      ballSpeedY = -ballSpeedY;
    } else if (totalHeart == 0) {
      digitalWrite(ledA, LOW);
      ballX = 200;
      ballY = 200;
    }
  }
}

void UpdateItem() {
  if (item.active) {
    item.y += item.speed;

    if (item.y + item.size >= pedalY && item.x >= pedalX && item.x <= pedalX + pedalWidth) {
      item.active = false;
      totalHeart++;
      UpdateLED();
    }

    if (item.y > 64) {
      item.active = false;
    }
  }
}

void DrawMenu() {
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


void Move() {

  int yeniPaletX = map(analogRead(A0), 0, 1023, 0, 128);
  pedalX = yeniPaletX;
}

void ShowMessage(const char* message, byte size) {

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x12_tr);
  u8g2.setCursor(0, 10 + size);
  u8g2.print(message);

  u8g2.sendBuffer();
}

void ShowTotal() {

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x12_tr);
  u8g2.setCursor(0, 30);
  u8g2.print(total - 1);

  u8g2.sendBuffer();

  delay(3000);
}

void StartGame() {

  while (0 < totalHeart) {

    if (activeLevel == 1) {
      u8g2.clearBuffer();
      Move();
      DrawPedal();
      DrawBall();
      DrawLevel(level1);
      UpdateBall(level1);
      UpdateItem();
      DrawItem();
      u8g2.sendBuffer();
    } else if (activeLevel == 2) {
      u8g2.clearBuffer();
      Move();
      DrawPedal();
      DrawBall();
      DrawLevel(level2);
      UpdateBall(level2);
      UpdateItem();
      DrawItem();
      u8g2.sendBuffer();
    } else if (activeLevel == 3) {
      u8g2.clearBuffer();
      Move();
      DrawPedal();
      DrawBall();
      UpdateBall(level3);
      UpdateItem();
      DrawItem();
      DrawLevel(level3);
      u8g2.sendBuffer();
    } else if (activeLevel == 4) {
      u8g2.clearBuffer();
      Move();
      DrawPedal();
      DrawBall();
      UpdateBall(level4);
      UpdateItem();
      DrawItem();
      DrawLevel(level4);
      u8g2.sendBuffer();
    } else if (activeLevel == 5) {
      u8g2.clearBuffer();
      Move();
      DrawPedal();
      DrawBall();
      UpdateBall(level5);
      UpdateItem();
      DrawItem();
      DrawLevel(level5);
      u8g2.sendBuffer();
    }

    if (totalHeart == 0) {
      ShowMessage("Game Over", 30);
      delay(2000);
      ShowTotal();

      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);

      total = 1;
      totalLevel = 1;
      totalHeart = 3;
      totalSegment = 1;
      activeLevel = 1;

      zero();

      for (int i = 0; i < SIZE; i++) {
        level1[i].active = true;
        level2[i].active = true;
        level3[i].active = true;
        level4[i].active = true;
        level5[i].active = true;
      }

      ballX = 64;
      ballY = 48;
      ballSpeedY = -ballSpeedY;

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

  pinMode(buttonUp, INPUT_PULLUP);
  pinMode(buttonDown, INPUT_PULLUP);
  pinMode(buttonSelection, INPUT_PULLUP);

  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledC, HIGH);

  zero();
  DrawPedal();
}

void loop() {

  DrawMenu();

  if (digitalRead(buttonUp) == LOW) {

    menuOption = (menuOption == 0) ? 1 : 0;
    delay(200);
  }

  if (digitalRead(buttonDown) == LOW) {

    menuOption = (menuOption == 0) ? 1 : 0;
    delay(200);
  }

  if (digitalRead(buttonSelection) == LOW) {

    if (menuOption == 0) {

      StartGame();

    } else {

      ShowMessage("Thanks for", 5);
      delay(2000);
      ShowMessage("Playing", 30);
      delay(2000);
      ShowMessage("Good bye", 40);
      while (true);
    }
  }
}