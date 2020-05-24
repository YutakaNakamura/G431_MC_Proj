/*
 * ConvertADCtoCurrent.hpp
 *
 *  Created on: 2020/05/24
 *      Author: watashi
 */

#ifndef MOTOR_INC_CONVERTADCTOCURRENT_HPP_
#define MOTOR_INC_CONVERTADCTOCURRENT_HPP_

#include "MotorCtrlDefPack.hpp"

template<typename T>
class ConvertADCtoCurrent {
public:
	ConvertADCtoCurrent(){};
	~ConvertADCtoCurrent(){};
	constexpr T Current(T pADCVal){
		T output = pADCVal * BoardIVRatio * ADCVoltageRatio + BoardIVOffset;
		output = -output;
		return output;
	};



};

#endif /* MOTOR_INC_CONVERTADCTOCURRENT_HPP_ */
