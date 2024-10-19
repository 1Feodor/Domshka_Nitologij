#include <iostream>
#include <Windows.h>


template<class T>
class Unique
{
public:
	Unique(T*);
	Unique(const Unique&) = delete;
	~Unique();
	Unique& operator= (const Unique&) = delete;
	T& operator* ();
	T* release();
	T* operator-> ();
private:
	T* ptr;
};


template<class T>
Unique<T>::Unique(T* ptr) : ptr{ ptr }
{
}

template<class T>
Unique<T>::~Unique()
{
	if (this->ptr != nullptr)
	{
		delete ptr;
		this->ptr = nullptr;
	}
}

template<class T>
T& Unique<T>::operator*()
{
	return *this->ptr;
}

template<class T>
T* Unique<T>::release()
{
	T* ptr1 = this->ptr;
	this->ptr = nullptr;
	return ptr1;
}

template<class T>
T* Unique<T>::operator->()
{
	return this->ptr;
}

class MyTest
{
public:
	MyTest(int);
	~MyTest();
	int val;
};

MyTest::MyTest(int wal): val{ wal }
{
}

MyTest::~MyTest()
{
}

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	Unique<int> value{ new int(5) };
	*value = 66;
	std::cout << *value << std::endl;

	int* ptr_test{ value.release()};
	std::cout << *ptr_test << std::endl;
	delete ptr_test;

	Unique<MyTest> value1{ new MyTest(5)};
	std::cout << value1->val << std::endl;
	return 0;
}