//   名字：AFMotor_R4.h
//   功能：提供方便的L293D擴充版操控給非AVR系列的Arduino開發板

//   作者：®LanFeng studios
//   時間：2024
//   版本：Official-1.1.12

//定義C Header來源檔案
#ifndef _AFMotor_R4_H__
#define _AFMotor_R4_H__

//匯入arduino核心標頭檔案
#include <Arduino.h>

#define FORWARD 0
#define BACKWARD 1
#define RELEASE 2
#define BREAK 2
#define DATA 8
#define OE 7
#define OUTT 12
#define SC 4

const int MT_PINS[4][3] =  {
                    {2, 3, 11},
                    {1, 4, 3},
                    {5, 7, 6},
                    {0, 6, 5}
                    };
extern bool HCOUT[8];
void MT_shiftOut();

class AF_DCMotor
{
private:
    int mtn;
    enum
    {
        MOTOR12_64KHZ = 1,
    };
public:
    AF_DCMotor(int mt, int MOTOR_TYPE = MOTOR12_64KHZ);
    void setSpeed(int speed);
    void run(int dir);
    void autoRun(int speed);
};


#endif