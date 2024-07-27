#include "Class_Rhombus.h"

Rhombus::Rhombus(int a, int A, int B) : Parallelogram(a, a, A, B)
{
	if (Quadrangle::h[dlinna::a] != Quadrangle::h[dlinna::c] || Quadrangle::h[dlinna::b] != Quadrangle::h[dlinna::d] || Quadrangle::h[dlinna::b] != Quadrangle::h[dlinna::a])
	{
		throw std::exception{ "стороны \"a\",\"c\",\"b\",\"d\" не равен." };
	}
	Set_Name_Fig();
}

Rhombus::~Rhombus()
{
}

void Rhombus::Set_Name_Fig()
{
	name = "Ромб";
}

bool Rhombus::check()
{
	if (!Parallelogram::check() || this->h[dlinna::a] != this->h[dlinna::b])
	{
		return false;
	}
	return true;
}