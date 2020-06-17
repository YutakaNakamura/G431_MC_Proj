/*
 * MotorCtrlMain.hpp
 *
 *  Created on: 2020/05/23
 *      Author: watashi
 */

#ifndef MOTOR_INC_MOTORCTRLMAIN_HPP_
#define MOTOR_INC_MOTORCTRLMAIN_HPP_

#include "ConvertADCtoCurrent.hpp"
//#include "MotorController.hpp"

#include "DebugCtrl.hpp"

class MotorCtrlMain {
private:

	ConvertADCtoCurrent<float> mConvertADCtoCurrent;

	//MotorController<float> mMotorController;

	bool isON = false;
	float mRPM=0;

public:
	MotorCtrlMain();
	virtual ~MotorCtrlMain();

	static void MotorCtrlInit();
	void MotorCtrl();

	void toggleAcceleration();
};

#endif /* MOTOR_INC_MOTORCTRLMAIN_HPP_ */
