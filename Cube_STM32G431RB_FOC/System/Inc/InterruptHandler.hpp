/*
 * InterruptHandler.hpp
 *
 *  Created on: 2020/05/22
 *      Author: watashi
 */

#ifndef SYSTEM_INC_INTERRUPTHANDLER_HPP_
#define SYSTEM_INC_INTERRUPTHANDLER_HPP_

#include <functional>
#include "MotorCtrlMain.hpp"

class InterruptHandler final{
private:
	InterruptHandler() = default;
	~InterruptHandler() = default;
public:
	InterruptHandler(const InterruptHandler&) = delete;
	InterruptHandler& operator=(const InterruptHandler&) = delete;
	InterruptHandler(InterruptHandler&&) = delete;
	InterruptHandler& operator=(InterruptHandler&&) = delete;

	static InterruptHandler& GetInstance() {
		static InterruptHandler instance;
		return instance;
	}

private:
	//ADCInterruptFunc
	std::function<void()> mADCCpltInterruptFunc;
	//DMA1InterruptFunc
	std::function<void()> mDMA1CpltInterruptFunc;
	//GPIOInterruptFunc
	std::function<void()> mGPIOInterruptFunc;

public:

	void SetADCCpltInterrptFunc(std::function<void()> &pADCCpltInterruptFunc) {
		mADCCpltInterruptFunc = pADCCpltInterruptFunc;
	};

	void ADCCpltFunc() {
		mADCCpltInterruptFunc();
	};

	void SetDMA1CpltInterrptFunc(std::function<void()> &pDMA1CpltInterruptFunc) {
		mDMA1CpltInterruptFunc = pDMA1CpltInterruptFunc;
	};

	void DMA1CpltFunc() {
		mDMA1CpltInterruptFunc();
	};

	void SetGPIOInterrptFunc(std::function<void()> &pGPIOInterruptFunc) {
		mGPIOInterruptFunc = pGPIOInterruptFunc;
	};

	void GPIOInterrptFunc() {
		mGPIOInterruptFunc();
	};



};

//class Sender {
//private:
////    Receiver *m_pReceiver;
////    void (Receiver::*m_pCallbackFunc)();
//	//ADCInterrupt
//	//Object格納
//	MotorCtrlMain *mMotorCtrlMain;
//	//Handler格納
//	void (MotorCtrlMain::*mADCInterruptFunc)();
//
//public:
//    Sender(MotorCtrlMain *pMotorCtrlMain) : mMotorCtrlMain(pMotorCtrlMain) {}
//
//    void SetCallbackFunction( void (MotorCtrlMain::*pFunc)() ) {
//    	mADCInterruptFunc = pFunc;
//    }
//
//    void Invoke() {
//        (mMotorCtrlMain->*mADCInterruptFunc)();
//    }
//};



#endif /* SYSTEM_INC_INTERRUPTHANDLER_HPP_ */
