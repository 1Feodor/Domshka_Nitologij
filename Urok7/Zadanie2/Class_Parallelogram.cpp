#include "Class_Parallelogram.h"

Parallelogram::Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B)
{
	Set_Name_Fig();
	Print_error();
}

Parallelogram::~Parallelogram()
{
}

void Parallelogram::Set_Name_Fig()
{
	name = "Параллелограмм";
}

bool Parallelogram::check()
{
	if (!Quadrangle::check() || this->h[dlinna::a] != this->h[dlinna::c] || this->h[dlinna::b] != this->h[dlinna::d] || this->ugl[ugol::A] != this->ugl[ugol::C] || this->ugl[ugol::B] != this->ugl[ugol::D])
	{
		return false;
	}
	return true;
}

void Parallelogram::Print_error()
{
	if (!check())
	{
		this->~Parallelogram();
		throw std::string{ "углы попарно не равны, стороны попарно не равны" };
	}
}
