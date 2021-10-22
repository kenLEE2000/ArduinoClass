#include <Adafruit_NeoPixel.h>
#define num 16
#define pin 3
#define sec *1000

//函式初始化
void LEDSHOW(int);
int COLORSET();
void resetSerial();

int colorledid[16] = {0};
unsigned int Lb = 150;
Adafruit_NeoPixel pixels = 
  Adafruit_NeoPixel(num, pin, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  pixels.begin();
  pixels.setBrightness(Lb);
  resetSerial();
}

void loop() {
  static int Times = 1;
  for(int i = 0; i < num; i++) {
    resetSerial();
    colorledid[i] = 1;
    LEDSHOW(i);
  }
  Times ++;
}

void LEDSHOW(int v) {
  for(int i = 0; i < num; i++) pixels.setPixelColor(i, 0, 0, 0);
  pixels.setPixelColor(v, COLORSET(), COLORSET(), COLORSET());
  pixels.show();
  for(int i : colorledid) Serial.print(i);
  
  Serial.print("\n");
  delay(1 sec);
}

int COLORSET() { return (int)random(0, 256); }

void resetSerial() {
  for(int i = 0; i < num; i++) colorledid[i]=0;
}
