#include <iostream>
#include <Windows.h>

class smart_array
{
public:

	smart_array(int);
	~smart_array();
	void add_element(int);
	int get_element(int);
private:
	int capacity;
	int size{ 0 };
	int* arr{ nullptr };
	void increased_capacity();
};

smart_array::smart_array(int capacity) : capacity{ capacity }
{
	if (this->capacity < 1)
	{
		throw std::exception("Error: capacity < 1");
	}
	this->arr = new int[this->capacity];
}

smart_array::~smart_array()
{
	if (arr != nullptr)
	{
		delete[] arr;
	}
}

void smart_array::add_element(int value)
{
	if (this->size >= this->capacity)
	{
		increased_capacity();
	}
	this->arr[this->size] = value;
	++this->size;
}

int smart_array::get_element(int ind)
{
	if (ind < 0 || ind >= this->size)
	{
		throw std::exception("Error: index outside the array!");
	}
	return arr[ind];
}

void smart_array::increased_capacity()
{
	int* arr1 = new int[this->capacity + 5];
	for (int i = 0; i < this->size; i++)
	{
		arr1[i] = this->arr[i];
	}
	delete[] arr;
	this->arr = arr1;
	arr1 = nullptr;
}

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		//arr.add_element(-15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}