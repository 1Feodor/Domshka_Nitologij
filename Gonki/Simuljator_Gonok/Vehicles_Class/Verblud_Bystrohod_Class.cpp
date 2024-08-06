#include "Verblud_Bystrohod_Class.h"

VerbludBystrohod::VerbludBystrohod(int dist) : Verblud::Verblud()
{
	this->distance = dist;
	this->name = "Верблюд-быстроход";
	this->label = "\033[30;48;2;242;225;39mC++\033[0m";
	this->speed = 40;
	this->time_run = 10;
	this->size = 3;
	Set_size();
	this->time_relax[0] = 5.0f;
	this->time_relax[1] = 6.5f;
	this->time_relax[2] = 8.0f;
	Run();
}

VerbludBystrohod::~VerbludBystrohod()
{
	Delet_size();
}

float VerbludBystrohod::Set_Relax(int i)
{
	if (!i)
	{
		return this->time_relax[0];
	}
	else if (i == 1)
	{
		return this->time_relax[1];
	}
	return this->time_relax[2];
}