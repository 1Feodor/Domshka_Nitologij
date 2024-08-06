#include "Class_Triangle.h"

Triangle::Triangle(int a, int b, int c, int A, int B, int C)
{

	Set_Name_Fig();
	Set_Stron();
	Num_Stron_Corner();
	this->h[dlinna::a] = a;
	this->h[dlinna::b] = b;
	this->h[dlinna::c] = c;
	this->ugl[ugol::A] = A;
	this->ugl[ugol::B] = B;
	this->ugl[ugol::C] = C;
}

Triangle::~Triangle()
{
	Del_Stron();
}

void Triangle::print_info()
{
	Figure::print_info();
	std::cout << Figure::get_side_length() << std::endl;
	std::cout << Figure::get_side_corner() << std::endl;
}

void Triangle::Set_Stron()
{
	storona = 3;
}

void Triangle::Set_Name_Fig()
{
	name = "Треугольник";
}

bool Triangle::check()
{
	if (storona != 3 || (this->ugl[ugol::A] + this->ugl[ugol::B] + this->ugl[ugol::C] != 180))
	{
		return false;
	}
	return true;
}