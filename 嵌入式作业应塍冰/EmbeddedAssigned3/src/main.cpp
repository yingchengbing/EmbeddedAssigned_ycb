
//OLED屏幕显示文字

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define OLED_RESET -1 
 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
 
void setup() {
  Serial.begin(9600); 
  
  if(!display.begin(SSD1306_SWITCHCAPVCC,  0x3C)) {
    Serial.println(F("OLED 分配失败"));
    for(;;);
  }
  
  display.display();  // 显示Adafruit启动画面 
  delay(2000);
  display.clearDisplay();  // 清屏 
}
 
void displayTextDemo() {
  display.clearDisplay(); 
  
  // 设置文本参数 
  display.setTextSize(1);       // 字体大小1-8 
  display.setTextColor(SSD1306_WHITE);  // 颜色模式 
  
  // 显示静态文本 
  display.setCursor(0,  0);     // 设置起始坐标(x,y)
  display.println("hzx:my love!"); 
  
  // 显示动态数据 
  display.setCursor(0,  16);
  display.print(" date: ");
  display.print("2025/13/14"); 

  
  // 大字体显示 
  display.setTextSize(2); 
  display.setCursor(0,  48);
  display.print("05:20"); 
  
  display.display();  // 必须调用才会更新屏幕 
}
void loop() {
  displayTextDemo();
  delay(3000);
}



/*OLED屏幕显示图片
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "bmp.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 OLED(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); // 使用 I2C 接口

void setup() {
  Serial.begin(115200);
  Wire.begin(21,22); // SDA, SCL 引脚
 OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C); // I2C 地址为 0x3C
 OLED.clearDisplay();
 OLED.setCursor(1,1);// 设置光标位置
 OLED.setTextSize(1); // 设置字体大小
 OLED.setTextColor(SSD1306_WHITE); // 设置字体颜色
 delay(1000); // 延时 1 秒
 OLED.drawBitmap(0, 0, BMP_1, 128, 64, SSD1306_WHITE); // 显示图片
 OLED.display(); // 刷新显示
 randomSeed(analogRead(0)); // 初始化随机数种子
}
void loop() {
  // 在这里可以添加其他代码
  delay(10000); // 延时 10 秒
}*/