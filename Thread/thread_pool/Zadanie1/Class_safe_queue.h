#pragma once
#include <list>
#include <mutex>
#include <condition_variable>
#include <chrono>

template <class Predicate>
class Safe_queue
{
public:
	template <class Predicate>
	void push(Predicate foo)
	{
		std::lock_guard<std::mutex> LG(m);
		this->queue.push_front(move(foo));
		cv.notify_one();
	}

	template <class Predicate>
	Predicate pop()
	{
		std::unique_lock<std::mutex> UL(m);
		cv.wait_for(UL, std::chrono::milliseconds(100), [this] { return !this->queue.empty(); });
		if (this->queue.empty())
		{
			UL.unlock();
			return nullptr;
		}
		Predicate buf{ move(this->queue.back()) };
		this->queue.pop_back();
		UL.unlock();
		return buf;
	}

private:
	std::list<Predicate> queue;
	std::mutex m;
	std::condition_variable cv;
};