#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>


class window
{
public:
	window(unsigned int);
	~window();
	void client();
	void the_operator();
private:
	int queue{ 0 };
	unsigned int value;
};

window::window(unsigned int value) : value{ value }
{
}

window::~window()
{
}

void window::client()
{
	for (size_t i = 0; i < value; i++)
	{
		++this->queue;
		std::cout << "Количество клиентов в очереди: " << queue << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

void window::the_operator()
{
	do
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		--this->queue;
		std::cout << "Количество клиентов не обслуженных операционистом: " << queue << std::endl;
	} while (queue);
}


int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	window test(10);
	std::thread t1(&window::client, &test);
	std::thread t2(&window::the_operator, &test);
	t1.detach();
	t2.join();
	return 0;
}