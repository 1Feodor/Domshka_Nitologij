#include "Kentavr_Class.h"

Kentavr::Kentavr() : Land_TC::Land_TC()
{
}

Kentavr::Kentavr(int dist) : Land_TC::Land_TC()
{
	this->distance = dist;
	this->name = "Кентавр          ";
	this->label = "\033[30;42m**&\033[0m";
	this->speed = 15;
	this->time_run = 8;
	this->size = 1;
	Set_size();
	this->time_relax[0] = 2.0f;
	Run();
}

Kentavr::~Kentavr()
{
	Delet_size();
}

float Kentavr::Set_Relax(int)
{
	return this->time_relax[0];
}