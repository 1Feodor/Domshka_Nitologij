#pragma once
#include<string>
#ifndef LEAVER
#define TRIG_LIB_API_LEAVER __declspec(dllexport)
#else
#define TRIG_LIB_API_LEAVER __declspec(dllimport)
#endif // !LEAVER
class Leaver
{
public:
	TRIG_LIB_API_LEAVER std::string leave(std::string);

private:

};
