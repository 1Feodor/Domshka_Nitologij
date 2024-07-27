#include <iostream>
#include <Windows.h>
#include <string.h>
#include <exception>
//#include <stdexcept>


int function(std::string const, int const);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int forbidden_length{ 0 };
	std::string str { "\0" };
	bool flag{ true };
	std::cout << "������� ��������� �����: ";
	std::cin >> forbidden_length;

	do
	{
		std::cout << "������� �����: ";
		std::cin >> str;

		try
		{
			int rezul{ function(str, forbidden_length) };
			std::cout << "����� ����� \"" << str << "\" ����� " << rezul << std::endl;
		}
		catch (const std::string& bad_length)
		{
			std::cout << bad_length;
			flag = !flag;
		}
		catch (const std::domain_error& e)
		{
			std::cerr << e.what() << std::endl;
			flag = !flag;
		}
		catch (const std::exception& e)
		{
			//std::cerr << "Caught: " << e.what() << std::endl;
			std::cerr << "Type: " << typeid(e).name() << std::endl;
		}
		catch(...){}
	} while (flag);
	std::cout << "�� ��������\n";
	return 0;
}

int function(std::string const str, int const forbidden_length)
{
	if (str.length() == forbidden_length)
	{
		throw std::exception{ "�� ����� ����� ��������� �����! " };
	}
	return str.length();
}
