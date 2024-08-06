#pragma once
#include "Verblud_Class.h"

class VerbludBystrohod : public Verblud
{
public:
	TRIG_LIB_TR VerbludBystrohod(int);
	~VerbludBystrohod() override;
protected:
	float Set_Relax(int)override;
};