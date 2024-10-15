#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>


int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	std::cout << "Укажите размер массива: ";
	unsigned int vector_size{ 0 };
	std::cin >> vector_size;

	std::vector<int> myvec(vector_size);
	std::cout << "Укажите значения элементов:\n";
	for (unsigned int i = 0; i < vector_size; i++)
	{
		std::cout << "arr[" << i << "] = ";
		int val = 0;
		std::cin >> val;
		myvec.at(i) = val;
	}

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