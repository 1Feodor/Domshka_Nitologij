#pragma once
#include "Class_Quadrangle.h"

class Parallelogram : public Quadrangle
{
public:
	TRIG_LIB_API_FIGURE Parallelogram(int, int, int, int);
	TRIG_LIB_API_FIGURE ~Parallelogram();
protected:
	void Set_Name_Fig();
	bool check() override;
};

#include "Class_Reectangle.h"
#include "Class_Rhombus.h"