#include "Class_Square.h"

Square::Square(int a) : Reectangle(a, a)
{
	if (Quadrangle::h[dlinna::a] != Quadrangle::h[dlinna::c] || Quadrangle::h[dlinna::b] != Quadrangle::h[dlinna::d] || Quadrangle::h[dlinna::b] != Quadrangle::h[dlinna::a])
	{
		throw std::exception{ "������� \"a\",\"c\",\"b\",\"d\" �� �����." };
	}
	Set_Name_Fig();
}

Square::~Square()
{
}

void Square::Set_Name_Fig()
{
	name = "�������";
}

bool Square::check()
{
	if (!Reectangle::check() || this->h[dlinna::a] != this->h[dlinna::b])
	{
		return false;
	}
	return true;
}