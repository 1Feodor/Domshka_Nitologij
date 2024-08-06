#pragma once
#include "Class_Air_TC.h"

class Orel : public Air_TC
{
public:
TRIG_LIB_API Orel(int);
	~Orel() override;
protected:
	void Run() override;
	double Run_Time(double)override;
};