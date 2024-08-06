#include "Metla_Class.h"

Metla::Metla(int dist) : Air_TC::Air_TC()
{
	this->distance = dist;
	this->name = "Метла            ";
	this->label = "\033[30;48;2;128;128;128m~~}\033[0m";
	this->speed = 20;
	this->factor = 0;
	Run();
}

Metla::~Metla()
{
}

void Metla::Run()
{
	float buf{ 0 };
	for (int i = 0; i <= distance / 1000; i++)
	{
		this->factor = i;
		if (i == distance / 1000)
		{
			buf = buf + static_cast<float>(distance % 1000 * (100 - factor)) / speed / 100;
		}
		else
		{
			buf = buf + static_cast<float>(1000 * (100 - factor)) / speed / 100;
		}
	}
	time_TC = buf;
}

double Metla::Run_Time(double time)
{
	double dist_min{ 0.0 };
	for (int i = 0; time > 0; i++)
	{
		if (i > 99) this->factor = 99;
		else this->factor = i;
	
		if (time <= 1000.0 / speed)
		{
			dist_min = dist_min + time * speed * 100 / (100 - factor);
			time = 0;
		}
		else
		{
			dist_min = dist_min + 1000.0 * 100 / (100 - factor);
			time = time - 1000.0 / speed;
		}
	}
	return dist_min + 0.002;
}
