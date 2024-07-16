#include "Mathem_Fun.h"


int main()
{
	enum class matFuncs : short {Sloshenie = 1,
		Vychitanie, Umnoshenie, Delenie, Stepen} matFunc;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double cislo1 = 0, cislo2 = 0;
	bool flag = true;
	
	do
	{
		std::cout << "\033c";
		do
		{
			std::cout << "Введите первое число: ";
			if (Cislo_iz_Consol(&cislo1)) flag = false;
			else std::cout << "\033[0;31mОшибка!\033[0m";
			if (flag)
			{
				std::cout << "\033[1F";	
			}
			std::cout << "\033[0K";
		} while (flag);

		flag = true;
		do
		{
			std::cout << "Введите второе число: ";
			if (Cislo_iz_Consol(&cislo2)) flag = false;
			else std::cout << "\033[0;31mОшибка!\033[0m";
			if (flag)
			{
				std::cout << "\033[1F";
			}
			std::cout << "\033[0K";
		} while (flag);

		flag = true;

			matFunc = static_cast<matFuncs>(Vybor_Operacii());
		switch (matFunc)
		{
			case matFuncs::Sloshenie:
			{
				std::cout << cislo1 << " + " << cislo2 << " = " << Sloshenie(&cislo1, &cislo2);
				std::cout << "\033[5B\r";
			}
			break;
			case matFuncs::Vychitanie:
			{
				std::cout << cislo1 << " - " << cislo2 << " = " << Vychitanie(&cislo1, &cislo2);
				std::cout << "\033[4B\r";
			}
			break;
			case matFuncs::Umnoshenie:
			{
				std::cout << cislo1 << " * " << cislo2 << " = " << Umnoshenie(&cislo1, &cislo2);
				std::cout << "\033[3B\r";
			}
			break;
			case matFuncs::Delenie:
			{
				if (cislo2 == 0)
				{
					std::cout << cislo1 << " / " << cislo2 << " = \033[0;31mError!\033[0m";
				}
				else
				{
					std::cout << cislo1 << " / " << cislo2 << " = " << Delenie(&cislo1, &cislo2);
				}
				std::cout << "\033[2B\r";
			}
			break;
			case matFuncs::Stepen:
			{
				std::cout << cislo1 << " в степени " << cislo2 << " = " << Stepen(&cislo1, &cislo2);
				std::cout << "\033[1B\r";
			}
			break;
		}
		std::cout << "\nЧто-бы продолжить введите \"1\"\n";
		std::cout << "Что-бы выйти введите \"0\"\n";
	} while (Exit());
	return 0;
}