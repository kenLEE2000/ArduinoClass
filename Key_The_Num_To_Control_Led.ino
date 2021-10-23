#include <Adafruit_NeoPixel.h>                                    //LED燈串控制Class頭檔
#define num 16
#define pin 3

void LEDSHOW(int);                                                //宣告LED閃爍函式
void LEDSHUTDOWN();                                               //宣告LED全熄函式
int COLORSET();                                                   //宣告顏色設置函式
void resetSerial();                                               //宣告序列埠輸出重設函式

int colorledid[16] = {0};                                         //設置Led編號
unsigned int Lb = 150;                                            //設置亮度
Adafruit_NeoPixel pixels(num, pin, NEO_GRB + NEO_KHZ800);         //定義Led燈串控制物件
/*======================================================*\
 [建構式參數]                          
 第一個參數：設置LED燈數量                    
 第二個參數：設置輸入腳位                     
 第三個參數：LED類型旗標Flag                     
\*======================================================*/

void setup() {
  Serial.begin(9600);
  pixels.begin();                                                 //啟動Led燈串控制物件
  pixels.setBrightness(Lb);                                       //設置明亮度
}

void loop() {
  if(Serial.available() > 0) {                                    //若接收的位元組數量大於0，有接收
    int i = Serial.readString().toInt();                          //接收的訊息以字串表示在轉換成整數
    if(i >= 0 && i < num) LEDSHOW(i);                             //若輸入值範圍：0（包含）～16，則讓燈亮並顯示訊息
    else Serial.println("Values error");                          //否則錯誤
    delay(1000);
    resetSerial();
  }
}

void LEDSHOW(int v) {
  LEDSHUTDOWN();
  pixels.setPixelColor(v, COLORSET(), COLORSET(), COLORSET());    //設置該那顆Led的顏色
  pixels.show();                                                  //顯示那顆Led燈
  colorledid[v] = !colorledid[v];                                 //將那顆Led燈訊息設為顛倒，true = 1, false = 0
  for(int i : colorledid) Serial.print(i);                        //將所有Led燈訊息顯示出來
                                                                  //也可以寫成：
                                                                  //for(int i = 0; i < num; i++) 
                                                                  //   Serial.print(colorledid[i]);
  
  Serial.print('\n');                                             //顯示完後換行 '\n' 為換行的跳逸字元
  delay(1000);
}

int COLORSET() {
  return (int)random(0, 256); 
}

void resetSerial() {
  for(int i = 0; i < num; i++) colorledid[i] = 0;
}

void LEDSHUTDOWN() {
  for(int i = 0; i < num; i++) pixels.setPixelColor(i, 0, 0, 0);   //R, G, B 值為零為黑色，代表Led燈不亮
}