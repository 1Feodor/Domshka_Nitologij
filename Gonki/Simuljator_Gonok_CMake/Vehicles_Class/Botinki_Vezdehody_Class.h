#pragma once
#include "Kentavr_Class.h"

class BotinkiVezdehody : public Kentavr
{
public:
	BotinkiVezdehody();
	TRIG_LIB_TR BotinkiVezdehody(int);
	~BotinkiVezdehody() override;
protected:
	float Set_Relax(int)override;
};
#include "Verblud_Class.h"