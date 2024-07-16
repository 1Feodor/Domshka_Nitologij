#pragma once
#include "Class_Triangle.h"

class Isosceles_Triangle : public Triangle
{
public:
	Isosceles_Triangle(int, int, int, int);
	~Isosceles_Triangle();
protected:
	void Set_Name_Fig();
	bool check() override;
};

#include "Class_Equilateral_Triangle.h"