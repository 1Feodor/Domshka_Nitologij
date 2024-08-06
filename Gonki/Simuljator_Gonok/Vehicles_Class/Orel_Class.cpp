#include "Orel_Class.h"

Orel::Orel(int dist) : Air_TC::Air_TC()
{
	this->distance = dist;
	this->name = "Îð¸ë             ";
	this->label = "\033[30;46m~%~\033[0m";
	this->speed = 8;
	this->factor = 6;
	Run();
}

Orel::~Orel()
{
}

void Orel::Run()
{
	time_TC = static_cast<float>(distance * (100 - factor)) / speed / 100;
}

double Orel::Run_Time(double time)
{
	double dist_min = time * speed * 100 / (100 - factor);
	return dist_min + 0.002;
}
