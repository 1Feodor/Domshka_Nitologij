#pragma once
#include "Class_Parallelogram.h"

class Reectangle : public Parallelogram
{
public:
	Reectangle(int, int);
	~Reectangle();
protected:
	void Set_Name_Fig();
	bool check() override;
};

#include "Class_Square.h"