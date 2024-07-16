#pragma once
#include "Class_Figure.h"

class Triangle : public Figure
{
public:
	Triangle(int, int, int, int, int, int);
	~Triangle();
	void print_info() override;
protected:
	void Set_Stron();
	void Set_Name_Fig();
	bool check() override;
};

#include "Class_Right_Triangle.h"
#include "Class_Isosceles_Triangle.h"