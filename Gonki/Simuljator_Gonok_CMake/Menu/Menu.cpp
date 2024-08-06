#include"Menu.h"

void Zagolovok()
{
	std::cout << "\033[?25l";
	char zagl[35]{ "«СИМУЛЯТОР ГОНОК»\0" };
	int sec{ 10 };
	for (int i = 0; i < 67; i++)
	{
		if (i < 17)
		{
			std::cout << "\033[50C" << zagl[i] << "\r";
		}
		std::cout << "\033[1P";
		Sleep(10);
	}
	Sleep(200);
	for (int i = 0; i < 67; i++)
	{
		if (i >= 50)
		{
			std::cout << "\033[49C\033[1P\r";
		}
		std::cout << "\033[1@";
		if (i < 17)
		{
			std::cout << zagl[16 - i] << "\r";
		}
		Sleep(10);
	}
	Sleep(200);

	for (int i = 0; i < 34; i++)
	{
		if (i < 17)
		{
			std::cout << "\033[50C" << zagl[i] << "\r";
		}
		if (i > 22)
		{
			sec += 4;
		}
		std::cout << "\033[1P";
		Sleep(sec);
	}
	Sleep(500);
	std::cout << "\033[?25h";
}

void Vykl_Podsvetka(int rjad)
{
	std::cout << "\r";
	switch (rjad)
	{
	case 1:
	{
		std::cout << "Наземный транспорт            ";
	}
	break;
	case 2:
	{
		std::cout << "Воздушный транспорт           ";
	}
	break;
	case 3:
	{
		std::cout << "Наземный и воздушный транспорт";
	}
	break;
	case 4:
	{
		std::cout << "\033[34;42mНаземный транспорт            \033[0m ";
	}
	break;
	case 5:
	{
		std::cout << "\033[34;42mВоздушный транспорт           \033[0m ";
	}
	break;
	case 6:
	{
		std::cout << "\033[34;42mНаземный и воздушный транспорт\033[0m ";
	}
	break;
	default:
	{
		std::cout << "\033[34;42mНаземный транспорт            \033[0m \n";
		std::cout << "Воздушный транспорт\n";
		std::cout << "Наземный и воздушный транспорт ";
		std::cout << "\033[2A";
	}
	break;
	}
}

void Inform(short tipg, bool metka)
{
	char* cvet{ nullptr };
	if (metka)
	{
		cvet = new char[6] { "\033[41m" };
	}
	else
	{
		cvet = new char[1] { "" };
	}

	switch (tipg)
	{
	case 1:
	{
		std::cout << "\033[2F\033[10C";
		std::cout << cvet << "наземного транспорта             \033[0m";
		std::cout << "\033[12D\033[2B";
	}
	break;
	case 2:
	{
		std::cout << "\033[3F\033[10C";
		std::cout << cvet << "воздушного транспорта            \033[0m";
		std::cout << "\033[12D\033[3B";
	}
	break;
	case 3:
	{
		std::cout << "\033[4F\033[10C";
		std::cout << cvet << "наземного и воздушного транспорта\033[0m";
		std::cout << "\033[12D\033[4B";
	}
	break;
	default:
	{
		std::cout << "\rГонка для ";
		std::cout << cvet << "наземного транспорта             \033[0m";
	}
	break;
	}
	delete[] cvet;
	cvet = nullptr;
}

int Vybor_Tipa_Gonki()
{
	std::cout << "\033[5B\033[36C\033[30;42m ВПЕРЕД>> \033[0m";
	std::cout << "\033[5F";

	Inform(false, true);
	int rjad{ 1 };

	std::cout << "\nВыберите тип гонки стрелками:\n";
	Vykl_Podsvetka(0);
	char aaa{ '\0' };
	do
	{
		std::cout << "\033[?25h";
		aaa = _getch();
		std::cout << "\033[?25l";
		if (aaa == -32)
		{
			aaa = _getch();
			if (aaa == 72) // Up
			{
				Vykl_Podsvetka(rjad);
				if (rjad == 1)
				{
					std::cout << "\033[2B";
					rjad = 3;
				}
				else
				{
					std::cout << "\033[1A";
					rjad--;
				}
				Vykl_Podsvetka(rjad + 3);
				Inform(rjad, true);
			}
			else if (aaa == 80) // Вниз
			{
				Vykl_Podsvetka(rjad);
				if (rjad == 3)
				{
					std::cout << "\033[2A";
					rjad = 1;
				}
				else
				{
					std::cout << "\033[1B";
					rjad++;
				}
				Vykl_Podsvetka(rjad + 3);
				Inform(rjad, true);
			}
			else if (aaa == 77)
			{
				aaa = '\r';
			}
		}
	} while (aaa != '\r');
	Inform(rjad, false);
	std::cout << "\033[" << rjad << "A\033[5M";
	return rjad;
}

