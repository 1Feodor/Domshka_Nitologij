#include "Broadcast_Gonki_Class.h"

Broadcast_Gonki::Broadcast_Gonki(int const carR, int const dist) : Gonka::Gonka(carR, dist, true)
{
	Get_List_Participants();
}

Broadcast_Gonki::~Broadcast_Gonki()
{
}

const char* Broadcast_Gonki::Participant_Label(int i)
{
	return list[i]->Get_Label();
}

double Broadcast_Gonki::Run_Time(const int i, double m_time)
{
	return list[i]->Run_Time(m_time);
}

void Broadcast_Gonki::Get_List_Participants()
{
	int car{ this->car_massiv };
	list = new TC * [size];
	for (int i = size - 1; i >= 0; i--)
	{
		list[i] = Participant(car % 10);
		car /= 10;
	}
}