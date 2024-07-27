#include <Windows.h>
#include "Class_Figure.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try
	{
		Figure fff;
		fff.print_info();
		std::cout << std::endl;

		Triangle tri(10, 20, 30, 92, 49, 39);
		tri.print_info();
		std::cout << std::endl;
		
		Right_Triangle rt(16, 38, 104, 76, 14);
		rt.print_info();
		std::cout << std::endl;

		Isosceles_Triangle it(13, 24, 51, 78);
		it.print_info();
		std::cout << std::endl;

		Equilateral_Triangle et(33);
		et.print_info();
		std::cout << std::endl;

		Parallelogram parll(16, 38, 104, 76);
		parll.print_info();
		std::cout << std::endl;

		Reectangle rec(10, 35);
		rec.print_info();
		std::cout << std::endl;

		Rhombus rhom(24, 101, 79);
		rhom.print_info();
		std::cout << std::endl;

		Square squ(27);
		squ.print_info();
		std::cout << std::endl;

		Quadrangle qua(10, 20, 30, 25, 75, 88, 64, 96);
		qua.print_info();
		std::cout << std::endl;
	}
	catch (const std::domain_error& e)
	{
		std::cout << "Ошибка создания фигуры. Причина: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "ERROR FATAL! Причина: " << e.what() << std::endl;
	}

	return 0;
}