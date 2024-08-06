#pragma once
#include "Class_TC.h"

class Land_TC : public TC
{
public:
	Land_TC();
	~Land_TC();
protected:
	int time_run{ 0 };
	short size{ 0 };
	float* time_relax { nullptr };
	void Run() override;
	double Run_Time(double)override;
	virtual float Set_Relax(int) = 0;
	void Set_size();
	void Delet_size();
};
#include "Kentavr_Class.h"