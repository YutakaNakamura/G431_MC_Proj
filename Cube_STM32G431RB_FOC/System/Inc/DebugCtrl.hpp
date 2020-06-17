/*
 * DebugCtrl.hpp
 *
 *  Created on: Aug 8, 2019
 *      Author: watashi
 */

#ifndef DEBUGCTRL_HPP_
#define DEBUGCTRL_HPP_

#include <string>
#include "SEGGER_RTT.h"

//class JScopeData {
//public:
//	int mLogCnt;
//	int mIg;
//	int mId;
//	int EstOmega;
//	int EstTheta;
//};

//class JScopeData {
//public:
//	int mIa;
//	int mIb;
//	int mIg;
//	int mId;
//	int EstTheta;
//};

class JScopeData {
public:
	int mLogCnt;
	int mIu;
	int mIv;
	int mIw;
	int mVg;
	int mVd;
};

//class JScopeData {
//public:
//	int mLogCnt;
//	int mVg;
//	int mVd;
//	int mIa;
//	int mIb;
//	int mIg;
//	int mId;
//	int EstOmega;
//	int EstTheta;
//};

//class JScopeData {
//public:
//	int mLogCnt;
//	int mVg;
//	int mVd;
//	int mIu;
//	int mIv;
//	int mIw;
//	int mIa;
//	int mIb;
//	int EstTheta;
//};


class DebugCtrl {
private:
	DebugCtrl() = default;
	~DebugCtrl() = default;

public:
	DebugCtrl(const DebugCtrl&) = delete;
	DebugCtrl& operator=(const DebugCtrl&) = delete;
	DebugCtrl(DebugCtrl&&) = delete;
	DebugCtrl& operator=(DebugCtrl&&) = delete;

	static DebugCtrl& GetInstance() {
		static DebugCtrl instance;
		return instance;
	}

private:

	char mJS_RTT_UpBuffer[4096];
	int mLogcount;
	std::string mOutputStr;
	char mOutputChar[128] = {};

public:
	JScopeData mJScopeData;

	void Init();
	void RTTOutput();
	//void RTTOutput(const MotorInfo<float> &pMotorInfo, const UIStatus &pUIStatus){};
	//void RTTOutput(const MotorInfo<float> &pMotorInfo);
	//void AddOutputString(const MotorInfo<volatile float> &pMotorInfo);

};



#endif /* DEBUGCTRL_HPP_ */
