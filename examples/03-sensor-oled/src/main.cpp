/**
 * 示例 03：传感器数据 + OLED 显示
 *
 * 功能：读取温湿度传感器 (DHT20) 和光线传感器 (A6)，在 OLED 上实时显示
 * 概念：多传感器输入 → 数据处理 → 屏幕输出
 */

#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
#include <DHT20.h>

// OLED 显示屏初始化（I2C，地址 0x3C）
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

// DHT20 温湿度传感器
DHT20 dht;

// 光线传感器引脚
const int LIGHT_PIN = A6;

// 刷新间隔
unsigned long lastUpdate = 0;
const unsigned long UPDATE_INTERVAL = 2000;  // 每 2 秒刷新

void setup() {
    Serial.begin(9600);

    // 初始化 OLED
    u8g2.begin();
    u8g2.setFont(u8g2_font_6x13_tf);

    // 初始化 DHT20
    Wire.begin();
    dht.begin();

    Serial.println("传感器 + OLED 示例启动");

    // 显示启动画面
    u8g2.clearBuffer();
    u8g2.drawStr(10, 30, "Sensor + OLED");
    u8g2.drawStr(10, 50, "Starting...");
    u8g2.sendBuffer();
    delay(1000);
}

void loop() {
    unsigned long now = millis();

    if (now - lastUpdate >= UPDATE_INTERVAL) {
        lastUpdate = now;

        // 读取 DHT20
        dht.read();
        float temp = dht.getTemperature();
        float humi = dht.getHumidity();

        // 读取光线值
        int light = analogRead(LIGHT_PIN);

        // 串口输出
        Serial.print("温度: "); Serial.print(temp, 1); Serial.print(" C  ");
        Serial.print("湿度: "); Serial.print(humi, 1); Serial.print(" %  ");
        Serial.print("光线: "); Serial.println(light);

        // OLED 显示
        u8g2.clearBuffer();

        // 标题
        u8g2.drawStr(0, 12, "== Sensor Data ==");

        // 温度
        char tempStr[20];
        snprintf(tempStr, sizeof(tempStr), "Temp: %.1f C", temp);
        u8g2.drawStr(0, 28, tempStr);

        // 湿度
        char humiStr[20];
        snprintf(humiStr, sizeof(humiStr), "Humi: %.1f %%", humi);
        u8g2.drawStr(0, 42, humiStr);

        // 光线
        char lightStr[20];
        snprintf(lightStr, sizeof(lightStr), "Light: %d", light);
        u8g2.drawStr(0, 56, lightStr);

        u8g2.sendBuffer();
    }
}
