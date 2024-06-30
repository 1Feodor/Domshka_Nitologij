#include <iostream>

enum class months : short { Exit, January, February, March
, April, May, June, July, August, September, October,
November, December} month;

short Konvert_Consol();

int main()
{
	setlocale(LC_ALL, "Russian");
	bool flag = true;
	do
	{
		std::cout << "Введите номер месяца: ";
		month = static_cast<months>(Konvert_Consol());
		switch (month)
		{
		case months::Exit:
			{
			flag = !flag;
			}
			break;
		case months::January:
			{
			std::cout << "Январь\n";
			}
			break;
		case months::February:
		{
			std::cout << "Февраль\n";
		}
		break;
		case months::March:
		{
			std::cout << "Март\n";
		}
		break;
		case months::April:
		{
			std::cout << "Апрель\n";
		}
		break;
		case months::May:
		{
			std::cout << "Май\n";
		}
		break;
		case months::June:
		{
			std::cout << "Июнь\n";
		}
		break;
		case months::July:
		{
			std::cout << "Июль\n";
		}
		break;
		case months::August:
		{
			std::cout << "Август\n";
		}
		break;
		case months::September:
		{
			std::cout << "Сентябрь\n";
		}
		break;
		case months::October:
		{
			std::cout << "Октябрь\n";
		}
		break;
		case months::November:
		{
			std::cout << "Ноябрь\n";
		}
		break;
		case months::December:
		{
			std::cout << "Декабрь\n";
		}
		break;
		default:
			{
			std::cout << "Неправильный номер!\n";
			}
			break;
		}
	} while (flag);
	std::cout << "До свидания";
	return 0;
}

short Konvert_Consol()
{
	char znak1 = '\0';
	short buf = 0;
	for (int i = 0; i < 3; i++)    // Ограничеваю проверку символов тремя элементами
	{
		znak1 = std::cin.get();  // читаю из буфера посимвольно
		if (znak1 == '\n')
		{
			if (!i)		// если строка пуста
			{
				buf = 13;
			}
			break;
		}
		else if (znak1 >= '0' && znak1 <= '9' && i < 2)
		{
			buf = buf * 10 + (znak1 - '0');
		}
		else
		{
			buf = 13;
			while (std::cin.get() != '\n');    // Очищаю буфер ввода
			break;
		}
	}
	return buf;
}