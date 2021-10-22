#include <Adafruit_NeoPixel.h>
#define num 16
#define pin 3
#define sec *1000

//函式初始化
void LEDSHOW(int);
int COLORSET();

unsigned int Lb = 150;
Adafruit_NeoPixel pixels = 
  Adafruit_NeoPixel(num, pin, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  pixels.setBrightness(Lb);
}

void loop() {
  static int Times = 1;
  for(int i = 0; i < num; i++) {
    switch(Times % 2) {
      case 0:
      	if(i % 2 == 1) LEDSHOW(i);
      	break;
      case 1:
      	if(i % 2 != 1) LEDSHOW(i);
      	break;
    }
  }
  Times ++;
}

void LEDSHOW(int v) {
  for(int i = 0; i < num; i++) pixels.setPixelColor(i, 0, 0, 0);
  pixels.setPixelColor(v, COLORSET(), COLORSET(), COLORSET());
  pixels.show();
  delay(1 sec);
}

int COLORSET() { return (int)random(0, 256); }