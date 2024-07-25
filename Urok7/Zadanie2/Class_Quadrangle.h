#pragma once
#include "Class_Figure.h"

class Quadrangle : public Figure
{
public:
	Quadrangle(int, int, int, int, int, int, int, int);
	~Quadrangle();
	void print_info() override;
protected:
	void Set_Stron();
	void Set_Name_Fig();
	bool check() override;
	void Print_error() override;
};

#include "Class_Parallelogram.h"