/*
 * MotorController.hpp
 *
 *  Created on: 2020/05/23
 *      Author: watashi
 */

#ifndef MOTOR_INC_MOTORCONTROLLER_HPP_
#define MOTOR_INC_MOTORCONTROLLER_HPP_

#include <array>

#include "MotorCtrlDefPack.hpp"

#include "HighFreqVoltageCommander.hpp"

template<typename T>
class MotorController {
private:

	HighFreqVoltageCommander<T> mHFVC;
	DiscreteTimeIntegrator<T> mIntegrator;

public:
	MotorController();
	virtual ~MotorController();

	std::array<T, 3> Calculate(const T &pVBus, const std::array<T, 3> &pIuvw, const T &pInputTarget, const T &pInputREV);
};


#include "details_MotorController.hpp"


#endif /* MOTOR_INC_MOTORCONTROLLER_HPP_ */
