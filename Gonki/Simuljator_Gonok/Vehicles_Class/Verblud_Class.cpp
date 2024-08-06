#include "Verblud_Class.h"

Verblud::Verblud() : BotinkiVezdehody::BotinkiVezdehody()
{
}

Verblud::Verblud(int dist) : BotinkiVezdehody::BotinkiVezdehody()
{
	this->distance = dist;
	this->name = "Верблюд          ";
	this->label = "\033[30;48;2;252;252;38m^^@\033[0m";
	this->speed = 10;
	this->time_run = 30;
	this->size = 2;
	Set_size();
	this->time_relax[0] = 5;
	this->time_relax[1] = 8;
	Run();
}

Verblud::~Verblud()
{
	Delet_size();
}
#include "Verblud_Bystrohod_Class.h"