#include "Class_Square.h"

Square::Square(int a) : Reectangle(a, a)
{
	Set_Name_Fig();
}

Square::~Square()
{
}

void Square::Set_Name_Fig()
{
	name = "Êâàäğàò";
}

bool Square::check()
{
	if (!Reectangle::check() || this->h[dlinna::a] != this->h[dlinna::b])
	{
		return false;
	}
	return true;
}