#pragma once
#include "Class_Quadrangle.h"

class Parallelogram : public Quadrangle
{
public:
	Parallelogram(int, int, int, int);
	~Parallelogram();
protected:
	void Set_Name_Fig();
	bool check() override;
	void Print_error() override;
};

#include "Class_Reectangle.h"
#include "Class_Rhombus.h"