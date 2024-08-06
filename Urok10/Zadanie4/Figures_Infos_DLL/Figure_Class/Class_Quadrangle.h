#pragma once
#include "Class_Figure.h"

class Quadrangle : public Figure
{
public:
	TRIG_LIB_API_FIGURE Quadrangle(int, int, int, int, int, int, int, int);
	TRIG_LIB_API_FIGURE ~Quadrangle();
	void print_info() override;
protected:
	void Set_Stron();
	void Set_Name_Fig();
	bool check() override;
};

#include "Class_Parallelogram.h"