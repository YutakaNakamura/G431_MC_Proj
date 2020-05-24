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




#endif /* SYSTEM_INC_MOTORCTRLDEFPACK_HPP_ */