int Vybor_Rastojnij()
{
	std::cout << "\033[4B\033[30;42m <<НАЗАД  ";
	std::cout << "\033[26C\033[37;48;2;128;128;128m ВПЕРЕД>> \033[0m";
	std::cout << "\033[4F";

	std::cout << "Расстояние: \033[41m    0\033[0mкм.\n";
	std::cout << "Укажите длинну дистанции в километрах: ";
	int dlina{ 0 };
	short buf{ 0 };
	char bbb{ '\0' };
	do
	{
		std::cout << "\033[?25h";
		bbb = _getch();
		std::cout << "\033[?25l";
		if (bbb == -32)
		{
			bbb = _getch();
			if (bbb == 77)  // вперед
			{
				bbb = '\r';
			}
			else if (bbb == 75)  // назад
			{
				std::cout << "\033[2A\033[6M";
				return 100100;
			}
		}
		else if (bbb >= '0' && bbb <= '9' && buf < 5)
		{
			dlina = dlina * 10 + (bbb - '0');
			if (dlina)
			{
				buf++;
				std::cout << bbb;
				std::cout << "\033[1F\033[" << 17 - buf << "C\033[41m" << dlina << "\033[0m";
				std::cout << "\033[1B\033[" << 22 + buf << "C";
			}
			if (buf == 1)
			{
				std::cout << "\033[3E\033[36C\033[30;42m ВПЕРЕД>> \033[0m";
				std::cout << "\033[3A\033[6D";
			}
		}
		else if (bbb == '\b' && buf > 0)
		{
			dlina = dlina / 10;
			buf--;
			std::cout << "\b\033[1P";
			std::cout << "\033[1F\033[" << 16 - buf << "C";
			if (dlina)
			{
				std::cout << "\033[41m" << " " << dlina << "\033[0m";
			}
			else
			{
				std::cout << "\033[41m" << dlina << "\033[0m";
			}
			std::cout << "\033[1B\033[" << 22 + buf << "C";
			if (buf == 0)
			{
				std::cout << "\033[3E\033[36C\033[37;48;2;128;128;128m ВПЕРЕД>> \033[0m";
				std::cout << "\033[3A\033[7D";
			}
		}
	} while (bbb != '\r' || dlina == 0);

	std::cout << "\033[1F\033[11C\033[" << 6 - buf << "X";
	std::cout << "\033[" << 6 - buf << "C" << dlina << "\033[1B";
	std::cout << "\033[4M";
	return dlina;
}

