#include <Windows.h>
#include <iostream>
#include <string> // ���������� ������
#include <fstream> // ���������� �����

class Adresa
{
public:
	Adresa();
	Adresa(const std::string, const std::string, const int, const int);
	~Adresa();
	std::string Get_Adres() const;
private:
	std::string gorod;
	std::string ulica;
	int dom;
	int kvartira;
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string name_file = "in.txt";
	std::ifstream in_file;
	in_file.open(name_file);
	if (!in_file.is_open())
	{
		std::cout << "File \"in.txt\" opening error!" << std::endl;
		in_file.close();
		return 0;
	}

	int size = 0;
	in_file >> size;
	if (size <= 0)
	{
		std::cout << "Error! The file \"in.txt\" contains incorrect data" << std::endl;
		in_file.close();
		return 0;
	}

	Adresa* adr_massiv = new Adresa[size];
	std::string gorodB;
	std::string ulicaB;
	int domB = 0;
	int kvartiraB = 0;
	for (int i = 0; i < size; i++)
	{
		in_file >> gorodB;
		in_file >> ulicaB;
		in_file >> domB;
		in_file >> kvartiraB;
		adr_massiv[i] = Adresa(gorodB, ulicaB, domB, kvartiraB);
	}
	in_file.close();
////////////////////////////////////////////////////
	std::ofstream iot_file;
	iot_file.open("out.txt");
	if (!iot_file.is_open())
	{
		std::cout << "File \"out.txt\" opening error!" << std::endl;
	}
	else
	{
		for (int i = size; i > 0; i--)
			{
			iot_file << adr_massiv[i - 1].Get_Adres() << std::endl;
			}
	}
	iot_file.close();
	delete[] adr_massiv;
	return 0;
}

Adresa::Adresa()
{
	this->gorod = Adresa::ulica = "\0";
	this->dom = Adresa::kvartira = 0;
}

Adresa::Adresa(const std::string gorod, const std::string ulica, const int dom, const int kvartira)
{
	Adresa::gorod = gorod;
	this -> ulica = ulica;
	Adresa::dom = dom;
	this -> kvartira = kvartira;
}

Adresa::~Adresa()
{
}

std::string Adresa::Get_Adres() const
{
	return gorod + ", " + ulica + ", " + std::to_string(dom) + ", " + std::to_string(kvartira);
}
