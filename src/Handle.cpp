#include "Handle.h"


/** @fn
 * @brief コンストラクタ、しきい値やピン番号の設定
 * 
 * @param pin     ピン番号
 * @param front   前 のしきい値
 * @param back    後 のしきい値
 * @param left    左 のしきい値
 * @param right   右 のしきい値
 */
Handle::Handle(int pin, float front, float back, float left, float right)
:pin(pin), front(front), back(back), left(left), right(right) {}

/** @fn
 * @brief pinModeの設定、setup関数内で呼び出す
 */
void Handle::start(){ pinMode(pin, ANALOG); }

/** @fn
 * @brief 値をアナログ値で取得し判別、方向は重複を考慮してbitで返す
 * @return 方向を示す値
 */
int Handle::get(){
  int param = 0;
  int data[] = {FRONT_BIT, BACK_BIT, LEFT_BIT, RIGHT_BIT};
  float thresholds[] = {front, back, left, right};
  for(int i=0; i<4; i++){
    if(analogRead(pin) >= thresholds[i]) param += data[i];
  }
  return param;
}