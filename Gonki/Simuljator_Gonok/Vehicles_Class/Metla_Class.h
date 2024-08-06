#pragma once
#include "Class_Air_TC.h"

class Metla : public Air_TC
{
public:
TRIG_LIB_API Metla(int);
	~Metla() override;
protected:
	void Run() override;
	double Run_Time(double)override;
};