/*
 * MotorCtrlMain.hpp
 *
 *  Created on: 2020/05/23
 *      Author: watashi
 */

#ifndef MOTOR_INC_MOTORCTRLMAIN_HPP_
#define MOTOR_INC_MOTORCTRLMAIN_HPP_


#include "MotorController.hpp"


class MotorCtrlMain {
private:
	MotorController<float> mMotorController;


public:
	MotorCtrlMain();
	virtual ~MotorCtrlMain();

	static void MotorCtrlInit();
	void MotorCtrl();

};

#endif /* MOTOR_INC_MOTORCTRLMAIN_HPP_ */
