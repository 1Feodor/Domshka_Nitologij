#include <Windows.h>
#include "Class_Figure.h"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try
	{
		Triangle tri(10, 20, 30, 92, 49, 39);
		tri.print_info();
		std::cout << std::endl;

		Parallelogram parll(16, 38, 104, 76);
		parll.print_info();
		std::cout << std::endl;

		Quadrangle qua(10, 20, 30, 25, 75, 88, 64, 96);
		qua.print_info();
	}
	catch (const std::string& bad_figure)
	{
		std::cout << "Ошибка создания фигуры. Причина: " << bad_figure << std::endl;
	}

	return 0;
}