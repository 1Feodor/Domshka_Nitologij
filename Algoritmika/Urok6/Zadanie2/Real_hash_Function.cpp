#include <iostream>
#include <Windows.h>
#include <string>

int simple_string_hash(std::string, int, int);


int main()
{
	/*SetConsoleCP(1251);
	SetConsoleOutputCP(1251);*/
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	std::string stri{ "\0" };
	int rezul{ 0 };
	int p{ 0 };
	int n{ 0 };
	std::cout << "Введите p: ";
	std::cin >> p;
	std::cout << "Введите n: ";
	std::cin >> n;
	do
	{
		std::cout << "Введите строку: ";
		std::cin >> stri;
		rezul = simple_string_hash(stri, p, n);
		std::cout << "Хэш строки " << stri << " = " << rezul << std::endl;
	} while (stri != "exit");
	return 0;
}

int simple_string_hash(std::string str, int p, int n)
{
	unsigned long long rezul{ 0 };
	unsigned long long step{ 1 };
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (i) step *= p;
		rezul += str[i] * step;
	}
	return rezul % n;
}