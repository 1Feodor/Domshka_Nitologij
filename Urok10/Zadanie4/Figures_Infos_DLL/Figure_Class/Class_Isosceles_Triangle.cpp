#include "Class_Isosceles_Triangle.h"

Isosceles_Triangle::Isosceles_Triangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A)
{
	Set_Name_Fig();
}

Isosceles_Triangle::~Isosceles_Triangle()
{
}

void Isosceles_Triangle::Set_Name_Fig()
{
	name = "Равнобедренный треугольник";
}

bool Isosceles_Triangle::check()
{
	if (!Triangle::check() || this->h[dlinna::a] != this->h[dlinna::c] || this->ugl[ugol::A] != this->ugl[ugol::C])
	{
		return false;
	}
	return true;
}