﻿#include <iostream>
#include <Windows.h>

class Calculator
{
public:
	Calculator();
	~Calculator();
	double add() const;
	double multiply() const;
	double subtract_1_2() const;
	double subtract_2_1() const;
	double divide_1_2() const;
	double divide_2_1() const;
	bool set_num1(const double);
	bool set_num2(const double);
private:
	double num1 = 0;
	double num2 = 0;
};

Calculator::Calculator()
{
	std::cout << "Начало программы. \n";
}

Calculator::~Calculator()
{
	std::cout << "Конец программы. \n";
}

double Calculator::add() const
{
	return this->num1 + this->num2;
}

double Calculator::multiply() const
{
	return this->num1 * this->num2;
}

double Calculator::subtract_1_2() const
{
	return this->num1 - this->num2;
}

double Calculator::subtract_2_1() const
{
	return this->num2 - this->num1;
}

double Calculator::divide_1_2() const
{
	return this->num1 / this->num2;
}

double Calculator::divide_2_1() const
{
	return this->num2 / this->num1;
}

bool Calculator::set_num1(const double num1)
{
	if (!num1)
	{
		return false;	
	}
	this->num1 = num1;
	return true;
}

bool Calculator::set_num2(const double num2)
{
	if (!num2)
	{
		return false;
	}
	this->num2 = num2;
	return true;
}

double Balance_Consol();

int main()
{
	//setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Calculator kalk;
	while (true)
	{
	//double num1 = 0;
	double num2 = 0;
	std::cout << "Введите num1: ";
		while (!kalk.set_num1(Balance_Consol()))
		{
			std::cout << "Неверный ввод!\n";
			std::cout << "Введите num1: ";
		}

		do
		{
			std::cout << "Введите num2: ";
			num2 = Balance_Consol();
			if (!num2)
			{
				std::cout << "Неверный ввод!\n";
			}
		} while (!kalk.set_num2(num2));

		std::cout << "num1 + num2 = ";
		std::cout << kalk.add() << std::endl;
		std::cout << "num1 - num2 = ";
		std::cout << kalk.subtract_1_2() << std::endl;
		std::cout << "num2 - num1 = ";
		std::cout << kalk.subtract_2_1() << std::endl;
		std::cout << "num1 * num2 = ";
		std::cout << kalk.multiply() << std::endl;
		std::cout << "num1 / num2 = ";
		std::cout << kalk.divide_1_2() << std::endl;
		std::cout << "num2 / num1 = ";
		std::cout << kalk.divide_2_1() << std::endl;
	}
	return 0;
}

double Balance_Consol()
{
	bool flag1 = true, flag2 = true;
	char znak1 = '\0';
	int buf = 0, pred = 30, del = 1;
	for (int i = 0; i < pred; i++)    // Ограничеваю проверку символов тремя элементами
	{
		znak1 = std::cin.get();  // читаю из буфера посимвольно
		if (znak1 == '\n')
		{
			break;
		}
		else if (!i && znak1 == '-' && flag1)
		{
			flag1 = false;
			continue;
		}
		else if ((znak1 == '.' || znak1 <= ',') && flag2)
		{
			flag2 = false;
			continue;
		}
		else if (znak1 >= '0' && znak1 <= '9' && i < pred - 1)
		{
			buf = buf * 10 + (znak1 - '0');
		}
		else
		{
			buf = 0;
			while (std::cin.get() != '\n');    // Очищаю буфер ввода
			break;
		}
		if (!flag2)
		{
			del *= 10;
		}
	}
	if (!flag1)
	{
		del *= (-1);
	}
	return static_cast<double>(buf) / del;
}
