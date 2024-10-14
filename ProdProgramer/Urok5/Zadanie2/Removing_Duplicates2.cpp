#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>


int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	
	std::vector<int> myvec(std::istream_iterator<int>{std::cin}, std::istream_iterator<int>{});

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