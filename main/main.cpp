#include <stdio.h>
#include "M5Unified.h"

int count = 0;

void setup() {
  auto cfg = M5.config();
  M5.begin(cfg);

  M5.Display.setRotation(3);
  M5.Display.setTextColor(WHITE);
  M5.Display.setTextSize(2);

  M5.Display.fillScreen(BLACK);
  M5.Display.setCursor(10, 20);
  M5.Display.printf("Hello world %d\n", count);
}

void loop() {
  printf("delay 1 sec.\n");
  M5.delay(1000);
  count++;

  M5.Display.fillScreen(BLACK);  
  M5.Display.setCursor(10, 20);
  M5.Display.printf("Hello world %d\n", count);
}