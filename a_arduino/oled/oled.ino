#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED ekran genişliği
#define SCREEN_HEIGHT 64 // OLED ekran yüksekliği

#define OLED_RESET    -1 // OLED reset pini, -1 ise reset kullanılmıyor
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 başlatılamadı!"));
    for(;;);
  }

  display.display();
  delay(2000); // Ekranı 2 saniye beklet
  display.clearDisplay();
}

void loop() {
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Merhaba, Dunya!");

  display.display();
  delay(1000); // 1 saniye beklet
  display.clearDisplay();
}

