#include "Class_Counter.h"

short Da_ili_Net()
{
	char znak1 = '\0';
	short otvet = 0;
	znak1 = std::cin.get();

	if (znak1 == 'Y' || znak1 == 'y')
	{
		znak1 = std::cin.get();
		if (znak1 == '\n')
		{
			otvet = 1;
		}

	}
	else if (znak1 == 'N' || znak1 == 'n')
	{
		znak1 = std::cin.get();
		if (znak1 == '\n')
		{
			otvet = 2;
		}

	}
	else if (znak1 == '�' || znak1 == '�')
	{
		znak1 = std::cin.get();
		if (znak1 == '�' || znak1 == '�')
		{
			znak1 = std::cin.get();
			if (znak1 == '\n')
			{
				otvet = 1;
			}
		}

	}
	else if (znak1 == '�' || znak1 == '�')
	{
		znak1 = std::cin.get();
		if (znak1 == '�' || znak1 == '�')
		{
			znak1 = std::cin.get();
			if (znak1 == '�' || znak1 == '�')
			{
				znak1 = std::cin.get();
				if (znak1 == '\n')
				{
					otvet = 2;
				}
			}
		}

	}
	if (znak1 != '\n')
	{
		otvet = 0;
		while (std::cin.get() != '\n');
	}

	return otvet;
}

short Chislo_Consol()
{
	bool flag = false;
	char znak1 = '\0';
	short buf = 0;
	for (int i = 0; i < 5; i++)
	{
		znak1 = std::cin.get();
		if (znak1 == '\n')
		{
			if (!i)
			{
				buf = 10000;
			}
			break;
		}
		else if (!i && znak1 == '-')
		{
			flag = true;
		}
		else if (znak1 >= '0' && znak1 <= '9' && i < 4)
		{
			buf = buf * 10 + (znak1 - '0');
		}
		else
		{
			buf = 10000;
			flag = false;
			while (std::cin.get() != '\n');
			break;
		}
	}
	if (flag)
	{
		buf *= (-1);
	}
	return buf;
}