#include <FastLED.h>
#define NUM_LEDS 64
#define DATA_PIN 7

char s;

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  Serial.println("resetting");
  LEDS.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  LEDS.setBrightness(84);
}

void fadeall() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].nscale8(250);
  }
}

void loop() {
  if (Serial.available() > 0) {
    static uint8_t hue = 0;
    s = Serial.read();
    if (s == 'Y') {
      for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CHSV(hue++, 255, 255);
        FastLED.show();
        fadeall();
        delay(10);
      }
    }
    if (s == 'Z')  {
      static uint8_t hue = 0;
      for (int i = (NUM_LEDS) - 1; i >= 0; i--) {
        leds[i] = CHSV(hue++, 255, 255);
        FastLED.show();
        fadeall();
        delay(10);
      }
    }
    if (s == 'A')  {
      static uint8_t hue = 0;
      for (int i = 0; i < 150; i++) {
      fadeall();
      }
        leds[0] = CHSV(10, 255, 255);
        leds[1] = CHSV(10, 255, 255);
        
        leds[8] = CHSV(10, 255, 255);
        leds[9] = CHSV(10, 255, 255);
        FastLED.show();
        delay(10);
      }
      if (s == 'B')  {
      static uint8_t hue = 0;
      for (int i = 0; i < 150; i++) {
      fadeall();
      }
        leds[2] = CHSV(20, 255, 255);
        leds[3] = CHSV(20, 255, 255);
        
        leds[10] = CHSV(20, 255, 255);
        leds[11] = CHSV(20, 255, 255);
        FastLED.show();
        delay(10);
      }
      if (s == 'C')  {
      static uint8_t hue = 0;
      for (int i = 0; i < 150; i++) {
      fadeall();
      }
        leds[4] = CHSV(30, 255, 255);
        leds[5] = CHSV(30, 255, 255);
        
        leds[12] = CHSV(30, 255, 255);
        leds[13] = CHSV(30, 255, 255);
        FastLED.show();
        delay(10);
      }
      if (s == 'D')  {
      static uint8_t hue = 0;
      for (int i = 0; i < 150; i++) {
      fadeall();
      }
        leds[6] = CHSV(40, 255, 255);
        leds[7] = CHSV(40, 255, 255);
        
        leds[14] = CHSV(40, 255, 255);
        leds[15] = CHSV(40, 255, 255);
        FastLED.show();
        delay(10);
      }
      if (s == 'E')  {
      static uint8_t hue = 0;
      for (int i = 0; i < 150; i++) {
      fadeall();
      }
        leds[16] = CHSV(50, 255, 255);
        leds[17] = CHSV(50, 255, 255);
        
        leds[24] = CHSV(50, 255, 255);
        leds[25] = CHSV(50, 255, 255);
        FastLED.show();
        delay(10);
      }
      if (s == 'F')  {
      static uint8_t hue = 0;
      for (int i = 0; i < 150; i++) {
      fadeall();
      }
        leds[18] = CHSV(60, 255, 255);
        leds[19] = CHSV(60, 255, 255);
        
        leds[26] = CHSV(60, 255, 255);
        leds[27] = CHSV(60, 255, 255);
        FastLED.show();
        delay(10);
      }
      if (s == 'G')  {
      static uint8_t hue = 0;
      for (int i = 0; i < 150; i++) {
      fadeall();
      }
        leds[20] = CHSV(70, 255, 255);
        leds[21] = CHSV(70, 255, 255);
        
        leds[28] = CHSV(70, 255, 255);
        leds[29] = CHSV(70, 255, 255);
        FastLED.show();
        delay(10);
      }
      if (s == 'H')  {
      static uint8_t hue = 0;
      for (int i = 0; i < 150; i++) {
      fadeall();
      }
        leds[22] = CHSV(80, 255, 255);
        leds[23] = CHSV(80, 255, 255);
        
        leds[30] = CHSV(80, 255, 255);
        leds[31] = CHSV(80, 255, 255);
        FastLED.show();
        delay(10);
      }
      if (s == 'I')  {
      static uint8_t hue = 0;
      for (int i = 0; i < 150; i++) {
      fadeall();
      }
        leds[32] = CHSV(90, 255, 255);
        leds[33] = CHSV(90, 255, 255);
        
        leds[40] = CHSV(90, 255, 255);
        leds[41] = CHSV(90, 255, 255);
        FastLED.show();
        delay(10);
      }
      if (s == 'J')  {
      static uint8_t hue = 0;
      for (int i = 0; i < 150; i++) {
      fadeall();
      }
        leds[34] = CHSV(100, 255, 255);
        leds[35] = CHSV(100, 255, 255);
        
        leds[42] = CHSV(100, 255, 255);
        leds[43] = CHSV(100, 255, 255);
        FastLED.show();
        delay(10);
      }
      if (s == 'K')  {
      static uint8_t hue = 0;
      for (int i = 0; i < 150; i++) {
      fadeall();
      }
        leds[36] = CHSV(110, 255, 255);
        leds[37] = CHSV(110, 255, 255);
        
        leds[44] = CHSV(110, 255, 255);
        leds[45] = CHSV(110, 255, 255);
        FastLED.show();
        delay(10);
      }
      if (s == 'L')  {
      static uint8_t hue = 0;
      for (int i = 0; i < 150; i++) {
      fadeall();
      }
        leds[38] = CHSV(120, 255, 255);
        leds[39] = CHSV(120, 255, 255);
        
        leds[46] = CHSV(120, 255, 255);
        leds[47] = CHSV(120, 255, 255);
        FastLED.show();
        delay(10);
      }
      if (s == 'M')  {
      static uint8_t hue = 0;
      for (int i = 0; i < 150; i++) {
      fadeall();
      }
        leds[48] = CHSV(130, 255, 255);
        leds[49] = CHSV(130, 255, 255);
        
        leds[56] = CHSV(130, 255, 255);
        leds[57] = CHSV(130, 255, 255);
        FastLED.show();
        delay(10);
      }
      if (s == 'N')  {
      static uint8_t hue = 0;
      for (int i = 0; i < 150; i++) {
      fadeall();
      }
        leds[50] = CHSV(140, 255, 255);
        leds[51] = CHSV(140, 255, 255);
        
        leds[58] = CHSV(140, 255, 255);
        leds[59] = CHSV(140, 255, 255);
        FastLED.show();
        delay(10);
      }
      if (s == 'O')  {
      static uint8_t hue = 0;
      for (int i = 0; i < 150; i++) {
      fadeall();
      }
        leds[52] = CHSV(150, 255, 255);
        leds[53] = CHSV(150, 255, 255);
        
        leds[60] = CHSV(150, 255, 255);
        leds[61] = CHSV(150, 255, 255);
        FastLED.show();
        delay(10);
      }
      if (s == 'P')  {
      static uint8_t hue = 0;
      for (int i = 0; i < 150; i++) {
      fadeall();
      }
        leds[54] = CHSV(160, 255, 255);
        leds[55] = CHSV(160, 255, 255);
        
        leds[62] = CHSV(160, 255, 255);
        leds[63] = CHSV(160, 255, 255);
        FastLED.show();
        delay(10);
      }
      if (s == 'X')  {
      static uint8_t hue = 0;
      for (int i = 0; i < 150; i++) {
      fadeall();
      }
      for (int j = 0; j < 8; j++) {
        leds[j] = CHSV(250, 255, 255);
        leds[56 + j] = CHSV(250, 255, 255);
        leds[j * 8] = CHSV(250, 255, 255);
        leds[j * 8 + 7] = CHSV(250, 255, 255);
      }
      FastLED.show();
      
          delay(80);
      
      for (int j = 0; j < 6; j++) {
        leds[j + 9] = CHSV(210, 255, 255);
        leds[49 + j] = CHSV(210, 255, 255);
        leds[9 + j * 8] = CHSV(210, 255, 255);
        leds[j * 8 + 14] = CHSV(210, 255, 255);
      }
      FastLED.show();
      
          delay(80);
      
      for (int j = 0; j < 4; j++) {
        leds[j + 18] = CHSV(170, 255, 255);
        leds[42 + j] = CHSV(170, 255, 255);
        leds[18 + j * 8] = CHSV(170, 255, 255);
        leds[j * 8 + 21] = CHSV(170, 255, 255);
      }
      FastLED.show();
      
          delay(80);
      
        leds[27] = CHSV(110, 255, 255);
        leds[28] = CHSV(110, 255, 255);
        leds[35] = CHSV(110, 255, 255);
        leds[36] = CHSV(110, 255, 255);
      FastLED.show();

      for (int k = 0; k < 150; k++) {
        for (int j = 0; j < 6; j++) {
          leds[j + 9] = CHSV(210, 255, 255);
          leds[49 + j] = CHSV(210, 255, 255);
          leds[9 + j * 8] = CHSV(210, 255, 255);
          leds[j * 8 + 14] = CHSV(210, 255, 255);
        }
        for (int j = 0; j < 4; j++) {
          leds[j + 18] = CHSV(170, 255, 255);
          leds[42 + j] = CHSV(170, 255, 255);
          leds[18 + j * 8] = CHSV(170, 255, 255);
          leds[j * 8 + 21] = CHSV(170, 255, 255);
        }
        leds[27] = CHSV(110, 255, 255);
        leds[28] = CHSV(110, 255, 255);
        leds[35] = CHSV(110, 255, 255);
        leds[36] = CHSV(110, 255, 255);
        FastLED.show();
        fadeall();
      }

            delay(60);
      
      for (int k = 0; k < 150; k++) {
        for (int j = 0; j < 4; j++) {
          leds[j + 18] = CHSV(170, 255, 255);
          leds[42 + j] = CHSV(170, 255, 255);
          leds[18 + j * 8] = CHSV(170, 255, 255);
          leds[j * 8 + 21] = CHSV(170, 255, 255);
        }
        leds[27] = CHSV(110, 255, 255);
        leds[28] = CHSV(110, 255, 255);
        leds[35] = CHSV(110, 255, 255);
        leds[36] = CHSV(110, 255, 255);
        FastLED.show();
        fadeall();
        }

            delay(60);
      
      for (int k = 0; k < 150; k++) {
        leds[27] = CHSV(110, 255, 255);
        leds[28] = CHSV(110, 255, 255);
        leds[35] = CHSV(110, 255, 255);
        leds[36] = CHSV(110, 255, 255);
        FastLED.show();
        fadeall();
        }
      
      for (int j = 0; j < 4; j++) {
        delay(140);
        leds[27] = CHSV(110, 255, 255);
        leds[28] = CHSV(110, 255, 255);
        leds[35] = CHSV(110, 255, 255);
        leds[36] = CHSV(110, 255, 255);
        FastLED.show();
        delay(140);
        for (int l = 0; l < 150; l++) {
          fadeall();
        }
        FastLED.show();
      }
    }
  }
}
