#include <iostream>
#include <Windows.h>

unsigned long long cisloFi(int, unsigned long long*);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int cislo{ 0 };
	std::cout << "Введите число: ";
	std::cin >> cislo;
	unsigned long long* buferFi = new unsigned long long[cislo] {0};
	std::cout << "Числа Фибоначчи: ";

	for (int i = 0; i < cislo; i++)
	{
		std::cout << cisloFi(i, buferFi) << " ";
	}
	std::cout << std::endl;
	delete[] buferFi;
	return 0;
}

unsigned long long cisloFi(int fi, unsigned long long* buf)
{
	if (fi == 1) return 1;
	if (fi == 0) return 0;
	if (buf[fi] != 0) return buf[fi];
	buf[fi] = cisloFi(fi - 1, buf) + cisloFi(fi - 2, buf);
	return buf[fi];
}