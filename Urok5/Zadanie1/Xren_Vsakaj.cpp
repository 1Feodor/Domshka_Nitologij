#include "Mathem_Fun.h"

bool Cislo_iz_Consol(double* cislo)
{
	bool flagi = true;
	char znak1 = '\0';
	long long buf = 0; 
	int pred = 10, del = 1;
	for (int i = 0; i < pred; i++)    // ����������� �������� �������� ����� ����������
	{
		znak1 = std::cin.get();  // ����� �� ������ �����������
		if (znak1 == '\n')
		{
			if (!i)		// ���� ������ �����
			{
				buf = 1000000000;
			}
			break;
		}
		else if (!i && znak1 == '-')
		{
			del *= (-1);
			continue;
		}
		else if ((znak1 == '.' || znak1 == ',') && flagi)
		{
			flagi = false;
			continue;
		}
		else if (znak1 >= '0' && znak1 <= '9' && i < pred - 1)
		{
			buf = buf * 10 + static_cast<long long>(znak1 - '0');
		}
		else
		{
			buf = 1000000000;
			del = 1;
			while (std::cin.get() != '\n');    // ������ ����� �����
			break;
		}
		if (!flagi)
		{
			del *= 10;
		}
	}
	if (buf == 1000000000)
	{
		return false;
	}
	*cislo = static_cast<double>(buf) / del;
	return true;
}

bool Exit()
{
	char znak1 = '\0';
	bool ex = true;
	for (int i = 0; i < 2; i++)    // ����������� �������� �������� ����� ����������
	{
		znak1 = std::cin.get();  // ����� �� ������ �����������
		if (znak1 == '\n')
		{
			break;
		}
		else if (znak1 == '0' && i < 1)
		{
			ex = false;
		}
		else
		{
			ex = true;
			while (std::cin.get() != '\n');    // ������ ����� �����
			break;
		}
	}
	return ex;
}

void Vykl_Podsvetka(int rjad)
{
	std::cout << "\r";
	switch (rjad)
	{
	case 1:
	{
		std::cout << "C�������             ";
	}
	break;
	case 2:
	{
		std::cout << "���������            ";
	}
	break;
	case 3:
	{
		std::cout << "���������            ";
	}
	break;
	case 4:
	{
		std::cout << "�������              ";
	}
	break;
	case 5:
	{
		std::cout << "���������� � ������� ";
	}
	break;
	case 6:
	{
		std::cout << "\033[0;34;42mC�������            \033[0m ";
	}
	break;
	case 7:
	{
		std::cout << "\033[0;34;42m���������           \033[0m ";
	}
	break;
	case 8:
	{
		std::cout << "\033[0;34;42m���������           \033[0m ";
	}
	break;
	case 9:
	{
		std::cout << "\033[0;34;42m�������             \033[0m ";
	}
	break;
	case 10:
	{
		std::cout << "\033[0;34;42m���������� � �������\033[0m ";
	}
	break;
	}
}

int Vybor_Operacii()
{
	int rajd = 1;

	std::cout << "\n�������� �������� ���������:\n";
	std::cout << "C�������\n";
	std::cout << "���������\n";
	std::cout << "���������\n";
	std::cout << "�������\n";
	std::cout << "���������� � �������";
	std::cout << "\033[4A";
	Vykl_Podsvetka(rajd + 5);
	char aaa = '\0';
	do
	{
		aaa = _getch();
		if (aaa == -32)
		{
			aaa = _getch();
			if (aaa == 72 && rajd > 1) // Up
			{
				Vykl_Podsvetka(rajd);
				std::cout << "\033[1A";
				rajd--;
				Vykl_Podsvetka(rajd + 5);
			}
			else if (aaa == 80 && rajd < 5)
			{
				Vykl_Podsvetka(rajd);
				std::cout << "\033[1B";
				rajd++;
				Vykl_Podsvetka(rajd + 5);
			}

		}
	} while (aaa != '\r');

	return rajd;
}