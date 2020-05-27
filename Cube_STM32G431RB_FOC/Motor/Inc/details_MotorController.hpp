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

#include "DebugCtrl.hpp"

template <typename T>
MotorController<T>::MotorController()
: mHFVC(1, ControllerSamplingTime)
, mIntegrator(1.0f,ControllerSamplingTime) {
	// TODO Auto-generated constructor stub

	DebugCtrl::GetInstance().Init();

}

template <typename T>
MotorController<T>::~MotorController() {
	// TODO Auto-generated destructor stub
}

template<typename T>
std::array<T, 3> MotorController<T>::Calculate(const T &pVBus, const std::array<T, 3> &pIuvw, const T &pInputTarget, const T &pInputREV) {


	DebugCtrl::GetInstance().mJScopeData.mIu = (int)1000 * pIuvw[0];
	DebugCtrl::GetInstance().mJScopeData.mIv = (int)1000 * pIuvw[1];
	DebugCtrl::GetInstance().mJScopeData.mIw = (int)1000 * pIuvw[2];

	std::array<T, 2> Ialphabeta = MotorMath::clarkTransform(pIuvw);

//	DebugCtrl::GetInstance().mJScopeData.mIa=Ialphabeta[0];
//	DebugCtrl::GetInstance().mJScopeData.mIb=Ialphabeta[1];

	std::array<T, 2> Vganmadelta = {0,pInputTarget};

	DebugCtrl::GetInstance().mJScopeData.mVg = (int)1000 * Vganmadelta[0];
	DebugCtrl::GetInstance().mJScopeData.mVd = (int)1000 * Vganmadelta[1];


	float speed = pInputREV;

	//T theta = mIntegrator.Integrate2PiMod(1 * 2 * 3.14);
	T theta = mIntegrator.Integrate2PiMod(speed * 2 * 3.14);

	float gdArg = theta;
	std::array<T, 2> Valphabeta = MotorMath::InvparkTransform(gdArg, Vganmadelta);

	std::array<T, 3> output = MotorMath::SVM(Valphabeta, pVBus);


	return output;
}



#endif /* MOTOR_INC_DETAILS_MOTORCONTROLLER_HPP_ */
