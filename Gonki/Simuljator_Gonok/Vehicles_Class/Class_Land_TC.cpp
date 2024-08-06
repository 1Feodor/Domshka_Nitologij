#include "Class_Land_TC.h"

Land_TC::Land_TC() : TC::TC()
{
}

Land_TC::~Land_TC()
{
}

void Land_TC::Run()
{
	float relax{ Set_Relax(0) };
	float buf{ 0 };
	for (int i = 0; i < distance / (time_run * speed); i++)
	{
		if (i == 1) relax = Set_Relax(i);
		if (i == 2) relax = Set_Relax(i);

		buf = buf + time_run;
		if (i + 1 != distance / (time_run * speed) || distance % (time_run * speed))
		{
			buf = buf + relax;
		}
	}
	if (distance % (time_run * speed))
	{
		buf = buf + static_cast<float>(distance % (time_run * speed)) / speed;
	}
	time_TC = buf;
}

double Land_TC::Run_Time(double time)
{
	float relax{ this->Set_Relax(0) };
	double dist_min{ 0.0 };
	for (int i{ 0 }; time > this->time_run; i++)
	{
		if (i == 1) relax = this->Set_Relax(i);
		if (i == 2) relax = this->Set_Relax(i);
		dist_min = dist_min + this->time_run * this->speed;
		time = time - this->time_run;
		if (time <= relax)
		{
			time = 0;
		}
		else
		{
			time = time - relax;
		}
	}
	dist_min = dist_min + time * this->speed;

	return  dist_min + 0.002;
}

void Land_TC::Set_size()
{
	time_relax = new float[size];
}

void Land_TC::Delet_size()
{
	if (time_relax != nullptr)
	{
		delete[] time_relax;
		time_relax = nullptr;
	}
}