int Nazad_Vpered(int rjad, int maxr, int minr, int mod)
{
	char* cvet_vpered_do{ nullptr };
	char* cvet_vpered_posl{ nullptr };
	int str_vverh{ maxr - minr + 2 };
	int rezul{ 100000 };
	if (mod == 0)
	{
		std::cout << "\033[1B";
		std::cout << "\r\033[30;43m <<НАЗАД  ";
		std::cout << "\033[26C\033[37;48;2;128;128;128m ВПЕРЕД>> \033[0m";
		std::cout << "\033[35D";
		std::cout << "\033[" << str_vverh << "A";
		return 0;
	}
	else if (mod > 0 && mod < 3)
	{
		cvet_vpered_do = new char[23] { "\033[37;48;2;128;128;128m" };
		cvet_vpered_posl = new char[23] { "\033[37;48;2;128;128;128m" };
	}
	else
	{
		cvet_vpered_do = new char[23] { "\033[30;42m" };
		cvet_vpered_posl = new char[23] { "\033[30;43m" };
	}

	std::cout << "\033[" << maxr - rjad + 2 << "B";
	std::cout << "\r\033[30;42m <<НАЗАД  ";
	std::cout << "\033[26C" << cvet_vpered_do << " ВПЕРЕД>> \033[0m";
	std::cout << "\033[35D";

	char aaa{ '\0' };
	do
	{
		std::cout << "\033[?25h";
		aaa = _getch();
		std::cout << "\033[?25l";
		if (aaa == -32)
		{
			aaa = _getch();
			if (aaa == 72) // Up
			{
				std::cout << "\r\033[30;43m <<НАЗАД  ";
				std::cout << "\033[26C" << cvet_vpered_posl << " ВПЕРЕД>> \033[0m";
				std::cout << "\033[2A";
				rezul = 1;
			}
			else if (aaa == 80) // Вниз
			{
				std::cout << "\r\033[30;43m <<НАЗАД  ";
				std::cout << "\033[26C" << cvet_vpered_posl << " ВПЕРЕД>> \033[0m";
				std::cout << "\033[" << str_vverh << "A";
				rezul = 0;
			}
			else if (aaa == 77)  // вперед
			{
				if (mod > 2)
				{
					std::cout << "\033[" << maxr - minr + 3 << "A";
					std::cout << "\033[" << maxr - minr + 5 << "M";
					std::cout << "\033[" << mod << "B\033[1M";
					rezul = 100200;
				}
			}
			else if (aaa == 75)  // назад
			{
				std::cout << "\033[" << maxr - minr + 4 << "A";
				std::cout << "\033[" << maxr - minr + mod + 7 << "M";
				rezul = 100100;
			}
		}
	} while (rezul == 100000);
	delete[] cvet_vpered_do;
	cvet_vpered_do = nullptr;
	delete[] cvet_vpered_posl;
	cvet_vpered_posl = nullptr;
	return rezul;
}

void Vykl_Podsvetka_TC(int num_rjad, bool flag, int ind)
{
	char* svet{ nullptr };
	bool flag2{ false };
	while (ind)
	{
		if (ind % 10 != num_rjad)
		{
			ind = ind / 10;
		}
		else
		{
			flag2 = true;
			break;
		}
	}

	if (flag)
	{
		if (flag2)
		{
			svet = new char[9] { "\033[31;42m" };
		}
		else
		{
			svet = new char[9] { "\033[30;42m" };
		}

	}
	else
	{
		if (flag2)
		{
			svet = new char[9] { "\033[33m" };
		}
		else
		{
			svet = new char[1] { "" };
		}
	}
	std::cout << "\r";
	switch (num_rjad)
	{

	case 1:
	{
		std::cout << svet << "Ботинки-вездеходы\033[0m ";
	}
	break;
	case 2:
	{
		std::cout << svet << "Верблюд          \033[0m ";
	}
	break;
	case 3:
	{
		std::cout << svet << "Верблюд-быстроход\033[0m ";
	}
	break;
	case 4:
	{
		std::cout << svet << "Кентавр          \033[0m ";
	}
	break;
	case 5:
	{
		std::cout << svet << "Ковёр-самолёт    \033[0m ";
	}
	break;
	case 6:
	{
		std::cout << svet << "Метла            \033[0m ";
	}
	break;
	case 7:
	{
		std::cout << svet << "Орёл             \033[0m ";
	}
	break;
	}
	delete[] svet;
	svet = nullptr;
}

