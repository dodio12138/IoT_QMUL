#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>

SoftwareSerial mySearial(3, 2);
Adafruit_GPS GPS(&mySearial);

char c;

void setup() {
  Serial.begin(9600);
  GPS.begin(9600);
  Serial.println("start print");
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);

  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
  delay(1000);
}

void loop() {
  Serial.println("start print");
  clearGPS();
  while (!GPS.newNMEAreceived()) {
    c = GPS.read();
  } 
  GPS.parse(GPS.lastNMEA());
  Serial.println("start print");
  Serial.print("Time: ");
  Serial.print(GPS.hour, DEC);
  Serial.print(':');
  Serial.print(GPS.minute, DEC);
  Serial.print(':');
  Serial.print(GPS.seconds, DEC);
  Serial.print('.');
  Serial.println(GPS.milliseconds);

  Serial.print(GPS.fix);
  Serial.println("start print");
  if (GPS.fix) {
    Serial.print("Location: ");
    Serial.print(GPS.latitude, 4);
    Serial.print(',');
    Serial.print(GPS.longitude, 4);
    Serial.print('.');
  }
}

void clearGPS() {
  while (!GPS.newNMEAreceived()) {
    c = GPS.read();
  }
  GPS.parse(GPS.lastNMEA());

  while (!GPS.newNMEAreceived()) {
    c = GPS.read();
  }
  GPS.parse(GPS.lastNMEA());
}
