#include <iostream>
#include <Windows.h>
#include <string>

int simple_string_hash(std::string);


int main()
{
	/*SetConsoleCP(1251);
	SetConsoleOutputCP(1251);*/
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	std::string stri{ "\0" };
	int rezul{ 0 };
	do
	{
		std::cout << "Введите строку: ";
		std::cin >> stri;
		rezul = simple_string_hash(stri);
		std::cout << "Наивный хэш строки " << stri << " = " << rezul << std::endl;
	} while (stri != "exit");
	return 0;
}

int simple_string_hash(std::string str)
{
	int rezul{ 0 };
	for (int i = 0; str[i] != '\0'; ++i)
	{
		rezul += str[i];
	}
	return rezul;
}