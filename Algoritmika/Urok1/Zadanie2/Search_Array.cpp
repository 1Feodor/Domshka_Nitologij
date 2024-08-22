#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

template<class T>
void printArrei(T* arr)
{
	for (auto i : *arr)
	{
		std::cout << i << " ";
	}
}

template <>
void printArrei(const char* arr)
{
	for (auto i = arr; *i != '\0'; ++i)
	{
		std::cout << *i << " ";
	}
}

template <class T>
void printArrei(T* arr, const int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << *(arr + i) << " ";
	}
}

///////////////////////////////////////////////

template <class T>
int moreThan(T* arr, const T st_point, int size)
{
	if (size < 1)
	{
		throw std::exception("error: int size < 1!!!");
	}
	int index_end{ size - 1 };
	int index_begin{ 0 };
	int index{ (index_end + index_begin) / 2 };

	if (st_point >= *(arr + index_begin)) return 0;
	if (st_point < *(arr + index_end)) return size;

	while (*(arr + index_end) != *(arr + index_begin + 1) || *(arr + index_end - 1) != *(arr + index_begin))
	{
		st_point >= *(arr + index) ? index_end = index : index_begin = index;
		index = (index_end + index_begin) / 2;
	}
	return index_end;
}

template <class T, class T1>
int moreThan(T* arr, const T1 st_point)
{
	if (arr->size() < 1)
	{
		throw std::exception("error: int size < 1!!!");
	}
	auto itBeg{ arr->cbegin() };
	auto itEnd{ arr->crbegin() };

	if (st_point >= *itBeg) return 0;
	if (st_point < *itEnd) return arr->size();

	auto index_end{ arr->size() - 1 };
	auto index_begin{ 0 };
	auto index{ (index_end + index_begin) / 2 };

	auto itBeg1{ arr->cbegin() };
	++itBeg1;
	auto itEnd1{ arr->crbegin() };
	++itEnd1;
	auto it{ arr->cbegin() };
	std::advance(it, index);
	
	while (*itEnd != *itBeg1 || *itEnd1 != *itBeg)
	{
		if (st_point >= *it)
		{
			std::advance(itEnd, index_end - index);
			std::advance(itEnd1, index_end - index);
			index_end = index;
		}
		else
		{
			std::advance(itBeg, index - index_begin);
			std::advance(itBeg1, index - index_begin);
			index_begin = index;
		}
		index = (index_end + index_begin) / 2;
		it = arr->cbegin();
		std::advance(it, index);
	}
	return index_end;
}

//template <class T, class T1>
//int moreThan(T* arr, const T1 st_point)
//{
//	if (arr->size() < 1)
//	{
//		throw std::exception("error: int size < 1!!!");
//	}
//	auto it{ arr->begin() };
//
//	auto index_end{ arr->size() - 1 };
//	auto index_begin{ 0 };
//	auto index{ (index_end + index_begin) / 2 };
//	if (st_point >= arr->at(index_begin)) return 0;
//	if (st_point < arr->at(index_end)) return arr->size();
//
//	while (arr->at(index_end) != arr->at(index_begin + 1) || arr->at(index_end - 1) != arr->at(index_begin))
//	{
//		st_point >= arr->at(index) ? index_end = index : index_begin = index;
//		index = (index_end + index_begin) / 2;
//	}
//	return index_end;
//}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::list<int> mylist{ 14, 16, 19, 32, 32, 32, 56, 69, 72,3,2,1 };

	mylist.sort();
	mylist.reverse();
	printArrei(&mylist);
	std::cout << std::endl;
	
	int starting_point5{ 0 };
	std::cout << "Введите точку отсчёта: ";
	std::cin >> starting_point5;

	int rezul5{ moreThan(&mylist, starting_point5) };
	std::cout << "Количество элементов в массиве больших, чем " << starting_point5 << ": " << rezul5 << " \n";

	//////////////////////////////////////////////////////////////////

	int arr1[]{ 14, 16, 19, 32, 32, 32, 56, 69, 72,3,2,1};
	int size{ static_cast<int>(sizeof arr1 / sizeof arr1[0]) };

	std::sort(arr1, arr1 + size, [](int a, int b)
		{
			return a > b;
		});
	printArrei(arr1, size);
	std::cout << std::endl;

	int starting_point{ 0 };
	std::cout << "Введите точку отсчёта: ";
	std::cin >> starting_point;

	int rezul{ moreThan(arr1, starting_point, size) };
	std::cout<< "Количество элементов в массиве больших, чем " << starting_point << ": " << rezul << " \n";

	////////////////////////////////////////////////////////////////////////

	std::string str[]{ "aaa","bbb","ccc","ddd","iii" };
	int size1{ static_cast<int>(sizeof str / sizeof str[0]) };

	std::sort(str, str + size1, [](std::string a, std::string b)
		{
			return a > b;
		});

	printArrei(str, size1);
	std::cout << std::endl;

	std::string starting_point1{ "\0" };
	std::cout << "Введите точку отсчёта: ";
	std::cin >> starting_point1;

	int rezul1{ moreThan(str, starting_point1, size1) };
	std::cout << "Количество элементов в массиве больших, чем " << starting_point1 << ": " << rezul1 << " \n";

	/////////////////////////////////////////////////////////////////////

	std::vector<int>myvector{ 14, 16, 19, 32, 32, 32, 56, 69, 72,3,2,1 };

	std::sort(myvector.begin(), myvector.end(),[](int a, int b)
		{
			return a > b;
		});

	printArrei(&myvector);
	std::cout << std::endl;

	int starting_point2{ 0 };
	std::cout << "Введите точку отсчёта: ";
	std::cin >> starting_point2;

	int rezul2{ moreThan(&myvector, starting_point2)};
	std::cout << "Количество элементов в массиве больших, чем " << starting_point2 << ": " << rezul2 << " \n";

	//////////////////////////////////////////////////////////

	std::string charr{ "string" };
	
	std::sort(charr.begin(), charr.end(), [](char a, char b)
		{
			return a > b;
		});

	printArrei(&charr);
	std::cout << std::endl;

	while (std::cin.get() != '\n') continue;
	char ch{ '\0' };
	std::cout << "Введите точку отсчёта: ";
	ch = std::cin.get();
	while (std::cin.get() != '\n') continue;
	
	int rezul3{ moreThan(&charr, ch)};
	std::cout << "Количество элементов в массиве больших, чем " << ch << ": " << rezul3 << " \n";

	//printArrei("arr555");
	
	return 0;
}