void Spisok_TC(int num_rjad, bool flag, int mod, int ind)
{
	std::cout << "\033[2E";
	if (flag)
	{
		if (mod < 3)
		{
			std::cout << "\033[33mЗарегистрированные транспортные средства:\033[0m\n";
			std::cout << "\033[33mЧто-бы снять регистрацию c TC, нажмите стрелку <-.\033[0m\033[1F";
		}

		std::cout << "\033[" << mod - 1 << "E";
		std::cout << "\033[1L";
		switch (num_rjad)
		{
		case 1:
		{
			std::cout << "Ботинки-вездеходы";
		}
		break;
		case 2:
		{
			std::cout << "Верблюд";
		}
		break;
		case 3:
		{
			std::cout << "Верблюд-быстроход";
		}
		break;
		case 4:
		{
			std::cout << "Кентавр";
		}
		break;
		case 5:
		{
			std::cout << "Ковёр-самолёт";
		}
		break;
		case 6:
		{
			std::cout << "Метла";
		}
		break;
		case 7:
		{
			std::cout << "Орёл";
		}
		break;
		}
	}
	else
	{
		if (mod == 1)
		{
			std::cout << "\033[3M";
			std::cout << "\033[1E";
		}
		else
		{
			std::cout << "\033[" << mod - ind << "E";
			std::cout << "\033[1M";
		}
	}
}

void Inform_TC(int rjad, int maxr, int minr, int mod)
{
	if (mod == 0)
	{
		std::cout << "Пожалуйста зарегистрируйте минимум";
		std::cout << "\033[41m 2 \033[0mтранспортных средства.\n";
	}
	else if (mod == 1)
	{
		std::cout << "\033[" << rjad - minr + 1 << "F";
		std::cout << "Пожалуйста зарегистрируйте минимум";
		std::cout << "\033[41m 2 \033[0mтранспортных средства.";
		std::cout << "\033[" << maxr - minr + 3 << "E";
	}
	else if (mod == 2)
	{
		std::cout << "\033[" << rjad - minr + 1 << "F";
		std::cout << "Пожалуйста зарегистрируйте минимум";
		std::cout << "\033[43m 1 \033[0mтранспортное средство.";
		std::cout << "\033[" << maxr - minr + 3 << "E\033[36C";
		std::cout << "\033[37;48;2;128;128;128m ВПЕРЕД>> \033[0m";
	}
	else if (mod == 3 || mod == maxr - minr + 1)
	{
		std::cout << "\033[" << rjad - minr + 1 << "F";
		std::cout << "Можете продолжить регистрацию транспортных средств.        ";
		std::cout << "\033[" << maxr - minr + 3 << "E\033[36C";
		std::cout << "\033[30;43m ВПЕРЕД>> \033[0m";
	}
	else if (mod == maxr - minr + 2)
	{
		std::cout << "\033[" << rjad - minr + 1 << "F";
		std::cout << "Регистрация транспортных средств окончена.         ";
		std::cout << "\033[" << maxr - minr + 3 << "E";
	}
	else
	{
		std::cout << "\033[" << maxr - rjad + 2 << "E";
	}
}

