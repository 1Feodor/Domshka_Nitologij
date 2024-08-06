#pragma once
#include "Class_Reectangle.h"

class Square : public Reectangle
{
public:
	TRIG_LIB_API_FIGURE Square(int);
	TRIG_LIB_API_FIGURE ~Square();
protected:
	void Set_Name_Fig();
	bool check() override;
};