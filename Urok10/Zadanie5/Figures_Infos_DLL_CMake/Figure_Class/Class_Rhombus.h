#pragma once
#include "Class_Parallelogram.h"

class Rhombus : public Parallelogram
{
public:
	TRIG_LIB_API_FIGURE Rhombus(int, int, int);
	TRIG_LIB_API_FIGURE ~Rhombus();
protected:
	void Set_Name_Fig();
	bool check() override;
};