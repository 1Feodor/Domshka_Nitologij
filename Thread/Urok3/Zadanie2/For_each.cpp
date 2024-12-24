#include <iostream>
#include <Windows.h>
#include <mutex>
#include <vector>
#include <future>

template < class Iterator, class Predicate>
void For_each(Iterator begins, Iterator ends, Predicate &foo)
{
	int size{ std::distance(begins, ends) };
	if (size <= 1)
	{
		foo(*begins);
	}
	else
	{
		Iterator mid{ begins };
		std::advance(mid, size / 2);
		std::future<void> first_half{ std::async(For_each<Iterator, Predicate>, begins, mid, std::ref(foo)) };
		std::future<void> second_half{ std::async(For_each<Iterator, Predicate>, mid, ends, std::ref(foo)) };
	}
}

std::mutex m;

void prints(int x)
{
	std::lock_guard<std::mutex> Lg{ m };
	std::cout << x << " ";
}

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	std::vector<int> list{ 5,44,6,85,21,3,48,71,55,6 };
	for (auto i : list) std::cout << i << " ";
	std::cout << std::endl;

	For_each(list.begin(), list.end(), prints);
	return 0;
}