/*
JTAG 
ESP32-C3 NodeMCU_ESP_C3_13
IO4 TMS
IO5 TDI
IO6 TCK
IO7 TDO
ChipModel: ESP32-C3, Freq: 160, Cores: 1, Revision: 3, Flash: 4 Mbit, PSRAM: 0 Mbit
Free heap: 303652 bytes, Free PSRAM: 0 bytes

ESP32-C3-12F
GPIO20 is used as U1RXD, a pull-up resistor needs to be added externally

ESP-PROG Pin
TXO  TXD0
RX0  RXD0
IO0  IO0
EN   EN
VCC  VCC
GND  GND

IO9: pulldown 10K for program, unconnected for running

ChipModel: ESP32-C3, Freq: 160 MHz, Cores: 1, Revision: 3, Flash: 4 Mbit, PSRAM: 0 Mbit
Free heap: 303668 bytes, Free PSRAM: 0 bytes

*/
#include <Arduino.h>
#ifdef BOARD_NODEMCU_ESP_C3_13
  #define LED_RGB_RED   3
  #define LED_RGB_GREEN 4
  #define LED_RGB_BLUE  5
  #define LED_COLD      19
  #define LED_WARM      18

  #define LEDS_COUNT    5
  const uint8_t arLeds[] = {LED_RGB_RED, LED_RGB_GREEN, LED_RGB_BLUE, LED_COLD, LED_WARM};
  const char* arLedsNames[] = {"LED_RGB_RED", "LED_RGB_GREEN", "LED_RGB_BLUE", "LED_COLD", "LED_WARM"};
#elif defined(BOARD_ESP_C3_12F)
  #define LED_EXT    10
  #define LEDS_COUNT  1
  const uint8_t arLeds[] = {LED_EXT};
  const char* arLedsNames[] = {"LED_EXT"};
#endif

void setup() {
  Serial.begin(115200);
  for (uint8_t i = 0; i < LEDS_COUNT; i++) {
    pinMode(arLeds[i], OUTPUT);
  }
  Serial.println("Booting...");
  // board info
  Serial.printf("ChipModel: %s, Freq: %d MHz, Cores: %d, Revision: %d, Flash: %d Mbit, PSRAM: %d Mbit\n", 
    ESP.getChipModel(), ESP.getCpuFreqMHz(), ESP.getChipCores(), ESP.getChipRevision(), ESP.getFlashChipSize() / 1024 / 1024, ESP.getPsramSize() / 1024 / 1024);
  // print esp ram
  Serial.printf("Free heap: %d bytes, Free PSRAM: %d bytes\n", ESP.getFreeHeap(), ESP.getFreePsram());
}

void loop() {
  for (uint8_t i = 0; i < LEDS_COUNT; i++) {
    Serial.printf("LED: %s\n", arLedsNames[i]);
    digitalWrite(arLeds[i], HIGH);
    delay(50);
    digitalWrite(arLeds[i], LOW);
    delay(2950);
  }  
}