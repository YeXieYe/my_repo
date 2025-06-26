#include <Adafruit_NeoPixel.h>

#define LED_PIN 3
#define LED_COUNT 64

Adafruit_NeoPixel matrix(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);

int LedIndex(int x, int y) {
  if (y % 2 == 0) {
    return (y * 8) + x;
  } else {
    return (y * 8) + (7 - x);
  }
}

void setup() {
  matrix.begin();
  matrix.setBrightness(50);
  matrix.clear();
  matrix.show();
}

void loop() {
  static unsigned long last_effect_change_time = 0;
  static int current_effect = 0;
  const unsigned long EFFECT_DURATION = 10000;
  if (millis() - last_effect_change_time >= EFFECT_DURATION) {
    current_effect = (current_effect + 1) % 3;
    last_effect_change_time = millis();
    matrix.clear();
  }
  switch (current_effect) {
    case 0:
      for(int y=0; y<8; y++) {
        for(int x=0; x<8; x++) {
          matrix.setPixelColor(LedIndex(x, y), random(256), random(256), random(256));
        }
      }
      matrix.show();
      delay(100);
      matrix.clear();
      matrix.show();
      delay(100);
      break;
    case 1:
      static uint8_t effect2_color_index = 0;
      static const uint32_t colors[] = {
        matrix.Color(255, 0, 0),
        matrix.Color(0, 255, 0),
        matrix.Color(0, 0, 255),
        matrix.Color(255, 255, 0),
        matrix.Color(0, 255, 255),
        matrix.Color(255, 0, 255)
      };
      static const uint8_t num_colors = sizeof(colors) / sizeof(colors[0]);
      matrix.fill(colors[effect2_color_index]);
      matrix.show();
      delay(500);
      effect2_color_index = (effect2_color_index + 1) % num_colors;
      break;
    case 2:
      for(int y=0; y<8; y++) {
        for(int x=0; x<8; x++) {
          matrix.setPixelColor(LedIndex(x, y), random(256), random(256), random(256));
        }
      }
      matrix.show();
      delay(50);
      break;
  }
} 