#pragma once
#include "Class_Triangle.h"

class Isosceles_Triangle : public Triangle
{
public:
	TRIG_LIB_API_FIGURE Isosceles_Triangle(int, int, int, int);
	TRIG_LIB_API_FIGURE ~Isosceles_Triangle();
protected:
	void Set_Name_Fig();
	bool check() override;
};

#include "Class_Equilateral_Triangle.h"