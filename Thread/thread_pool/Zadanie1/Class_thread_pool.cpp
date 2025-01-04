#include "Class_thread_pool.h"

Thread_pool::Thread_pool() : thr{ std::vector<std::thread>(std::thread::hardware_concurrency()) }
{
	for (auto &i : this->thr)
		i = move(std::thread(&Thread_pool::work, this));
}

Thread_pool::~Thread_pool()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	flag_exit.store(false);
	for (auto& i : this->thr)
		i.join();
}

void Thread_pool::submit(std::function<void()> foo)
{
	this->queue.push(foo);
}

void Thread_pool::work()
{
	while (flag_exit.load())
	{
		std::function<void()> buf{ this->queue.pop<std::function<void()>>() };
		if (buf != nullptr)
			buf();	
	}
}
