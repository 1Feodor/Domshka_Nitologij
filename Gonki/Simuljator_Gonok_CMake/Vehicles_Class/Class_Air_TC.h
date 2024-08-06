#pragma once
#include "Class_TC.h"

class Air_TC : public TC
{
public:
	Air_TC();
	~Air_TC();
protected:
	int factor{ 0 };
};
#include "Orel_Class.h"
#include "Metla_Class.h"
#include "Kover_Samolet_Class.h"