int Vybor_Car(short const tipg)
{

	enum class tip :short {
		Nazem_TC = 1, Vozd_TC = 2, Nazem_Vozd_TC = 3
	}TIP_TC{ static_cast<tip>(tipg) };
	int rjad{ 1 }, maxr{ 7 }, minr{ 1 }, mod{ 0 };
	int ind{ 0 };

	Inform_TC(rjad, maxr, minr, mod);
	switch (TIP_TC)
	{
	case tip::Nazem_TC:
	{
		maxr = 4;
		std::cout << "Ботинки-вездеходы\n";
		std::cout << "Верблюд\n";
		std::cout << "Верблюд-быстроход\n";
		std::cout << "Кентавр\n";
	}
	break;
	case tip::Vozd_TC:
	{
		rjad = minr = 5;
		std::cout << "Ковёр-самолёт\n";
		std::cout << "Метла\n";
		std::cout << "Орёл\n";
	}
	break;
	case tip::Nazem_Vozd_TC:
	{
		std::cout << "Ботинки-вездеходы\n";
		std::cout << "Верблюд\n";
		std::cout << "Верблюд-быстроход\n";
		std::cout << "Кентавр\n";
		std::cout << "Ковёр-самолёт\n";
		std::cout << "Метла\n";
		std::cout << "Орёл\n";
	}
	break;
	}
	Nazad_Vpered(rjad, maxr, minr, mod);

	Vykl_Podsvetka_TC(rjad, true, ind);
	char aaa{ '\0' };
	mod = 1;
	do
	{
		std::cout << "\033[?25h";
		aaa = _getch();
		std::cout << "\033[?25l";
		if (aaa == -32)
		{
			aaa = _getch();
			if (aaa == 72) // Up
			{
				Vykl_Podsvetka_TC(rjad, false, ind);
				if (rjad == minr)
				{
					int chto = Nazad_Vpered(rjad, maxr, minr, mod);
					if (chto)
					{
						rjad = maxr;
					}
					if (chto == 100100)
					{
						return 100100;
					}
					if (chto == 100200)
					{
						std::cout << "\n";
						return ind;
					}
				}
				else
				{
					std::cout << "\033[1A";
					rjad--;
				}
				Vykl_Podsvetka_TC(rjad, true, ind);
			}
			else if (aaa == 80) // Вниз
			{
				Vykl_Podsvetka_TC(rjad, false, ind);
				if (rjad == maxr)
				{
					int chto = Nazad_Vpered(rjad, maxr, minr, mod);
					if (!chto)
					{
						rjad = minr;
					}
					if (chto == 100100)
					{
						return 100100;
					}
					if (chto == 100200)
					{
						std::cout << "\n";
						return ind;
					}
				}
				else
				{
					std::cout << "\033[1B";
					rjad++;
				}
				Vykl_Podsvetka_TC(rjad, true, ind);
			}
			else if (aaa == 77)  // вперед
			{
				int cvet{ ind };
				while (cvet)
				{
					if (cvet % 10 != rjad)
					{
						cvet = cvet / 10;
					}
					else break;
				}
				if (!cvet)
				{
					ind = ind * 10 + rjad;
					Vykl_Podsvetka_TC(rjad, true, ind);
					mod++;
					Inform_TC(rjad, maxr, minr, mod);
					Spisok_TC(rjad, true, mod, 0);
					std::cout << "\033[" << maxr - rjad + mod + 3 << "F\033[18C";
				}
			}
			else if (aaa == 75)  // назад
			{
				int cof{ 0 };
				int cvet{ ind };
				while (cvet)
				{
					if (cvet % 10 != rjad)
					{
						cvet = cvet / 10;
						cof++;
					}
					else break;
				}
				if (cvet)
				{
					int plus{ 1 };
					for (int i = 0; i < cof; i++)
					{
						plus *= 10;
					}
					ind = cvet / 10 * plus + ind % plus;
					Vykl_Podsvetka_TC(rjad, true, ind);
					mod--;
					Inform_TC(rjad, maxr, minr, mod);
					Spisok_TC(rjad, false, mod, cof);
					std::cout << "\033[" << maxr - rjad + mod - cof + 4 << "F\033[18C";
				}
			}
		}
	} while (true);
	return ind;
}

void Vykl_Podsvetka_Gonka(int rjad)
{
	std::cout << "\r";
	switch (rjad)
	{
	case 1:
	{
		std::cout << "Провести гонку мгновенно      ";
	}
	break;
	case 2:
	{
		std::cout << "Провести гонку с визуализацией";
	}
	break;
	case 3:
	{
		std::cout << "Вернуться к регистрации ТС    ";
	}
	break;
	case 4:
	{
		std::cout << "\033[34;42mПровести гонку мгновенно      \033[0m ";
	}
	break;
	case 5:
	{
		std::cout << "\033[34;42mПровести гонку с визуализацией\033[0m ";
	}
	break;
	case 6:
	{
		std::cout << "\033[34;42mВернуться к регистрации ТС    \033[0m ";
	}
	break;
	default:
	{
		std::cout << "\033[34;42mПровести гонку мгновенно      \033[0m \n";
		std::cout << "Провести гонку с визуализацией\n";
		std::cout << "Вернуться к регистрации ТС     ";
		std::cout << "\033[2A";
	}
	break;
	}
}

void Nazad(int carR)
{
	int col{ 0 };
	while (carR % 10)
	{
		carR = carR / 10;
		col++;
	}
	std::cout << "\033[" << col + 4 << "A\033[" << col + 5 << "M";
}

