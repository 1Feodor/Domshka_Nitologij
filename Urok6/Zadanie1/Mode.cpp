#include <iostream>
#include <Windows.h>

//#define  MODE 0

#ifndef MODE
#error MODE must be defined!
#endif // define MODE

#if MODE == 1
int add(int a, int b)
{
	return a + b;
}
#endif // MODE == 1

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#if MODE == 0
	std::cout << "Работаю в режиме тренировки\n";
#elif MODE == 1
	std::cout << "Работаю в боевом режиме\n";
	std::cout << "Введите число 1: ";
	int a = 0;
	std::cin >> a;
	std::cout << "Введите число 2: ";
	int b = 0;
	std::cin >> b;
	std::cout << "Результат сложения: " << add(a, b) << "\n";
#else
	std::cout << "Неизвестный режим.Завершение работы\n";
	
#endif // MODE
	return 0;
}	