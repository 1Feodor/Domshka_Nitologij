#include "Class_Right_Triangle.h"

Right_Triangle::Right_Triangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90)
{
	if (Triangle::ugl[ugol::C] != 90)
	{
		throw std::exception{ "угол \"C\" не равен 90." };
	}
	Set_Name_Fig();
}

Right_Triangle::~Right_Triangle()
{
}

void Right_Triangle::Set_Name_Fig()
{
	name = "Прямоугольный треугольник";
}

bool Right_Triangle::check()
{
	if (!Triangle::check() || this->ugl[ugol::C] != 90)
	{
		return false;
	}
	return true;
}