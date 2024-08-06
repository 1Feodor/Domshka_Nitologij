#pragma once
#include "Botinki_Vezdehody_Class.h"

class Verblud : public BotinkiVezdehody
{
public:
	Verblud();
TRIG_LIB_API Verblud(int);
	~Verblud() override;
protected:
};
#include "Verblud_Bystrohod_Class.h"