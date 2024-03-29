#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED ekran genişliği
#define SCREEN_HEIGHT 64 // OLED ekran yüksekliği

// OLED ekran bağlantı pinleri
#define OLED_RESET    -1
#define OLED_ADDR     0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // Seri bağlantı hızı ayarla
  Serial.begin(9600);

  // OLED ekran başlatma
  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("SSD1306 ekran başlatılamadı! Bağlantıları kontrol edin."));
    for(;;);
  }

  // Ekranı temizle
  display.clearDisplay();

  // "Hello, World!" mesajını ekrana yazdır
  display.setTextSize(1);      
  display.setTextColor(SSD1306_WHITE); 
  display.setCursor(0, 0);    
  display.println("Hello, World!"); 
  display.display();
  
}

void loop() {
  // Döngüde yapılacak bir şey yok
}

Ax34   a45e
