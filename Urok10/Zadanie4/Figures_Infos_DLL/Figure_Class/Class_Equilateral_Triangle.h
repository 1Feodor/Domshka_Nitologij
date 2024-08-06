#pragma once
#include "Class_Isosceles_Triangle.h"

class Equilateral_Triangle : public Isosceles_Triangle
{
public:
	TRIG_LIB_API_FIGURE Equilateral_Triangle(int);
	TRIG_LIB_API_FIGURE ~Equilateral_Triangle();
protected:
	void Set_Name_Fig();
	bool check() override;
};