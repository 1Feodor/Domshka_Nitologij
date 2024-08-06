#pragma once
#ifndef TR_CR
#define TRIG_LIB_API __declspec(dllexport)
#else
#define TRIG_LIB_API __declspec(dllimport)
#endif // !TR_CR
class TC
{
public:
	TC();
	virtual ~TC();
TRIG_LIB_API const char* Get_Name();
TRIG_LIB_API const char* Get_Label();
TRIG_LIB_API float Get_Time()const;
	virtual double Run_Time(double) = 0;
protected:
	const char* name{ nullptr };
	const char* label{ nullptr };
	short speed{ 0 };
	int distance{ 0 };
	float time_TC{ 0.f };
	virtual void Run() = 0;
};

#include "Class_Land_TC.h"
#include "Class_Air_TC.h"