#pragma once
#include "Class_Triangle.h"

class Right_Triangle : public Triangle
{
public:
	Right_Triangle(int, int, int, int, int);
	~Right_Triangle();
protected:
	void Set_Name_Fig();
	bool check() override;
};