int Vybor_Gonki(int const carR)
{
	int rjad{ 1 };
	Vykl_Podsvetka_Gonka(0);
	char aaa{ '\0' };
	do
	{
		std::cout << "\033[?25h";
		aaa = _getch();
		std::cout << "\033[?25l";
		if (aaa == -32)
		{
			aaa = _getch();
			if (aaa == 72) // Up
			{
				Vykl_Podsvetka_Gonka(rjad);
				if (rjad == 1)
				{
					std::cout << "\033[2B";
					rjad = 3;
				}
				else
				{
					std::cout << "\033[1A";
					rjad--;
				}
				Vykl_Podsvetka_Gonka(rjad + 3);
			}
			else if (aaa == 80) // Вниз
			{
				Vykl_Podsvetka_Gonka(rjad);
				if (rjad == 3)
				{
					std::cout << "\033[2A";
					rjad = 1;
				}
				else
				{
					std::cout << "\033[1B";
					rjad++;
				}
				Vykl_Podsvetka_Gonka(rjad + 3);
			}
			else if (aaa == 77)  // вперед
			{
				aaa = '\r';
			}
			else if (aaa == 75 && rjad == 3)  // назад
			{
				Nazad(carR);
				return 100100;
			}
		}
		if (aaa == '\r')
		{
			switch (rjad)
			{
			case 1:
			{
				std::cout << "\033[3M";
				return 1;
			}
			break;
			case 2:
			{
				std::cout << "\033[1A\033[3M";
				return 2;
			}
			break;
			case 3:
			{
				Nazad(carR);
				return 100100;
			}
			break;
			}
		}
	} while (aaa != '\r');
	return 0;
}

void Vykl_Podsvetka_Exit(int rjad)
{
	std::cout << "\r";
	switch (rjad)
	{
	case 1:
	{
		std::cout << "Провести ещё одну гонку";
	}
	break;
	case 2:
	{
		std::cout << "         Выйти         ";
	}
	break;
	case 3:
	{
		std::cout << "\033[34;42mПровести ещё одну гонку\033[0m ";
	}
	break;
	case 4:
	{
		std::cout << "\033[34;42m         Выйти         \033[0m ";
	}
	break;
	default:
	{
		std::cout << "\n\033[34;42mПровести ещё одну гонку\033[0m \n";
		std::cout << "         Выйти          ";
		std::cout << "\033[1A";
	}
	break;
	}
}

const char* Cislo_Wo_Wrema(int t)
{
	static char str[15]{ "  0:00:00:00" };
	for (int i = 4; i > 0; i = i - 3)
	{
		str[7 + i] = t % 10 + '0';
		t /= 10;
		t = t - 6 * (t / 6) + (t / 6) * 10;
		str[6 + i] = t % 10 + '0';
		t /= 10;
	}
	t = t - 24 * (t / 24) + (t / 24) * 100;
	str[5] = t % 10 + '0';
	t /= 10;
	str[4] = t % 10 + '0';
	t /= 10;
	str[2] = t % 10 + '0';
	t /= 10;
	if (t) str[1] = t % 10 + '0';
	else str[1] = ' ';
	t /= 10;
	if (t) str[0] = t % 10 + '0';
	else str[0] = ' ';
	return str;
}

void Rezultaty_gonki(int const carR, int const dist, int const rezul)
{
	Gonka NFS(carR, dist);
	int size{ NFS.Participant_Size() };
	std::cout << "\t\033[33mРезультаты гонки:\033[0m\n";
	if (rezul == 1)
	{
		std::cout << "\033[31Cчасов:\n";
	}
	else
	{
		std::cout << "\033[33Cд:чч:мм:сс\n";
	}

	for (int i = 0; i < size; i++)
	{
		std::cout << NFS.Participant_Name(i) << "\tВремя: ";
		if (rezul == 1)
		{
			std::cout << NFS.Participant_Time(i) << std::endl;
		}
		else
		{
			std::cout << Cislo_Wo_Wrema(static_cast<int>(NFS.Participant_Time(i) * 3600)) << std::endl;
		}
	}
}

