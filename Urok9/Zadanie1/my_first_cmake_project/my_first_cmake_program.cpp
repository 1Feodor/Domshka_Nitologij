#include <iostream>
#include <Windows.h>
#include <string>
int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string name{ "\0" };

	std::cout << "Введите имя: ";
	std::cin >> name;
	std::cout << "Здравствуйте, " << name << "!\n";
	return 0;
}