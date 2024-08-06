#pragma once
#include "Class_Land_TC.h"

class Kentavr : public Land_TC
{
public:
	Kentavr();
TRIG_LIB_API Kentavr(int);
	~Kentavr() override;
protected:
	float Set_Relax(int)override;
};
#include "Botinki_Vezdehody_Class.h"