#include "Gonka_Class.h"

Gonka::Gonka(int const carR, int const dist, bool)
{
	this->car_massiv = carR;
	this->distancij = dist;
	Get_Size();
}

Gonka::Gonka(int const carR, int const dist)
{
	this->car_massiv = carR;
	this->distancij = dist;
	Get_Size();
	Get_List_Participants();
	Sorting_results();
}

Gonka::~Gonka()
{
	Delete_List_Participants();
}

const char* Gonka::Participant_Name(int i)
{
	return list[i]->Get_Name();
}

float Gonka::Participant_Time(int i) const
{
	return list[i]->Get_Time();
}

int Gonka::Participant_Size() const
{
	return this->size;
}

void Gonka::Get_Size()
{
	int car{ this->car_massiv };
	do 
	{
		this->size++;
	} while (car /= 10);
}

void Gonka::Get_List_Participants()
{
	int car{ this->car_massiv };
	list = new TC * [size + 1];
	for (int i = 0; i < size; i++)
	{
		list[i] = Participant(car % 10);
		car /= 10;
	}
	list[size] = nullptr;
}

void Gonka::Delete_List_Participants()
{
	for (int i = 0; i < size; i++)
	{
		if (list[i] != nullptr)
		{
			delete[] list[i];
			list[i] = nullptr;
		}
	}
	if (list != nullptr)
	{
		delete[] list;
		list = nullptr;
	}
}

TC* Gonka::Participant(int ind)
{
	TC* Car{ nullptr };
	switch (ind)
	{
	case 1:
	{
		Car = new BotinkiVezdehody{ this->distancij };
	}
	break;
	case 2:
	{
		Car = new Verblud{ this->distancij };
	}
	break;
	case 3:
	{
		Car = new VerbludBystrohod{ this->distancij };
	}
	break;
	case 4:
	{
		Car = new Kentavr{ this->distancij };
	}
	break;
	case 5:
	{
		Car = new KoverSamolet{ this->distancij };
	}
	break;
	case 6:
	{
		Car = new Metla{ this->distancij };
	}
	break;
	case 7:
	{
		Car = new Orel{ this->distancij };
	}
	break;
	}
	return Car;
}

void Gonka::Sorting_results()
{
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (list[j]->Get_Time() >= list[j + 1]->Get_Time())
			{
				list[size] = list[j + 1];
				list[j + 1] = list[j];
				list[j] = list[size];
				list[size] = nullptr;
			}
		}
	}
}
