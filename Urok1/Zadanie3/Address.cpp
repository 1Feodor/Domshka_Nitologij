#include <iostream>
#include <string>

struct Adresa
{
	std::string gorod = "������";
	std::string ulica = "�����" ;
	int dom = 12;
	int kvartira = 8;
	int indeks = 123456;
} adres_moskva;

void Adres_v_Consol(Adresa&);

int main()
{
	setlocale(LC_ALL, "Russian");
	Adresa adres_izhevsk;
	adres_izhevsk.gorod = "������";
	adres_izhevsk.ulica = "�������";
	adres_izhevsk.dom = 59;
	adres_izhevsk.kvartira = 143;
	adres_izhevsk.indeks = 953769;

	Adresa* adr_massiv = new Adresa[3];
	adr_massiv[0] = adres_moskva;
	adr_massiv[1] = adres_izhevsk;
	adr_massiv[2].gorod = "�����������";
	adr_massiv[2].ulica = "������";
	adr_massiv[2].dom = 26;
	adr_massiv[2].kvartira = 304;
	adr_massiv[2].indeks = 555666;
		//Adresa adres_vladivostok = adr_massiv[2];
	for (int i = 0; i < 3; i++)
	{
		Adres_v_Consol(adr_massiv[i]);
		std::cout << std::endl;
	}
	delete[] adr_massiv;
	adr_massiv = nullptr;
	return 0;
}

void Adres_v_Consol(Adresa& adr)
{
	std::cout << "�����: ";
	std::cout << adr.gorod << std::endl;
	std::cout << "�����: ";
	std::cout << adr.ulica << std::endl;
	std::cout << "����� ����: ";
	std::cout << adr.dom << std::endl;
	std::cout << "����� ��������: ";
	std::cout << adr.kvartira << std::endl;
	std::cout << "������: ";
	std::cout << adr.indeks << std::endl;
}