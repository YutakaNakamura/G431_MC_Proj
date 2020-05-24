/*
 * details_MotorController.hpp
 *
 *  Created on: 2020/05/24
 *      Author: watashi
 */

#ifndef MOTOR_INC_DETAILS_MOTORCONTROLLER_HPP_
#define MOTOR_INC_DETAILS_MOTORCONTROLLER_HPP_


/*
 * MotorController.cpp
 *
 *  Created on: 2020/05/23
 *      Author: watashi
 */

#include "MotorController.hpp"

#include "MotorMath.hpp"

template <typename T>
MotorController<T>::MotorController()
: mHFVC(1, ControllerSamplingTime)
, mIntegrator(1.0f,ControllerSamplingTime) {
	// TODO Auto-generated constructor stub

}

template <typename T>
MotorController<T>::~MotorController() {
	// TODO Auto-generated destructor stub
}

template<typename T>
std::array<T, 3> MotorController<T>::Calculate(const T &pVBus, const std::array<T, 3> &pIuvw, const T &pInputTarget) {

	std::array<T, 2> Ialphabeta = MotorMath::clarkTransform(pIuvw);

	std::array<T, 2> Vganmadelta = {0,pInputTarget};

	T theta = mIntegrator.Integrate2PiMod(1 * 2 * 3.14);

	float gdArg = theta;
	std::array<T, 2> Valphabeta = MotorMath::InvparkTransform(gdArg, Vganmadelta);

	std::array<T, 3> output = MotorMath::SVM(Valphabeta, pVBus);

	return output;
}



#endif /* MOTOR_INC_DETAILS_MOTORCONTROLLER_HPP_ */
