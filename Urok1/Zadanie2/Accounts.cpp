#include <iostream>
#include <Windows.h>
#include <iomanip>

struct Accounts
{
	int account_number = 0;
	char name[21] {"\0"};
	double balance = 0;
} account;

int Account_Consol();
void Name_Consol(Accounts&);
double Balance_Consol();
void Account_V_Consol(Accounts&);
void New_Balance(Accounts&, double);

int main()
{
	//setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool flag = true;
	///////////////////////////////////////////
	std::cout << "������� ����� �����: ";
	do
	{
		int num = Account_Consol();
		if (!num) // ���� ����� ����
		{
			std::cout << "�� ���������� ����� �����, \n";
			std::cout << "����� ����� �� ������ ��������� 9 ��������.\n";
			std::cout << "������� ����� �����: ";
			continue;
		}
		account.account_number = num;
		flag = false;
	} while (flag);
	flag = true;
	///////////////////////////////////////
	std::cout << "������� ��� ���������: ";
	Name_Consol(account);
	///////////////////////////////////////
	std::cout << "������� ������: ";
	do
	{
		double bal = Balance_Consol();
		if (bal < 0)
		{
			std::cout << "�� ��������� ������� ������, \n";
			std::cout << "������ �� ����� ����� ������ 2 ������ ����� �������.\n";
			std::cout << "������� ������: ";
			continue;
		}
		account.balance = bal;
		flag = false;
	} while (flag);
	flag = true;
	///////////////////////////////////////
	std::cout << "������� ����� ������: ";
	do
	{
		double bal = Balance_Consol();
		if (bal < 0)
		{
			std::cout << "�� ��������� ������� ������, \n";
			std::cout << "������ �� ����� ����� ������ 2 ������ ����� �������.\n";
			std::cout << "������� ������: ";
			continue;
		}
		New_Balance(account, bal);
		flag = false;
	} while (flag);
	///////////////////////////////////////
	std::cout << "��� ����: " << account.name << ", ";
	Account_V_Consol(account);
	std::cout << std::setprecision(2) << std::fixed << account.balance;
	return 0;
}

int Account_Consol()
{
	char znak1 = '\0';
	int buf = 0;
	for (int i = 0; i < 10; i++)    // ����������� �������� ��������
	{
		znak1 = std::cin.get();  // ����� �� ������ �����������
		if (znak1 == '\n')
		{
			break;
		}
		else if (znak1 >= '0' && znak1 <= '9' && i < 9)  // �� ������ 9 ����
		{
			buf = buf * 10 + (znak1 - '0');  // �������� � int
		}
		else  // �������� �����
		{
			buf = 0;
			while (std::cin.get() != '\n');    // ������ ����� �����
			break;
		}
	}
	return buf;
}

void Name_Consol(Accounts& account)
{
	char znak1 = '\0';
	for (int i = 0; i < 20; i++)    // ����������� �������� ��������
	{
		znak1 = std::cin.get();  // ����� �� ������ �����������
		if (znak1 == '\n')
		{
			if (!i)		// ���� ������ �����
			{
				account.name[i] = ' ';
				account.name[i + 1] = '\0';
			}
			else
			{
				account.name[i] = '\0';
			}
			break;
		}
		else
		{
			account.name[i] = znak1;
			if (i >= 19)
			{
				account.name[20] = '\0';
				while (std::cin.get() != '\n');    // ������ ����� �����
			}	
		}
	}
}

double Balance_Consol()
{
	bool flagi = true;
	char znak1 = '\0';
	int buf = 0, pred = 30, del = 1;
	for (int i = 0; i < pred; i++)    // ����������� �������� �������� ����� ����������
	{
		znak1 = std::cin.get();  // ����� �� ������ �����������
		if (znak1 == '\n')
		{
			if (!i)		// ���� ������ �����
			{
				buf = -1;
			}
			break;
		}
		else if ((znak1 == '.' || znak1 <= ',') && flagi)
		{
			if (i + 4 < pred)
			{
				pred = i + 4;
			}
			flagi = false;
			continue;
		}
		else if (znak1 >= '0' && znak1 <= '9' && i < pred - 1)
		{
			buf = buf * 10 + (znak1 - '0');
		}
		else
		{
			buf = -1;
			while (std::cin.get() != '\n');    // ������ ����� �����
			break;
		}
		if (!flagi)
		{
			del *= 10;
		}
	}
	return static_cast<double>(buf) / del;
}

void Account_V_Consol(Accounts&)
{
	int number = account.account_number;
	for (int i = 0; i < 9; i++)
	{
		number /= 10;
		if (number <= 0)
		{
			for (int j = 0; j < 8 - i; j++)
			{
				std::cout << 0;
			}
			std::cout << account.account_number << ", ";
			break;
		}
	}
}

void New_Balance(Accounts&, double neew)
{
	account.balance = neew;
}