#include <iostream>
#include <Windows.h>

void print_dynamic_array(int*, int, int);

int main()
{
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	int capacity{ 0 };
	int size{ 0 };

	std::cout << "Введите фактичеcкий размер массива: ";
	std::cin >> capacity;
	
	std::cout << "Введите логический размер массива: ";
	std::cin >> size;


	if (size > capacity)
	{
		std::cout << "Ошибка! Логический размер массива не может превышать фактический!\n";
		return 1;
		capacity = size;
	}
	
	int* arr = new int[capacity] {0};

	for (int i = 0; i < size; ++i)
	{
		std::cout << "Введите arr[" << i << "]: ";
		std::cin >> *(arr + i);
	}

	std::cout << "Динамический массив: ";

	print_dynamic_array(arr, size, capacity);
	std::cout << std::endl;

	delete[] arr;
	return 0;
}

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
	for (int* i = arr; i < arr + actual_size; ++i)
	{
		i < arr + logical_size ? std::cout << *i << " " : std::cout << "_" << " ";
	}
}
