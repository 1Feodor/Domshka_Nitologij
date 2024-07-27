#include "Class_Parallelogram.h"

Parallelogram::Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B)
{
	if (Quadrangle::ugl[ugol::A] != Quadrangle::ugl[ugol::C] || Quadrangle::ugl[ugol::B] != Quadrangle::ugl[ugol::D])
	{
		throw std::exception{ "углы \"A\",\"C\" и \"B\",\"D\" попарно не равны." };
	}
	else if (Quadrangle::h[dlinna::a] != Quadrangle::h[dlinna::c] || Quadrangle::h[dlinna::b] != Quadrangle::h[dlinna::d])
	{
		throw std::exception{ "стороны \"a\",\"c\" и \"b\",\"d\" попарно не равен." };
	}
	Set_Name_Fig();
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