#include "Class_Reectangle.h"

Reectangle::Reectangle(int a, int b) : Parallelogram(a, b, 90, 90)
{
	Set_Name_Fig();
}

Reectangle::~Reectangle()
{
}

void Reectangle::Set_Name_Fig()
{
	name = "Прямоугольник";
}

bool Reectangle::check()
{
	if (!Parallelogram::check() || this->ugl[ugol::A] != 90 || this->ugl[ugol::B] != 90)
	{
		return false;
	}
	return true;
}