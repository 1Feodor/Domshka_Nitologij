#pragma once
#include <iostream>
#include <string>

enum dlinna : int { a, b, c, d };
enum ugol : int { A, B, C, D };

class Figure
{
public:
	Figure();
	~Figure();
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