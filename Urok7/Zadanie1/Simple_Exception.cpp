#include <iostream>
#include <Windows.h>
#include <string.h>

int function(std::string const, int const);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int forbidden_length{ 0 };
	std::string str { "\0" };
	bool flag{ true };
	std::cout << "Введите запретную длину: ";
	std::cin >> forbidden_length;

	do
	{
		std::cout << "Введите слово: ";
		std::cin >> str;

		try
		{
			int rezul{ function(str, forbidden_length) };
			std::cout << "Длина слова \"" << str << "\" равна " << rezul << std::endl;
		}
		catch (const std::string& bad_length)
		{
			std::cout << bad_length;
			flag = !flag;
		}
		catch(...){}
	} while (flag);
	std::cout << "До свидания\n";
	return 0;
}

int function(std::string const str, int const forbidden_length)
{
	if (str.length() == forbidden_length)
	{
		throw std::string { "Вы ввели слово запретной длины! " };
	}
	return str.length();
}
