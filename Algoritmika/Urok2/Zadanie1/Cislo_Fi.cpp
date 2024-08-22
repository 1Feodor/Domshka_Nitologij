#include <iostream>
#include <Windows.h>

unsigned long long cisloFi(int);

int main()
{	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int cislo{ 0 };
	std::cout << "Введите число: ";
	std::cin >> cislo;
	std::cout << "Числа Фибоначчи: ";

	for (int i = 0; i < cislo; i++)
	{
		std::cout << cisloFi(i) << " ";
	}
	std::cout << std::endl;
	return 0;
}

unsigned long long cisloFi(int fi)
{
	if (fi == 1) return 1;
	if (fi == 0) return 0;
	return cisloFi(fi - 1) + cisloFi(fi - 2);
}