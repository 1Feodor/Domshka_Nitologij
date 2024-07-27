#include "Class_Rhombus.h"

Rhombus::Rhombus(int a, int A, int B) : Parallelogram(a, a, A, B)
{
	if (Quadrangle::h[dlinna::a] != Quadrangle::h[dlinna::c] || Quadrangle::h[dlinna::b] != Quadrangle::h[dlinna::d] || Quadrangle::h[dlinna::b] != Quadrangle::h[dlinna::a])
	{
		throw std::exception{ "������� \"a\",\"c\",\"b\",\"d\" �� �����." };
	}
	Set_Name_Fig();
}

Rhombus::~Rhombus()
{
}

void Rhombus::Set_Name_Fig()
{
	name = "����";
}

bool Rhombus::check()
{
	if (!Parallelogram::check() || this->h[dlinna::a] != this->h[dlinna::b])
	{
		return false;
	}
	return true;
}