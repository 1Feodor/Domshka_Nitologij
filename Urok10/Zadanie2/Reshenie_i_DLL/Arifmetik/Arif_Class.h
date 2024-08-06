#pragma once

#ifndef ARIF
	#define TRI_LIB_API __declspec(dllexport)
#else
	#define TRI_LIB_API __declspec(dllimport)
#endif // !ARIF


class Arif
{
public:
	TRI_LIB_API int Summ(int, int);
	TRI_LIB_API int Raznost(int, int);

private:

};