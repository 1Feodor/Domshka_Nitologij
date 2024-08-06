#pragma once
#include <iostream>
#include <string>

#ifndef FIGURE
#define TRIG_LIB_API_FIGURE __declspec(dllexport)
#else
#define TRIG_LIB_API_FIGURE __declspec(dllimport)
#endif // !FIGURE

enum dlinna : int { a, b, c, d };
enum ugol : int { A, B, C, D };

class Figure
{
public:
	TRIG_LIB_API_FIGURE Figure();
	TRIG_LIB_API_FIGURE ~Figure();
	virtual void print_info();
protected:
	std::string name;
	int storona;
	int* h = nullptr;
	int* ugl = nullptr;
	void Set_Stron();
	void Set_Name_Fig();
	void Num_Stron_Corner();
	void Del_Stron();
	std::string get_sides_count()const;
	std::string get_side_length()const;
	std::string get_side_corner()const;
	virtual bool check();
};

#include "Class_Triangle.h"
#include "Class_Quadrangle.h"