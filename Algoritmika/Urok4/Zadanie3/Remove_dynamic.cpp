#include <iostream>
#include <Windows.h>
#include <string>


int* remove_dynamic_array_head(int*, int*, int*);
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

	std::string value{ "\0" };

	do
	{
		std::cout << "Удалить первый элемент? ";
		std::cin >> value;
		if (value == "нет")
		{
			std::cout << "Спасибо! Ваш динамический массив: ";

			print_dynamic_array(arr, size, capacity);
			std::cout << std::endl;
			break;
		}
		if (!size)
		{
			std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!";
			break;
		}
		std::cout << "Динамический массив: ";

		arr = remove_dynamic_array_head(arr, &size, &capacity);

		print_dynamic_array(arr, size, capacity);
		std::cout << std::endl;
	} while (true);

	delete[] arr;
	return 0;
}

int* remove_dynamic_array_head(int* arr, int* logical_size, int* actual_size)
{
	--*logical_size;
	
	if (*actual_size / 3 >= *logical_size && *actual_size / 3)
	{
		*actual_size /= 3;
		int* arr1 = new int[*actual_size] {0};
		for (int i = 0; i < *actual_size; i++)
		{
			arr1[i] = arr[i + 1];
		}
		delete[] arr;
		arr = arr1;
		arr1 = nullptr;
	}
	else
	{
		for (int i = 0; i < *logical_size; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[*logical_size] = 0;
	}
	return arr;
}

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
	for (int* i = arr; i < arr + actual_size; ++i)
	{
		i < arr + logical_size ? std::cout << *i << " " : std::cout << "_" << " ";
	}
}