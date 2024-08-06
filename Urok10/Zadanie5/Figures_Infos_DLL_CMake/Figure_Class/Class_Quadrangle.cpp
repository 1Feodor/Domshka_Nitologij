#include "Class_Quadrangle.h"

Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
{
	Set_Name_Fig();
	Set_Stron();
	Num_Stron_Corner();
	this->h[dlinna::a] = a;
	this->h[dlinna::b] = b;
	this->h[dlinna::c] = c;
	this->h[dlinna::d] = d;
	this->ugl[ugol::A] = A;
	this->ugl[ugol::B] = B;
	this->ugl[ugol::C] = C;
	this->ugl[ugol::D] = D;
}

Quadrangle ::~Quadrangle()
{
	Del_Stron();
}

void Quadrangle::print_info()
{
	Figure::print_info();
	std::cout << Figure::get_side_length() << std::endl;
	std::cout << Figure::get_side_corner() << std::endl;
}

void Quadrangle::Set_Stron()
{
	storona = 4;
}

void Quadrangle::Set_Name_Fig()
{
	name = "Четырёхугольник";
}

bool Quadrangle::check()
{
	if (storona != 4 || (this->ugl[ugol::A] + this->ugl[ugol::B] + this->ugl[ugol::C] + this->ugl[ugol::D] != 360))
	{
		return false;
	}
	return true;
}