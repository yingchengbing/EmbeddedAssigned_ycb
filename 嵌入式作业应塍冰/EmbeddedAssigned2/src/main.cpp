#include <Arduino.h>
//任务一


/*// 定义LED引脚 
const int LED1 = 27;
const int LED2 = 26;
 
// 存储LED状态的变量 
bool led1State = false;
bool led2State = false;
 
void setup() {
  // 初始化串口通信，波特率设置为9600 
  Serial.begin(9600); 
  
  // 设置LED引脚为输出模式 
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  
  // 初始关闭所有LED 
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
}
 
void loop() {
  // 检查串口是否有数据可读 
  if (Serial.available()  > 0) {
    // 读取串口数据 
    String receivedData = Serial.readStringUntil('\n'); 
    receivedData.trim();  // 去除可能的空白字符 
    
    // 处理指令 
    if (receivedData == "1") {
      digitalWrite(LED1, HIGH);
      led1State = true;
      Serial.println("LED1 ON");
    } 
    else if (receivedData == "0") {
      digitalWrite(LED1, LOW);
      led1State = false;
      Serial.println("LED1 OFF");
    }
    else if (receivedData == "2") {
      digitalWrite(LED2, HIGH);
      led2State = true;
      Serial.println("LED2 ON");
    }
    else if (receivedData == "3") {
      digitalWrite(LED2, LOW);
      led2State = false;
      Serial.println("LED2 OFF");
    }
    else if (receivedData.startsWith("led_flash1(") && receivedData.endsWith(")")) 
    {
      // 提取闪烁次数 
      String countStr = receivedData.substring(11, receivedData.length() - 1);
      int count = countStr.toInt();
      
      // 闪烁LED1 
      for (int i = 0; i < count; i++) {
        digitalWrite(LED1, HIGH);
        delay(500);
        digitalWrite(LED1, LOW);
        delay(500);
      }
      Serial.println("LED1 flashed " + String(count) + " times");
    }
    else if (receivedData.startsWith("led_flash2(") && receivedData.endsWith(")")) 
    {
      // 提取闪烁次数 
      String countStr = receivedData.substring(11, receivedData.length() - 1);
      int count = countStr.toInt();
      
      // 闪烁LED2 
      for (int i = 0; i < count; i++) {
        digitalWrite(LED2, HIGH);
        delay(500);
        digitalWrite(LED2, LOW);
        delay(500);
      }
      Serial.println("LED2 flashed " + String(count) + " times");
    }
    else {
      // 无效指令处理 
      Serial.print(" 无效指令: '");
      Serial.print(receivedData); 
      Serial.println("' ，请重新输入");
    }
  }
}*/

// 任务二：密码箱解锁系统
 
String expectedCodes[4] = {"AA", "BB", "CC", "AA"}; // 预设密码序列 
int currentStep = 0; // 当前验证步骤 
bool resetFlag = false; // 重置标志 
 
void setup() {
  Serial.begin(9600); 
}
 
void loop() {
  if (resetFlag) {
    currentStep = 0;
    resetFlag = false;
  }
  
  if (Serial.available()  > 0) {
    String receivedData = Serial.readStringUntil('\n'); 
    receivedData.trim();  // 去除首尾空白 
    
    // 验证密码 
    if (receivedData == expectedCodes[currentStep]) {
      currentStep++;
      
      // 全部验证通过 
      if (currentStep == 4) {
        Serial.println(" success!");
        currentStep = 0; // 重置验证流程 
        // 这里可以添加解锁成功的物理操作，如继电器触发 
      }
    } 
    else {
      Serial.println(" wrong code, please try again!");
      resetFlag = true; // 触发重置 
    }
  }
} 

