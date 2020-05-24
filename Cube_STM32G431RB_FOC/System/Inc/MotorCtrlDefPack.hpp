/*
 * MotorCtrlDefPack.hpp
 *
 *  Created on: 2020/05/23
 *      Author: watashi
 */

#ifndef SYSTEM_INC_MOTORCTRLDEFPACK_HPP_
#define SYSTEM_INC_MOTORCTRLDEFPACK_HPP_

//system Init
constexpr int ProcessorClock = 170000000;
constexpr int TimerClock = ProcessorClock;

//pwm
constexpr int PWMFreq = 20000;
constexpr int PWMCounter = TimerClock/PWMFreq/2;

//controller
constexpr int ControllerSamplingFreq = PWMFreq;
constexpr float ControllerSamplingTime = (float)1/(float)ControllerSamplingFreq;


//ボードの I -> V 倍率
//(Rの配置及び計算式についてはPDF参照)
constexpr float BoardOffsetVCCVoltage = 3.3;
constexpr float BoardOpampR1 = 2200;
constexpr float BoardOpampR2 = 2200;
constexpr float BoardOpampR3 = 680;
constexpr float BoardOpampR4 = 2200;
constexpr float BoardShuntR = 0.33;

constexpr float BoardIVRatio = ( 1.0f / BoardShuntR ) * ( BoardOpampR1 / ( BoardOpampR1 + BoardOpampR2 ) ) * ( ( BoardOpampR3 + BoardOpampR4 ) / (BoardOpampR4 ) );
constexpr float BoardIVOffset = ( -1.0f * ( 1.0f / BoardShuntR ) * ( BoardOpampR3 / BoardOpampR4 ) * BoardOffsetVCCVoltage );

constexpr float ADCVoltageRatio = 3.3/(float)4096;

//ボードのVBus計算
constexpr float VBusR1 = 169000;
constexpr float VBusR2 = 9310;

//モータのパラメータ設定
//Ld=0.02[mH]
//Lq=0.02[mH]
//phi=0.8
constexpr float MotorParamLd = 0.00002f;
constexpr float MotorParamLq = 0.00002f;
constexpr float MotorParamPhy = 0.0008f;
constexpr float MotorParamR = 0.26f;



#endif /* SYSTEM_INC_MOTORCTRLDEFPACK_HPP_ */
