#include "Botinki_Vezdehody_Class.h"

BotinkiVezdehody::BotinkiVezdehody() : Kentavr::Kentavr()
{
}

BotinkiVezdehody::BotinkiVezdehody(int dist) : Kentavr::Kentavr()
{
	this->distance = dist;
	this->name = "Ботинки-вездеходы";
	this->label = "\033[30;43m==+\033[0m";
	this->speed = 6;
	this->time_run = 60;
	this->size = 2;
	Set_size();
	this->time_relax[0] = 10;
	this->time_relax[1] = 5;
	Run();
}

BotinkiVezdehody::~BotinkiVezdehody()
{
	Delet_size();
}

float BotinkiVezdehody::Set_Relax(int i)
{
	if (!i)
	{
		return this->time_relax[0];
	}
	return this->time_relax[1];
}