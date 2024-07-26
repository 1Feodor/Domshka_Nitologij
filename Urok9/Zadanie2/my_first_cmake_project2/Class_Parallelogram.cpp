#include "Class_Parallelogram.h"

Parallelogram::Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B)
{
	Set_Name_Fig();
}

Parallelogram::~Parallelogram()
{
}

void Parallelogram::Set_Name_Fig()
{
	name = "ֿאנאככוכמדנאלל";
}

bool Parallelogram::check()
{
	if (!Quadrangle::check() || this->h[dlinna::a] != this->h[dlinna::c] || this->h[dlinna::b] != this->h[dlinna::d] || this->ugl[ugol::A] != this->ugl[ugol::C] || this->ugl[ugol::B] != this->ugl[ugol::D])
	{
		return false;
	}
	return true;
}