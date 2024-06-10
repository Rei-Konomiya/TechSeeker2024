#include <Arduino.h>
#include "Gear.h"
#include "Handle.h"


// 上下on/off + 左右on/off

#define HANDLE_FRONT  // 前進
#define HANDLE_BACK   // 後退
#define HANDLE_LEFT   // 左折
#define HANDLE_RIGHT  // 右折

#define GEAR_PIN 17
#define GEAR_OFF 0
#define GEAR_ON 1
#define GEAR_LOW 2
#define GEAR_MEDIUM 3
#define GEAR_HIGH 4

#define BTN_KLAXON
#define BTN_LIGHT
#define BTN_DEFECATE

#define SPEAKER
#define LED
#define MOTOR
#define UNDEFINED     // 排出機構

// インスタンス作成
Gear gear(GEAR_PIN, GEAR_OFF, GEAR_ON, GEAR_LOW, GEAR_MEDIUM, GEAR_HIGH);

void setup() {
  gear.start();
}

void loop() {
  int mode = gear.get();
}