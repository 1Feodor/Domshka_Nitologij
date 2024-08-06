#include "Kover_Samolet_Class.h"

KoverSamolet::KoverSamolet(int dist) : Air_TC::Air_TC()
{
	this->distance = dist;
	this->name = "Ковёр-самолёт    ";
	this->label = "\033[30;44m~##\033[0m";
	this->speed = 10;
	this->factor = 0;
	Run();
}

KoverSamolet::~KoverSamolet()
{
}

void KoverSamolet::Run()
{
	float buf{ 0 };
	for (int i = 0; i <= distance / 1000; i++)
	{
		if (i == 1) this->factor = 3;
		else if (i == 5) this->factor = 10;
		else if (i == 10) this->factor = 5;
		
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

double KoverSamolet::Run_Time(double time)
{
	double dist_min{ 0.0 };
	for (int i = 0; time > 0; i++)
	{
		if (i == 1) this->factor = 3;
		else if (i == 5) this->factor = 10;
		else if (i == 10) this->factor = 5;

		if (time <= 1000.0 / speed)
		{
			dist_min = dist_min + time * speed * 100 / (100 - factor);
			time = 0.0;
		}
		else
		{
			dist_min = dist_min + 1000.0 * 100 / (100 - factor);
			time = time - 1000.0 / speed;
		}
	}
	return dist_min + 0.002;
}
