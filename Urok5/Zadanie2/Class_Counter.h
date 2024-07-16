#pragma once
#include <iostream>
#include <Windows.h>

class Counter
{
public:
	Counter();
	Counter(int);
	~Counter();
	void Plus1();
	void Minus1();
	int Schet_get();
private:
	int schet = 1;
};

short Da_ili_Net();
short Chislo_Consol();
