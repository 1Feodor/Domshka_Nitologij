#include "Class_TC.h"

TC::TC()
{
}

TC::~TC()
{
}

const char* TC::Get_Name()
{
	return this->name;
}

const char* TC::Get_Label()
{
	return this->label;
}

float TC::Get_Time() const
{
	return this->time_TC;
}