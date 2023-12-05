#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

static const int RXPin = 20, TXPin = 21;
static const uint32_t GPSBaud = 4800;

#define time_delay 2000
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ 9, /* data=*/ 8); 

// The TinyGPSPlus object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

int a;

void setup() {
  u8g2.begin();

  Serial.begin(115200);
  ss.begin(GPSBaud);
  a = 0;
}

void loop() {
  u8g2.sendBuffer();
  u8g2.clearBuffer();
  u8g2_prepare();
  a += 1;
  char b = char(a);
  u8g2.drawStr(80, 0, &b);
  u8g2_GPS_data(gps.location.lat(), gps.location.lng());
  printDateTime(gps.time);
  smartDelay(1000);

  if (millis() > 5000 && gps.charsProcessed() < 10)
    u8g2_No_GPS_data();
  
  u8g2.sendBuffer();
}

static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
}

void u8g2_prepare(void) {
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setFontRefHeightExtendedText();
  u8g2.setDrawColor(1);
  u8g2.setFontPosTop();
  u8g2.setFontDirection(0);
}

void u8g2_No_GPS_data() {
  u8g2.drawStr(0, 30, "No GPS data received");
}

void u8g2_GPS_data(float lat, float lng) {
  u8g2.drawStr(0, 0,"Lat: ");
  char buffer1[10];
  dtostrf(lat, 6, 3, buffer1);
  u8g2.drawStr(25,0,buffer1);
  u8g2.drawStr(0, 10,"Lng: ");
  char buffer2[10];
  dtostrf(lng, 6, 3, buffer2);
  u8g2.drawStr(25,10,buffer2);
}

static void printDateTime(TinyGPSTime &t)
{ 
  if (!t.isValid())
  {
    u8g2.drawStr(0, 20,"******");;
  }
  else
  {
    char sz[32];
    sprintf(sz, "%02d:%02d:%02d ", t.hour(), t.minute(), t.second());
    u8g2.drawStr(0, 20,"Time: ");
    u8g2.drawStr(36, 20, sz);
  }
  smartDelay(0);
}