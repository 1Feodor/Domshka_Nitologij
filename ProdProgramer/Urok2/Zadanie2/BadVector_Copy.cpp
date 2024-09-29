#include <iostream>
#include <Windows.h>

class smart_array
{
public:
	smart_array(int);
	smart_array(const smart_array&);
	~smart_array();
	void add_element(int);
	int get_element(int);
	smart_array& operator = (const smart_array&);
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

smart_array::smart_array(const smart_array& other)
{
	this->capacity = other.capacity;
	this->size = other.size;
	this->arr = new int[this->capacity];
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = other.arr[i];
	}
}

smart_array::~smart_array()
{
	if (this->arr != nullptr)
	{
		delete[] this->arr;
		this->arr = nullptr;
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
	this->capacity += 5;
	int* arr1 = new int[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		arr1[i] = this->arr[i];
	}
	delete[] this->arr;
	this->arr = arr1;
	arr1 = nullptr;
}

smart_array& smart_array::operator=(const smart_array& other)
{
	if (this->arr != nullptr)
	{
		delete[] this->arr;
	}
	this->capacity = other.capacity;
	this->size = other.size;
	this->arr = new int[this->capacity];
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = other.arr[i];
	}
	return *this;
}

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	smart_array arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);

	smart_array new_array(2);
	new_array.add_element(44);
	new_array.add_element(34);

	arr = new_array;
	//smart_array new_array2 = arr;
	return 0;
}