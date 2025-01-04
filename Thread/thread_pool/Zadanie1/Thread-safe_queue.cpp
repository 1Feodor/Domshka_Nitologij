#include <iostream>
#include <Windows.h>
#include <mutex>
#include "Class_thread_pool.h"

std::mutex m;

void foo1()
{
	m.lock();
	std::cout << "Foo1 start id\t" << std::this_thread::get_id() << std::endl;
	m.unlock();
	Sleep(500);
	m.lock();
	std::cout << "Foo1 stop id\t" << std::this_thread::get_id() << std::endl;
	m.unlock();
}

void foo2()
{
	m.lock();
	std::cout << "Foo2 start id\t" << std::this_thread::get_id() << std::endl;
	m.unlock();
	Sleep(1000);
	m.lock();
	std::cout << "Foo2 stop id\t" << std::this_thread::get_id() << std::endl;
	m.unlock();
}

void foo3()
{
	m.lock();
	std::cout << "Foo3 start id\t" << std::this_thread::get_id() << std::endl;
	m.unlock();
	Sleep(1500);
	m.lock();
	std::cout << "Foo3 stop id\t" << std::this_thread::get_id() << std::endl;
	m.unlock();
}

void foo4()
{
	m.lock();
	std::cout << "Foo4 start id\t" << std::this_thread::get_id() << std::endl;
	m.unlock();
	Sleep(2000);
	m.lock();
	std::cout << "Foo4 stop id\t" << std::this_thread::get_id() << std::endl;
	m.unlock();
}

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	std::vector< std::function<void()>> list{ 
		foo1, foo2, foo3, foo4, 
		foo4, foo3, foo2, foo1, 
		foo1, foo2, foo3, foo4, 
		foo4, foo3, foo2, foo1 };

	Thread_pool test;
	for (size_t i = 0; i < list.size(); i++)
	{
		test.submit(list[i]);
		if (i%2)
			Sleep(1000);
	}
	return 0;
}