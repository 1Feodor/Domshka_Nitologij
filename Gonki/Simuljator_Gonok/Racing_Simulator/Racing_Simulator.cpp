#include <Windows.h>
#include <iostream>
#include"Menu.h"

int main()
{
	#define NAZAD 100100
	enum class section {Exit, Tip_Gonki, Rastojnij, Car_Registration, Gonka
	}MENU = section::Tip_Gonki;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Zagolovok();
	std::cout << "\033[?25l";
	std::cout << "\033[16C«ÑÈÌÓËßÒÎÐ ÃÎÍÎÊ»\n";
	std::cout << "\033[6CÄîáðî ïîæàëîâàòü â ãîíî÷íûé ñèìóëÿòîð!\n";
	short tipG{ 0 };
	int dist{ 0 };
	int carR{ 0 };
	do
	{
		switch (MENU)
		{
		case section::Tip_Gonki:
		{
			tipG = Vybor_Tipa_Gonki();
			MENU = section::Rastojnij;
		}
			break;
		case section::Rastojnij:
		{
			dist = Vybor_Rastojnij();
			if (dist == NAZAD)
			{
				MENU = section::Tip_Gonki;
			}
			else
			{
				MENU = section::Car_Registration;
			}
		}
			break;
		case section::Car_Registration:
		{
			carR = Vybor_Car(tipG);
			if (carR == NAZAD)
			{
				MENU = section::Rastojnij;
			}
			else
			{
				MENU = section::Gonka;
			}
		}
			break;
		case section::Gonka:
		{
			int rezul{ Vybor_Gonki(carR) };
			if (rezul == NAZAD)
			{
				MENU = section::Car_Registration;
			}
			else
			{
				if (rezul == 2)
				{
					Broadcast_gonki(carR, dist);
				}
				Rezultaty_gonki(carR, dist, rezul);
				bool vybor{ Menu_Exit(carR) };
				if (vybor)
				{
					MENU = section::Tip_Gonki;
				}
				else
				{
					MENU = section::Exit;
				}
			}
		}
			break;
		}
	} while (MENU != section::Exit);	
	std::cout << "\n\033[?25h";
	return 0;
}