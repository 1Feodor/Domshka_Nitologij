#include <iostream>
#include <Windows.h>

template<class T>
class easyVector
{
public:
	easyVector();
	~easyVector();
	void push_back(T);
	T& at(int);
	int getSize()const;
	int getCapacity()const;
private:
	int size{ 0 };
	int capacity{ 5 };
	T* arr{ nullptr };
};

template<class T>
easyVector<T>::easyVector()
{
	this->arr = new T[this->capacity];
}

template<class T>
easyVector<T>::~easyVector()
{
	if (this->arr != nullptr)
	{
		delete[]this->arr;
		this->arr = nullptr;
	}
}

template<class T>
void easyVector<T>::push_back(T value)
{
	if (this->size >= this->capacity)
	{
		this->capacity += 5;
		T* arr1 = new T[this->capacity];
		for (int i = 0; i < this->size; i++)
		{
			arr1[i] = this->arr[i];
		}
		delete[]this->arr;
		this->arr = arr1;
		arr1 = nullptr;
	}
	this->arr[this->size] = value;
	++this->size;
}

template<class T>
T& easyVector<T>::at(int index)
{
	if (index < 0 || index >= this->size)
	{
		throw std::exception("Error: index line outside the array!");
	}
	return arr[index];
}

template<class T>
int easyVector<T>::getSize() const
{
	return this->size;
}

template<class T>
int easyVector<T>::getCapacity() const
{
	return this->capacity;
}

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	
	easyVector<int> easyVec;
	for (int i = 0; i < 6; i++)
	{
		easyVec.push_back(i);
	}
	easyVec.at(1) = 4;

	for (int i = 0; i < easyVec.getSize(); i++)
	{
		std::cout << easyVec.at(i) << "\n";
	}
	std::cout << "Size: " << easyVec.getSize() << "\n";
	std::cout << "Capacity: " << easyVec.getCapacity() << "\n";
	return 0;
}