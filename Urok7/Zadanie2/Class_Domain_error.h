#pragma once
class Domain_error
{
public:
	Domain_error();
	~Domain_error();
protected:
	virtual void Print_error() = 0;
};

#include "Class_Figure.h"