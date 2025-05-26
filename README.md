# Mikrodenetleyici Oyun Makinesi

Bu proje, Arduino tabanlı bir oyun makinesi uygulamasıdır. Klasik bir "Breakout" tarzı oyunu OLED ekran üzerinde oynatabilirsiniz.

## Özellikler

- 128x64 OLED ekran desteği
- 5 farklı oyun seviyesi
- 7-segment display ile skor gösterimi
- LED göstergeler ile can sistemi
- Potansiyometre ile kontrol edilebilen ped
- Menü sistemi
- Bonus item sistemi

## Donanım Gereksinimleri

- Arduino (Uno veya benzeri)
- SSD1306 128x64 OLED ekran
- 3 adet LED
- 7-segment display
- Potansiyometre
- 3 adet buton (Yukarı, Aşağı, Seçim)
- Bağlantı kabloları

## Bağlantılar

### OLED Ekran
- SDA ve SCL pinleri Arduino'nun I2C pinlerine bağlanır

### LED'ler
- LED A: Pin 11
- LED B: Pin 12
- LED C: Pin 13

### Butonlar
- Seçim Butonu: Pin 22
- Yukarı Butonu: Pin 23
- Aşağı Butonu: Pin 24

### 7-Segment Display
- Pin 2-8 arası bağlantılar

### Potansiyometre
- Analog Pin A0

## Oyun Özellikleri

1. **Menü Sistemi**
   - Başlangıç menüsünde "Start" ve "Exit" seçenekleri
   - Butonlar ile menü navigasyonu

2. **Oyun Mekanikleri**
   - Ped ile top kontrolü
   - Blokları kırma puanı
   - Can sistemi (3 can)
   - Bonus item'lar ile ekstra can kazanma

3. **Seviyeler**
   - 5 farklı zorluk seviyesi
   - Her seviyede farklı blok düzenleri
   - Seviye geçişlerinde artan zorluk

4. **Skor Sistemi**
   - 7-segment display ile anlık skor gösterimi
   - Oyun sonu toplam skor gösterimi

## Kurulum

1. Gerekli kütüphaneleri yükleyin:
   - U8g2lib

2. Donanım bağlantılarını yapın
3. Kodu Arduino'ya yükleyin

## Oyun Kontrolleri

- Potansiyometre ile ped kontrolü
- Menüde yukarı/aşağı butonları ile seçim
- Seçim butonu ile onay


# Microcontroller Game Machine

This project is an Arduino-based game machine application. You can play a classic "Breakout" style game on an OLED display.

## Features

- 128x64 OLED display support
- 5 different game levels
- Score display with 7-segment display
- Life system with LED indicators
- Paddle control with potentiometer
- Menu system
- Bonus item system

## Hardware Requirements

- Arduino (Uno or similar)
- SSD1306 128x64 OLED display
- 3 LEDs
- 7-segment display
- Potentiometer
- 3 buttons (Up, Down, Select)
- Connection cables

## Connections

### OLED Display
- SDA and SCL pins connect to Arduino's I2C pins

### LEDs
- LED A: Pin 11
- LED B: Pin 12
- LED C: Pin 13

### Buttons
- Select Button: Pin 22
- Up Button: Pin 23
- Down Button: Pin 24

### 7-Segment Display
- Connections between pins 2-8

### Potentiometer
- Analog Pin A0

## Game Features

1. **Menu System**
   - "Start" and "Exit" options in the main menu
   - Menu navigation with buttons

2. **Game Mechanics**
   - Paddle control with potentiometer
   - Block breaking points
   - Life system (3 lives)
   - Extra lives with bonus items

3. **Levels**
   - 5 different difficulty levels
   - Different block arrangements in each level
   - Increasing difficulty between levels

4. **Score System**
   - Real-time score display with 7-segment display
   - End game total score display

## Installation

1. Install required libraries:
   - U8g2lib

2. Make hardware connections
3. Upload code to Arduino

## Game Controls

- Paddle control with potentiometer
- Menu selection with up/down buttons
- Confirmation with select button 