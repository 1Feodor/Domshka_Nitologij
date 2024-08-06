#include <iostream>
#include <Windows.h>
#include"Arif_Class.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "¬ведите число: ";
	int a{ 0 };
	std::cin >> a;
	std::cout << "¬ведите число: ";
	int b{ 0 };
	std::cin >> b;
	Arif c;
	std::cout << c.Summ(a, b) << std::endl;
	std::cout << c.Raznost(a, b) << std::endl;
	system("Pause");
	return 0;
}