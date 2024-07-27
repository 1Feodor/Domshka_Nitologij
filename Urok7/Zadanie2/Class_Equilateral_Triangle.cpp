#include "Class_Equilateral_Triangle.h"

Equilateral_Triangle::Equilateral_Triangle(int a) : Isosceles_Triangle(a, a, 60, 60)
{
	if (Triangle::ugl[ugol::A] != 60 || Triangle::ugl[ugol::B] != 60 || Triangle::ugl[ugol::C] != 60)
	{
		throw std::exception{ "���� �� ����� 60." };
	}
	else if (a != Triangle::h[dlinna::b] || a != Triangle::h[dlinna::c])
	{
		throw std::exception{ "������� �� �����." };
	}
	Set_Name_Fig();
}

Equilateral_Triangle::~Equilateral_Triangle()
{
}

void Equilateral_Triangle::Set_Name_Fig()
{
	name = "�������������� �����������";
}

bool Equilateral_Triangle::check()
{
	if (!Isosceles_Triangle::check() || this->h[dlinna::a] != this->h[dlinna::b] || this->ugl[ugol::A] != this->ugl[ugol::B] || this->ugl[ugol::A] != 60)
	{
		return false;
	}
	return true;
}