#include  <Adafruit_NeoPixel.h> //載入LED全彩燈的驅動函式庫
#define   PIN       2   // 定義之後LED燈號訊號線的接腳號碼
#define   NUMPIXELS      4    //LED燈泡的數量
unsigned int brightness=255;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(4,2, NEO_GRB + NEO_KHZ800);

String num;
int status[] = {0,0,0,0};
int inches = 0;
int cm = 0;
int i=0;
int red=0;
int green=0;
int blue=0;
long readUltrasonicDistance(int triggerPin, int echoPin)
{     
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pixels.begin();     //啟用pixel 告知驅動程式要開始使用LED了
  Serial.begin(9600); //啟用序列埠 準備可以傳輸資料
  Serial.setTimeout(10); // 設定為每10毫秒結束一次讀取(數字愈小愈快
  pixels.setBrightness(brightness);
}

void loop()
{
  // measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(4, 5);
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");
  delay(100); // Wait for 100 millisecond(s)
 
 
  int num =0;
  if(cm>50){num=1;
  pixels.setPixelColor(num, pixels.Color(255, 125, 0));
  pixels.setPixelColor(num-1, pixels.Color(255, 125, 0));
  pixels.show();
  }
  else if (cm>25){num=2;
  pixels.setPixelColor(num, pixels.Color(255, 125, 0));
  pixels.setPixelColor(num-1, pixels.Color(255, 125, 0));
  pixels.setPixelColor(num-2, pixels.Color(255, 125, 0));
  pixels.show();}
  else if (cm>10){num=3;
  pixels.setPixelColor(num, pixels.Color(255, 125, 0));
  pixels.setPixelColor(num-1, pixels.Color(255, 125, 0));
  pixels.setPixelColor(num-2, pixels.Color(255, 125, 0));
  pixels.setPixelColor(num-3, pixels.Color(255, 125, 0));
  pixels.show();}
  else if (cm>5){num=4 ;
  pixels.setPixelColor(num, pixels.Color(255, 125, 0));
  pixels.setPixelColor(num-1, pixels.Color(255, 125, 0));
  pixels.setPixelColor(num-2, pixels.Color(255, 125, 0));
  pixels.setPixelColor(num-3, pixels.Color(255, 125, 0));
  pixels.setPixelColor(num-4, pixels.Color(255, 125, 0));
  pixels.show();}
  else if(cm=cm){}
//    for(int num=0;num<=4;num++)
  //pixels.setPixelColor(num, pixels.Color(120,0,0));
 //pixels.show();}
  else num=0;
     //   for(int num=0;num<=4;num++)
//    {  
  
  
  delay(1000);
  pixels.setPixelColor(num, pixels.Color(0, 0, 0));
  pixels.show();
//  }
 
    
    
}
void color()
{
  red=random(0,255);
  green=random(0,255);
  blue=random(0,255);
  }
