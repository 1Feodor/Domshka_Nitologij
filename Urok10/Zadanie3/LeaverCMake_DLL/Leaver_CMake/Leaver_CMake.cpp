#include <iostream>
#include <Windows.h>
#include"Leaver.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "¬ведите строку: ";
	std::string str;
	std::cin >> str;
	Leaver nime;
	std::cout << nime.leave(str);
	return 0;
}