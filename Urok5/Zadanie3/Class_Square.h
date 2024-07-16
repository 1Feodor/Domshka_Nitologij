#pragma once
#include "Class_Reectangle.h"

class Square : public Reectangle
{
public:
	Square(int);
	~Square();
protected:
	void Set_Name_Fig();
	bool check() override;
};