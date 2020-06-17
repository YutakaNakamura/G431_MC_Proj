/*
 * MotorCtrlMain.cpp
 *
 *  Created on: 2020/05/23
 *      Author: watashi
 */

#include "MotorCtrlMain.hpp"

#include <array>

#include "ADCCtrl.hpp"
#include "TIMCtrl.hpp"
#include "InterruptHandler.hpp"

MotorCtrlMain::MotorCtrlMain() {
	std::function<void()> func = [&](){ return this->toggleAcceleration(); };
	InterruptHandler::GetInstance().SetGPIOInterrptFunc(func);

}

MotorCtrlMain::~MotorCtrlMain() {
	TIMCtrl::DeInitPWM();
}



void MotorCtrlMain::MotorCtrlInit() {
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_SET);

	TIMCtrl::InitPWM();
	ADCCtrl::GetInstance().InitADC();
};

//#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
//#pragma GCC diagnostic ignored "-Wunused-variable"
void MotorCtrlMain::MotorCtrl() {

	std::array<float,3> Iuvw;

	volatile int adc1 = ADCCtrl::GetInstance().GetUphaseADCVal();
	volatile int adc2 = ADCCtrl::GetInstance().GetVphaseADCVal();
	volatile int adc3 = ADCCtrl::GetInstance().GetWphaseADCVal();

	Iuvw[0] = mConvertADCtoCurrent.Current(adc1);
	Iuvw[1] = mConvertADCtoCurrent.Current(adc2);
	Iuvw[2] = mConvertADCtoCurrent.Current(adc3);

	float VBusADC = (float)ADCCtrl::GetInstance().StartDCLinkADC();
	float VBus = VBusADC * ADCVoltageRatio * ((VBusR1 + VBusR2)/VBusR2);

	float UIinputADC = (float)ADCCtrl::GetInstance().StartUserInputADC();
	float inputVal = UIinputADC/4095 * VBus/2;

	std::array<float,3> Vuvw;

//	if(isON) {
//
//		if(mRPM <= 300) {
//			mRPM = mRPM + 0.003;
//		}
//
//	} else {
//		if(mRPM >= 0) {
//			mRPM = mRPM - 0.006;
//		} else
//			mRPM = 0;
//
//	}

	//Vuvw = ....

	float Uduty = Vuvw[0];
	float Vduty = Vuvw[1];
	float Wduty = Vuvw[2];

	TIMCtrl::SetUphaseDuty(Uduty);
	TIMCtrl::SetVphaseDuty(Vduty);
	TIMCtrl::SetWphaseDuty(Wduty);

	DebugCtrl::GetInstance().RTTOutput();

};

void MotorCtrlMain::toggleAcceleration() {
	if(isON == true){
		isON = false;
	} else {
		isON = true;
	}
}
