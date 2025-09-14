#include <Adafruit_NeoPixel.h>

#define LED_PIN 3
#define LED_COUNT 64
#define W 8
#define H 8

Adafruit_NeoPixel leds(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);

inline uint16_t xyToIndex(uint8_t x, uint8_t y) {
  if (y % 2 == 0) {
    return y * W + (W - 1 - x);
  } else {
    return y * W + x;
  }
}

inline void setXY(uint8_t x, uint8_t y, uint32_t c) {
  if (x < W && y < H) {
    leds.setPixelColor(xyToIndex(x, y), c);
  }
}

const float AMP = 1.0f;
const float WAVELEN = 1.6f;
const float SPEED = 0.06f;
const float X_SCALE = 1.4f;
const uint8_t FPS = 25;
const uint16_t FRAME_INTERVAL = 1000 / FPS;
const uint8_t H_WHITE = 2;
const uint8_t H_BLUE = 3;
const uint8_t H_RED = 3;
uint32_t C_WHITE, C_BLUE, C_RED;
unsigned long lastFrame = 0;
float phase = 0.0f;

void setup() {
  leds.begin();
  leds.setBrightness(60);
  leds.clear();
  leds.show();
  C_WHITE = leds.Color(255, 255, 255);
  C_BLUE  = leds.Color(0, 0, 255);
  C_RED   = leds.Color(0, 255, 0);
}

void loop() {
  unsigned long now = millis();
  if (now - lastFrame < FRAME_INTERVAL) {
    return;
  }
  lastFrame = now;
  phase += SPEED;
  leds.clear();
  for (uint8_t y = 0; y < H; y++) {
    for (uint8_t x = 0; x < W; x++) {
      float offset = AMP * sinf((float)x * X_SCALE / WAVELEN + phase);
      float yy = (float)y + offset;
      uint32_t color;
      if (yy < H_WHITE) {
        color = C_WHITE;
      } else if (yy < H_WHITE + H_BLUE) {
        color = C_BLUE;
      } else {
        color = C_RED;
      }
      setXY(x, y, color);
    }
  }
  leds.show();
}