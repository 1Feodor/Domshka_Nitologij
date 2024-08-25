#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <functional>

void count_sort(int* arr, int size);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int arr[]{ 19,14,22,22,17,22,13,21,20,24,18,10,17,16,17,20,22,11,20,16,14,13,10,22,18,14,16,24,19,17 };
	//int arr[]{ 16,17,14,20,22,20,17,22,16,19,23,24,20,22,21,18,14,16,17,21,10,11,19,23,11,11,17,17,11,21,17,11,17,16,12,11,16,22,23,16 };
	//int arr[]{ 21,15,19,18,23,12,18,18,19,23,12,20,15,22,21,18,19,20,12,16,20,14,17,13,10,23,19,14,10,22,19,12,24,23,22,15,13,22,18,18,11,23,24,17,10 };
	int size{ sizeof(arr) / sizeof(arr[0]) };

	std::cout << "Исходный массив: \t";
	std::for_each(std::begin(arr), std::end(arr), [](int i)
		{
			std::cout << i << " ";
		});
	std::cout << std::endl;

	count_sort(arr, size);

	std::cout << "Отсортированный массив: ";
	std::for_each(std::begin(arr), std::end(arr), [](int i)
		{
			std::cout << i << " ";
		});
	std::cout << std::endl;

	std::cout << "fff";
	return 0;
}

void count_sort(int* arr, int size)
{
	if (size < 1)
	{
		throw std::exception("error: int size < 1!!!");
	}

	if (size == 1) return;
	int* bufer = new int[14]{ 0 };
	for (int i = 0; i < size; i++)
	{
		++bufer[arr[i] - 10];
	}

	int j{ 0 };

	for (int i = 0; i < size; i++)
	{
		while (!bufer[j])
		{
			++j;
		}
		arr[i] = j + 10;
		--bufer[j];
	}

	delete[] bufer;
}