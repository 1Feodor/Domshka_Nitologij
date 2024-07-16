#pragma once
#include "Class_Isosceles_Triangle.h"

class Equilateral_Triangle : public Isosceles_Triangle
{
public:
	Equilateral_Triangle(int);
	~Equilateral_Triangle();
protected:
	void Set_Name_Fig();
	bool check() override;
};