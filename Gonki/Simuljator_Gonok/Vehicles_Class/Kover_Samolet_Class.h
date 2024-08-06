#pragma once
#include "Class_Air_TC.h"

class KoverSamolet : public Air_TC
{
public:
TRIG_LIB_API KoverSamolet(int);
	~KoverSamolet() override;
protected:
	void Run() override;
	double Run_Time(double)override;
};