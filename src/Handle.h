#pragma once

#include <Arduino.h>

#define HANDLE_FRONT 0b0001
#define HANDLE_BACK  0b0010
#define HANDLE_LEFT  0b0100
#define HANDLE_RIGHT 0b1000
#define HANDLE_FRONT_LEFT  0b0101
#define HANDLE_FRONT_RIGHT 0b1001
#define HANDLE_BACK_LEFT   0b0110
#define HANDLE_BACK_RIGHT  0b1010

/** 
 * @class Handle
 * @brief 移動方向の操作をするスティックレバーの管理クラス
 */
class Handle{

public:
  Handle(int pin, float front, float back, float left, float right);

  void start();
  int get();

private:
  #define FRONT_BIT 0b0001
  #define BACK_BIT  0b0010
  #define LEFT_BIT  0b0100
  #define RIGHT_BIT 0b1000

  int pin;
  float front;
  float back;
  float left;
  float right;
};