//#define RX 0
//#define TX 1
#define button_menue 2
#define red_dim 3
#define rx_tx_en 4
#define green_dim 5
#define blue_dim 6
#define button_up 7
#define button_down 8
#define white_dim 9
#define button_enter 10
#define wireless_en 13  //pin varies depending on version
#define Ubat_S4 A0
//#define SDA A4
//#define SCL A5
//#define RXEN_PIN A6
#define bat_meter A1  //pin varies depending on version
#include <Wire.h>
#include <EEPROM.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET LED_BUILTIN
#define SCREEN_ADRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#include <Conceptinetics.h>
byte red_value = EEPROM.read(100);
byte green_value = EEPROM.read(101);
byte blue_value = EEPROM.read(102);
byte white_value = EEPROM.read(103);
byte DMXAdressBIT8 = EEPROM.read(104);  //first 8 bit
byte DMXAdressBIT9 = EEPROM.read(105);  // last bit (9th, LSB)
byte menue_state = EEPROM.read(106);
byte DMXChannels = EEPROM.read(107);
bool num_of_channels = EEPROM.read(108);
byte farben = EEPROM.read(109);
byte fadePause = EEPROM.read(110);
byte Ape_DMX_Group = EEPROM.read(111);
int DMXAdress = 0;
float US4 = 0;
float Uges = 0;
byte r = 0;
byte g = 0;
byte b = 0;
char farbe = 'b';
//char farbe_name[1] = "NAN";
int halteZeit = 500;
unsigned long fadeZeit = 0;
boolean ersterLauf = true;
const long display_timeout = 10000;  //10s
unsigned long last_time = 0;
unsigned long actual_time = 0;
bool display_enable = 1;
DMX_Slave dmx_slave(DMXChannels);

void setup() {
  if (EEPROM.read(120) != 1) {
    EEPROM.update(100, 0);
    delay(50);
    EEPROM.update(101, 0);
    delay(50);
    EEPROM.update(102, 0);
    delay(50);
    EEPROM.write(103, 0);
    delay(50);
    EEPROM.write(104, 1);
    delay(50);
    EEPROM.write(105, 0);
    delay(50);
    EEPROM.write(106, 1);
    delay(50);
    EEPROM.write(107, 6);
    delay(50);
    EEPROM.write(108, 1);
    delay(50);
    EEPROM.write(109, 1);
    delay(50);
    EEPROM.write(110, 1);
    delay(50);
    EEPROM.write(111, 1);
    delay(50);
    EEPROM.write(120, 1);
    delay(50);
  }
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADRESS);
  delay(10);
  display.clearDisplay();
  display.display();
  pinMode(button_menue, INPUT_PULLUP);
  pinMode(red_dim, OUTPUT);
  pinMode(blue_dim, OUTPUT);
  pinMode(button_up, INPUT_PULLUP);
  pinMode(button_down, INPUT_PULLUP);
  pinMode(green_dim, OUTPUT);
  pinMode(white_dim, OUTPUT);
  pinMode(wireless_en, OUTPUT);
  pinMode(button_enter, INPUT_PULLUP);
  pinMode(Ubat_S4, INPUT);
  pinMode(rx_tx_en, OUTPUT);
  pinMode(bat_meter, OUTPUT);
  digitalWrite(bat_meter, HIGH);
  digitalWrite(red_dim, LOW);
  digitalWrite(green_dim, LOW);
  digitalWrite(blue_dim, LOW);
  digitalWrite(white_dim, LOW);
  digitalWrite(wireless_en, LOW);
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(25, 10);
  display.print("AKKU  Spot");
  display.display();
  delay(1000);
  DMXAdress = (DMXAdressBIT8 * 2) + DMXAdressBIT9;
  //dmx_slave.setStartAddress (DMXAdress); 
}

void loop() {
  if (digitalRead(button_menue) == LOW) {
    delay(200);
    menue_state++;
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
    if (menue_state > 7) {
      menue_state = 0;
    }
  }
  switch (menue_state) {
    case 0:  //DMX Adresse
      dmxMode();
      break;
    case 1:  //Ape Labs Ape DMX via WAPP & DMX
      ApeLabs();
      break;
    case 2:  //Rot Manuell
      manualRed();
      break;
    case 3:  //Grün Manuell
      manualGreen();
      break;
    case 4:  //Blau Manuell
      manualBlue();
      break;
    case 5:  //Manuell Weiß
      manualWhite();
      break;
    case 6:  //Automatik
      automatic();
      break;
    case 7:  //Farben
      farbe_menu();
      break;
    case 8:
      low_battery();
      break;
    default:
      break;
  }
  /* if (menue_state != 0)
    {
     dmx_slave.disable();
     analogWrite(red_dim, red_value);
     analogWrite(green_dim, green_value);
     analogWrite(blue_dim, blue_value);
     analogWrite(white_dim, white_value);
    }*/
  if (menue_state == 2 || menue_state == 3 || menue_state == 4 || menue_state == 5 || menue_state == 7) {
    digitalWrite(wireless_en, LOW);
    dmx_slave.disable();
    analogWrite(red_dim, red_value);
    analogWrite(green_dim, green_value);
    analogWrite(blue_dim, blue_value);
    analogWrite(white_dim, white_value);
  }
  US4 = (analogRead(Ubat_S4) * (5.0 / 1023.0));
  Uges = (US4 * 4);
  if (Uges <= 12) {
    menue_state = 8;
  }
  actual_time = millis();
  if (actual_time - last_time >= display_timeout) {
    last_time = actual_time;
    display_enable = 0;
  }
  if (display_enable == 1) {
    digitalWrite(bat_meter, HIGH);
    display.ssd1306_command(SSD1306_DISPLAYON);
    display.display();
  }
  if (display_enable == 0) {
    digitalWrite(bat_meter, LOW);
    display.ssd1306_command(SSD1306_DISPLAYOFF);
    display.display();
  }
}
