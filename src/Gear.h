#pragma once

#include <Arduino.h>

#define GEAR_OFF     0
#define GEAR_DRIVE   1
#define GEAR_LOW     2
#define GEAR_MEDIUM  3
#define GEAR_HIGH    4

/** 
 * @class Gear
 * @brief 前後するギアチェンジレバーの管理クラス
 */
class Gear {
public:
  Gear(int pin, float off, float drive, float low, float medium, float high);

  void start();
  int get();

private:
  int pin;
  float off;
  float drive;
  float low;
  float medium;
  float high;
};