#pragma once
#include "Class_Parallelogram.h"

class Reectangle : public Parallelogram
{
public:
	TRIG_LIB_API_FIGURE Reectangle(int, int);
	TRIG_LIB_API_FIGURE ~Reectangle();
protected:
	void Set_Name_Fig();
	bool check() override;
};

#include "Class_Square.h"