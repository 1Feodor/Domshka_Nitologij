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
		std::cout << "������� ����� ������: ";
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
			std::cout << "������\n";
			}
			break;
		case months::February:
		{
			std::cout << "�������\n";
		}
		break;
		case months::March:
		{
			std::cout << "����\n";
		}
		break;
		case months::April:
		{
			std::cout << "������\n";
		}
		break;
		case months::May:
		{
			std::cout << "���\n";
		}
		break;
		case months::June:
		{
			std::cout << "����\n";
		}
		break;
		case months::July:
		{
			std::cout << "����\n";
		}
		break;
		case months::August:
		{
			std::cout << "������\n";
		}
		break;
		case months::September:
		{
			std::cout << "��������\n";
		}
		break;
		case months::October:
		{
			std::cout << "�������\n";
		}
		break;
		case months::November:
		{
			std::cout << "������\n";
		}
		break;
		case months::December:
		{
			std::cout << "�������\n";
		}
		break;
		default:
			{
			std::cout << "������������ �����!\n";
			}
			break;
		}
	} while (flag);
	std::cout << "�� ��������";
	return 0;
}

short Konvert_Consol()
{
	char znak1 = '\0';
	short buf = 0;
	for (int i = 0; i < 3; i++)    // ����������� �������� �������� ����� ����������
	{
		znak1 = std::cin.get();  // ����� �� ������ �����������
		if (znak1 == '\n')
		{
			if (!i)		// ���� ������ �����
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
			while (std::cin.get() != '\n');    // ������ ����� �����
			break;
		}
	}
	return buf;
}