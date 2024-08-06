#pragma once

#ifndef GONKA
#define TRI_LIB_API __declspec(dllexport)
#else
#define TRI_LIB_API __declspec(dllimport)
#endif // !ARIF
#include"Class_TC.h"

class Gonka
{
public:
TRI_LIB_API Gonka(int const, int const);
TRI_LIB_API virtual ~Gonka();
TRI_LIB_API const char* Participant_Name(int);
TRI_LIB_API float Participant_Time(int)const;
TRI_LIB_API int Participant_Size()const;
protected:
	Gonka(int const, int const, bool);
	int car_massiv{ 0 };
	int size{ 0 };
	TC** list{ nullptr };
	TC* Participant(int);
	
private:
	int distancij{ 0 };
	void Get_Size();
	virtual void Get_List_Participants();
	void Delete_List_Participants();
	void Sorting_results();
};
#include "Broadcast_Gonki_Class.h"