#include "Class_Counter.h"

int main()
{
	enum class flagi : short { Error, Da, Net } flag;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	flag = flagi::Error;
	std::cout << "�� ������ ������� ��������� �������� ��������?" << std::endl;
	do
	{
		std::cout << "������� �� ��� ���: ";
		flag = static_cast<flagi>(Da_ili_Net());
	} while (flag == flagi::Error);
	///////////////////////////////////////////////
	Counter* coun = 0;
	if (flag == flagi::Da)
	{
		std::cout << "������� ��������� �������� ��������: ";
		int znach = Chislo_Consol();
		while (znach >= 10000)
		{
			std::cout << "�� ������ ������ ��������!" << std::endl;
			std::cout << "������� ��������� �������� ��������: ";
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
		std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
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
		case '�':
		{
			flag2 = false;
		}
		break;
		default:
		{
			std::cout << "������ �����!" << std::endl;
		}
		break;
		}
	} while (flag2);
	delete coun;
	std::cout << "�� ��������!" << std::endl;
	return 0;
}