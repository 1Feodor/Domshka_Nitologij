#include <iostream>
#include <Windows.h>
#include <algorithm>

void merge_sort(int* arr, int size);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int arr[]{ 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
	//int arr[]{ 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
	//int arr[]{ 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
	int size{sizeof(arr) / sizeof(arr[0])};

	std::cout << "Исходный массив: \t";
	std::for_each(std::begin(arr), std::end(arr), [](int i) 
		{
			std::cout << i << " ";
		});
	std::cout << std::endl;

	merge_sort(arr, size);

	std::cout << "Отсортированный массив: ";
	std::for_each(std::begin(arr), std::end(arr), [](int i)
		{
			std::cout << i << " ";
		});
	std::cout << std::endl;
	
	return 0;
}

void merge_sort(int* arr, int size)
{
	if (size < 1)
	{
		throw std::exception("error: int size < 1!!!");
	}
	if (size == 1) return;
	
	int* arrey1 = new int[size / 2] {0};
	int* arrey2 = new int[size - size / 2] {0};
	for (int i = 0; i < size; i++)
	{
		if (i < size / 2) arrey1[i] = arr[i];
		else arrey2[i - size / 2] = arr[i];
	}

	merge_sort(arrey1, size / 2);
	merge_sort(arrey2, size - size / 2);

	int sizeArrey1{ 0 };
	int sizeArrey2{ 0 };
	for (int sizeArr{ 0 }; sizeArrey1 < size / 2 || sizeArrey2 < size - size / 2; ++sizeArr)
	{
		if (sizeArrey1 == size / 2)
		{
			arr[sizeArr] = arrey2[sizeArrey2];
			++sizeArrey2;
		}
		else if (sizeArrey2 == size - size / 2)
		{
			arr[sizeArr] = arrey1[sizeArrey1];
			++sizeArrey1;
		}
		else
		{
			if (arrey1[sizeArrey1] <= arrey2[sizeArrey2])
			{
				arr[sizeArr] = arrey1[sizeArrey1];
				++sizeArrey1;
			}
			else
			{
				arr[sizeArr] = arrey2[sizeArrey2];
				++sizeArrey2;
			}
		}
	}
	delete[] arrey1, arrey2;
}