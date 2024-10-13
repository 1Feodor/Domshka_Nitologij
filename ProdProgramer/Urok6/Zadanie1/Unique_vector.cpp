#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>

template <class T>
std::vector<T> Unique_vector(const std::vector<T>& vec)
{
	std::vector<T> vec1{ vec };
	std::sort(vec1.begin(), vec1.end());
	auto it = std::unique(vec1.begin(), vec1.end());
	vec1.erase(it, vec1.end());
	return vec1;
}

///////////////////////////////////////

template<class T>
void printVec(const std::vector<T>& arr)
{
	for (auto i : arr) std::cout << i << " ";
}

////////////////////////////////////////////////////

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	std::vector<int> test{ 1, 1, 2, 5, 6, 1, 2, 4 };
	printVec(test);
	std::cout << "\n";
	printVec(Unique_vector(test));

	return 0;
}