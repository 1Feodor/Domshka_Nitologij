#pragma once
#include "Class_safe_queue.h"
#include <thread>
#include <vector>
#include <functional>
#include <atomic>
#include <chrono>

class Thread_pool
{
public:
	Thread_pool();
	~Thread_pool();
	void submit(std::function<void()> foo);
private:
	std::atomic<bool> flag_exit{ true };
	std::vector<std::thread> thr;
	Safe_queue<std::function<void()>> queue;
	void work();
};