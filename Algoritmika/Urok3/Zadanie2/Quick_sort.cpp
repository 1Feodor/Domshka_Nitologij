#include <iostream>
#include <Windows.h>
#include <algorithm>

void quick_sort(int* arr, int size);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int arr[]{ 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
	//int arr[]{ 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
	//int arr[]{ 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
	int size{ sizeof(arr) / sizeof(arr[0]) };

	std::cout << "Исходный массив: \t";
	std::for_each(std::begin(arr), std::end(arr), [](int i)
		{
			std::cout << i << " ";
		});
	std::cout << std::endl;

	quick_sort(arr, size);

	std::cout << "Отсортированный массив: ";
	std::for_each(std::begin(arr), std::end(arr), [](int i)
		{
			std::cout << i << " ";
		});
	std::cout << std::endl;

	return 0;
}
 
void quick_sort(int* arr, int size)
{
	if (size < 1)
	{
		throw std::exception("error: int size < 1!!!");
	}
	
	if (size == 1) return;
	else if (size == 2)
	{
		if (arr[0] > arr[1])
		{
			std::swap(arr[0], arr[1]);
		}
		return;
	}
	
	int beg{ 0 };
	int end{ size - 1 };
	int pivot{ arr[size / 2] };
	
	while (true )
	{
		while (arr[beg] < pivot)
		{
			++beg;
		}

		while (arr[end] > pivot)
		{
			--end;
		}
		
		if (beg < end)
		{
			if (arr[beg] != arr[end])
			{
				std::swap(arr[beg], arr[end]);
			}
			++beg;
			--end;
		}
		else
		{
			break;
		}
	}

	if (beg)
	{
		quick_sort(arr, beg);
	}

	if (size - beg)
	{
		quick_sort(arr + beg, size - beg);
	}
}