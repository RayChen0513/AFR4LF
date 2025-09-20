//   名字：AFMotor_R4.cpp
//   功能：提供方便的L293D擴充版操控給非AVR系列的Arduino開發板

//   作者：®LanFeng studios
//   時間：2024
//   版本：Official-1.1.12

//匯入arduino核心標頭檔案
#include <AFMotor_R4.h>
#include <Arduino.h>

// MT_MANAGERS::MT_MANAGERS()
// {
//     pinMode(DATA, OUTPUT);
//     pinMode(OE, OUTPUT);
//     pinMode(OUTT, OUTPUT);
//     pinMode(SC, OUTPUT);
//     for (int i = 0; i < 4; i++)
//     {
//         pinMode(MT_PINS[i][2], OUTPUT);
//     }
    
// }

bool HCOUT[8] = {
                0,  //4A
                0,  //2A
                0,  //1A
                0,  //1B
                0,  //2B
                0,  //3A
                0,  //4B
                0   //3B
                };

void MT_shiftOut()
{
    digitalWrite(OUTT, LOW);
    for (int i = 0; i < 8; i++)
    {
        digitalWrite(SC, LOW);
        digitalWrite(DATA, HCOUT[7-i]);
        digitalWrite(SC, HIGH);
    }
    digitalWrite(OUTT, HIGH);
}


AF_DCMotor::AF_DCMotor(int mt)
{
    this->mtn = mt - 1;
    pinMode(DATA, OUTPUT);
    pinMode(OE, OUTPUT);
    pinMode(OUTT, OUTPUT);
    pinMode(SC, OUTPUT);
    for (int i = 0; i < 4; i++)
    {
        pinMode(MT_PINS[i][2], OUTPUT);
    }
    MT_shiftOut();
}

void AF_DCMotor::setSpeed(int speed)
{
    analogWrite(MT_PINS[mtn][2], speed);
}

void AF_DCMotor::run(int dir)
{
    if (dir == 0)
    {
        HCOUT[MT_PINS[mtn][0]] = 1;
        HCOUT[MT_PINS[mtn][1]] = 0;
    }else if (dir == 1)
    {
        HCOUT[MT_PINS[mtn][0]] = 0;
        HCOUT[MT_PINS[mtn][1]] = 1;
    }else if (dir == 2)
    {
        HCOUT[MT_PINS[mtn][0]] = 0;
        HCOUT[MT_PINS[mtn][1]] = 0;
    }
    MT_shiftOut();
}

void AF_DCMotor::autoRun(int speed)
{
    analogWrite(MT_PINS[mtn][2], abs(speed));
    run((speed == 0 ? RELEASE : (speed < 0 ? BACKWARD : FORWARD)));
}