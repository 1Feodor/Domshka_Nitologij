#include <iostream>
#include <Windows.h>

enum class flagi : short { Error, Da, Net } flag;

class Counter
{
public:
	Counter();
	Counter(int);
	~Counter();
	void Plus1();
	void Minus1();
	int Schet_get();
private:
	int schet = 1;
};

Counter::Counter()
{
}

Counter::Counter(int cis)
{
	this->schet = cis;
}

Counter::~Counter()
{
}

void Counter::Plus1()
{
	this->schet++;
}

void Counter::Minus1()
{
	this->schet--;
}

int Counter::Schet_get()
{
	return this->schet;
}

short Da_ili_Net();
short Chislo_Consol();

int main()
{
	/*setlocale(LC_ALL, "Russian");*/
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	flag = flagi::Error;
	std::cout << "Vy hotite ukazat nachalnoe znachenie schetchika?" << std::endl;
	do
	{
		std::cout << "Vvedite Y ili N ";
		flag = static_cast<flagi>(Da_ili_Net());
	} while (flag == flagi::Error);
	///////////////////////////////////////////////
	Counter* coun = 0;
	if (flag == flagi::Da)
	{
		std::cout << "Vvedite nachalnoe znachenie schetchika: ";
		int znach = Chislo_Consol();
		while (znach >= 10000)
		{
			std::cout << "Ne vernyj format znachenia!" << std::endl;
			std::cout << "Vvedite nachalnoe znachenie schetchika: ";
			znach = Chislo_Consol();
		}
		coun = new Counter(znach);
	}
	else if (flag == flagi::Net)
	{
		coun = new Counter();
	}
	//////////////////////////////////////////////////
	bool flag2 = true;
	do
	{
		std::cout << "Vvedite komandu ('+', '-', '=' ili 'x'): ";
		char coman = '\0';
		std::cin >> coman;
		while (std::cin.get() != '\n') coman = '\0';
		switch (coman)
		{
		case '+':
		{
			coun->Plus1();
		}
		break;
		case '-':
		{
			coun->Minus1();
		}
		break;
		case '=':
		{
			std::cout << coun->Schet_get() << std::endl;
		}
		break;
		case 'x':
		{
			flag2 = false;
		}
		break;
		default:
		{
			std::cout << "Oshibka vvoda!" << std::endl;
		}
		break;
		}
	} while (flag2);
	delete coun;
	std::cout << "Do svidanij!" << std::endl;
	return 0;
}

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