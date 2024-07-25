#pragma once
#include "Class_Parallelogram.h"

class Rhombus : public Parallelogram
{
public:
	Rhombus(int, int, int);
	~Rhombus();
protected:
	void Set_Name_Fig();
	bool check() override;
};