#include <iostream>
#include <Windows.h>
#include <vector>

template<typename T>
T Squaring(T value) {return value * value;}

template <class T>
std::vector<T> Squaring(const std::vector<T>& vec)
{
	std::vector<T> vec1;
	for (auto i = vec.begin(); i != vec.end(); i++)
	{
		vec1.push_back(*i * *i);
	}
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
	
	std::cout << Squaring(4) << std::endl;
	printVec(Squaring(std::vector<int>{ 4,5,6,-1 }));

	return 0;
}