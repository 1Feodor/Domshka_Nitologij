#pragma once

#include "Gonka_Class.h"
class Broadcast_Gonki : public Gonka
{
public:
TRI_LIB_API Broadcast_Gonki(int const, int const);
TRI_LIB_API ~Broadcast_Gonki()override;
TRI_LIB_API	const char* Participant_Label(int);
TRI_LIB_API	double Run_Time(const int, double);
private:
	void Get_List_Participants()override;
};


