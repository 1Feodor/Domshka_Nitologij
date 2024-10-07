#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <list>

template<typename T>
void Squaring(T& value)
{
	value *= value;
}

template <class T>
void Squaring(T* arr)
{
	for (auto i = arr->begin(); i != arr->end(); i++)
	{
		*i *= *i;
	}
}

template <>
void Squaring(std::string* arr)
{
	arr->append(" в квадрате.");
}

///////////////////////////////////////

template<class T>
void printArrei(T* arr)
{
	for (auto i : *arr)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

template<>
void printArrei(std::string* arr)
{
	std::cout << *arr << std::endl;
}

////////////////////////////////////////////////////

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	int aaa{ 4 };
	std::list<int> mylist{ 3,2,1 };
	std::vector<int> myvector{ 4,5,6 };
	std::string mystring{ "string" };

	Squaring(aaa);
	Squaring(&mylist);
	Squaring(&myvector);
	Squaring(&mystring);

	std::cout << aaa << std::endl;

	printArrei(&mylist);
	printArrei(&myvector);
////// для кириллицы, почему-то, нужно собрать на х86 платформе (на х64 кириллицу не видно)
	std::cout << mystring << std::endl;
	printArrei(&mystring);

	return 0;
}