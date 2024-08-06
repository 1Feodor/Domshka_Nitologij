#pragma once
#include "Class_Triangle.h"

class Right_Triangle : public Triangle
{
public:
	TRIG_LIB_API_FIGURE Right_Triangle(int, int, int, int, int);
	TRIG_LIB_API_FIGURE ~Right_Triangle();
protected:
	void Set_Name_Fig();
	bool check() override;
};