#include <Windows.h>
#include "Class_Figure.h"

void Print_Info(Figure*);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Figure fig;
	Print_Info(&fig);
	std::cout << std::endl;
	
	Triangle tri(10, 20, 30, 92, 49, 39);
	Print_Info(&tri);
	std::cout << std::endl;

	Right_Triangle rt(14, 24, 34, 22, 69);
	Print_Info(&rt);
	std::cout << std::endl;

	Isosceles_Triangle it(13, 24, 51, 78);
	Print_Info(&it);
	std::cout << std::endl;

	Equilateral_Triangle et(33);
	Print_Info(&et);
	std::cout << std::endl;

	Quadrangle qua(10, 20, 30, 25, 75, 88, 64, 96);
	Print_Info(&qua);
	std::cout << std::endl;

	Reectangle rec(10, 35);
	Print_Info(&rec);
	std::cout << std::endl;

	Square squ(27);
	Print_Info(&squ);
	std::cout << std::endl;

	Parallelogram parll(16, 38, 104, 76);
	Print_Info(&parll);
	std::cout << std::endl;

	Rhombus rhom(24, 101, 79);
	Print_Info(&rhom);
	std::cout << std::endl;

	return 0;
}

void Print_Info(Figure* figur)
{
	figur->print_info();
}