void Broadcast_gonki(int const carR, int const dist)
{
	struct Ind_Time { int ind; float rezul_; };

	Broadcast_Gonki spotrTV(carR, dist);
	int size{ spotrTV.Participant_Size() };

	Ind_Time* ind_T = new Ind_Time[size];

	const char* label{ nullptr };
	float min_rezul{ spotrTV.Participant_Time(0) };
	float max_rezul{ min_rezul };
	float min_dist{ static_cast<float>(dist) / 30 };
	std::cout << "\033[" << size + 1 << "A";
	std::cout << "\033[18C";
	/////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < size; i++)
	{
		ind_T[i].ind = 1;
		ind_T[i].rezul_ = spotrTV.Participant_Time(i);
		if (min_rezul > ind_T[i].rezul_)
		{
			min_rezul = ind_T[i].rezul_;
		}
		if (max_rezul < ind_T[i].rezul_)
		{
			max_rezul = ind_T[i].rezul_;
		}
		label = spotrTV.Participant_Label(i);
		std::cout << "\033[30;42m" << label << "\033[0m\033[" << 30 << "C|cas";
		std::cout << "\033[1E\033[18C";
	}
	std::cout << "\033[34C" << Cislo_Wo_Wrema(0);
	float vrema_gonki{ 0.0 };
	/////////////////////////////////////////////////////////////////
	for (int i = 1; vrema_gonki < max_rezul; i++)
	{
		if (vrema_gonki <= max_rezul - min_rezul / 30)
		{
			vrema_gonki = min_rezul / 30 * i;
		}
		else vrema_gonki = max_rezul;

		Sleep(300);
		std::cout << "\033[" << size << "F\033[18C";
		for (int j = 0; j < size; j++)
		{
			double dist_etap = spotrTV.Run_Time(j, vrema_gonki);
			if (dist_etap <= dist + min_dist)
			{
				float dist_etalon = min_dist * ind_T[j].ind;
				if (dist_etap >= dist_etalon)
				{
					int koef_dvisch = static_cast<int>((dist_etap - dist_etalon) / min_dist);
					int dvisch = 1 + koef_dvisch;
					if (koef_dvisch)
					{
						ind_T[j].ind++;
					}
					ind_T[j].ind++;
					std::cout << "\033[" << 33 << "C    ";
					std::cout << "\033[" << 37 << "D";
					std::cout << "\033[" << dvisch << "@";
					if (dist_etap >= dist)
					{
						std::cout << "\033[" << 33 << "C|" << Cislo_Wo_Wrema(static_cast<int>(ind_T[j].rezul_ * 3600));
					}
					else std::cout << "\033[" << 33 << "C|cas";
				}
			}
			std::cout << "\033[1E\033[18C";
		}
		std::cout << "\033[34C" << Cislo_Wo_Wrema(static_cast<int>(vrema_gonki * 3600));
	}
	Sleep(1000);
	delete[] ind_T;
	ind_T = nullptr;
	std::cout << std::endl;
}

bool Menu_Exit(int const carR)
{
	int car{ carR };
	int size{ 0 };
	do size++;
	while (car /= 10);

	int rjad{ 1 };
	Vykl_Podsvetka_Exit(0);
	char aaa{ '\0' };
	do
	{
		std::cout << "\033[?25h";
		aaa = _getch();
		std::cout << "\033[?25l";
		if (aaa == -32)
		{
			aaa = _getch();
			if (aaa == 72) // Up
			{
				Vykl_Podsvetka_Exit(rjad);
				if (rjad == 1)
				{
					std::cout << "\033[1B";
					rjad = 2;
				}
				else
				{
					std::cout << "\033[1A";
					rjad--;
				}
				Vykl_Podsvetka_Exit(rjad + 2);
			}
			else if (aaa == 80) // Вниз
			{
				Vykl_Podsvetka_Exit(rjad);
				if (rjad == 2)
				{
					std::cout << "\033[1A";
					rjad = 1;
				}
				else
				{
					std::cout << "\033[1B";
					rjad++;
				}
				Vykl_Podsvetka_Exit(rjad + 2);
			}
			else if (aaa == 77)
			{
				aaa = '\r';
			}
		}
	} while (aaa != '\r');

	bool rezul{ false };
	if (rjad == 1)
	{
		std::cout << "\033[" << size * 2 + 7 << "A";
		std::cout << "\033[" << size * 2 + 9 << "M";
		rezul = true;
	}
	return rezul;
}