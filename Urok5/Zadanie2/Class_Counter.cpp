#include "Class_Counter.h"

Counter::Counter()
{
}

Counter::Counter(int cis)
{
	this->schet = cis;
}

Counter::~Counter()
{
}

void Counter::Plus1()
{
	this->schet++;
}

void Counter::Minus1()
{
	this->schet--;
}

int Counter::Schet_get()
{
	return this->schet;
}