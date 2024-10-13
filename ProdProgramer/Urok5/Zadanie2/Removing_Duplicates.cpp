#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <algorithm>

int mask_number_Consol();

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
//////////////////////////////////////////////////////////
	std::vector<int> myvec;								//
														//
	std::cout << "Укажите размер массива: ";			//
	int size{ mask_number_Consol() };					//
														//
	std::cout << "Укажите значения элементов:\n";		//
	for (int i = 0; i < size; i++)						//
	{													//
		std::cout << "arr[" << i << "] = ";				//
		myvec.push_back(mask_number_Consol());			//
	}													//
//////////////////////////////////////////////////////////
	/*std::vector<int> myvec{1,5,1,3,4,4};
	std::cout << myvec.size() << "\n";
	for (auto i : myvec)
	{
		std::cout << i << "\n";
	}*/
//////////////////////////////////////////////////////////
	std::cout << "\n";
	std::sort(myvec.begin(), myvec.end(), [](int a, int b) {return a > b; });
	auto it = std::unique(myvec.begin(), myvec.end());
	myvec.erase(it, myvec.end());
	for (auto i : myvec)
	{
		std::cout << i << "\n";
	}
	return 0;
}


int mask_number_Consol()
{
	int number{ 0 };
	short buf{ 0 };
	char chr{ '\0' };
	do
	{
		chr = _getch();
		if (chr >= '0' && chr <= '9' && buf < 5)
		{
			number = number * 10 + (chr - '0');
			if (number)
			{
				buf++;
				std::cout << chr;
			}
		}
		else if (chr == '\b' && buf > 0)
		{
			number = number / 10;
			buf--;
			std::cout << "\b\033[1P";
		}
	} while (chr != '\r' || number == 0);
	std::cout << "\n";
	return number;
}
