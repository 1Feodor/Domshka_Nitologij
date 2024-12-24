#include <iostream>
#include <Windows.h>
#include <vector>
#include <future>

void search_min(const std::vector<int>& list, const std::vector<int>::iterator &it, std::promise<int> prom)
{
	int value{ *it };
	for (auto j = it; j < list.end(); ++j)
	{
		if (value > *j)
			std::swap(value, *j);
	}
	prom.set_value(value);
}

void sort(std::vector<int> &list)
{	
	std::future<int> fut;
	std::future<void> asy;
	//std::promise<int> prom;
	//fut = prom.get_future();
	for (auto i = list.begin(); i < list.end(); ++i)
	{
		std::promise<int> prom;
		fut = prom.get_future();
		asy = std::async(search_min, std::ref(list), std::ref(i), move(prom));
		*i = fut.get();
	}
}


int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	std::vector<int> list{ 5,44,6,85,21,3,48,71,55,6 };
	for (auto i : list) std::cout << i << " ";
	std::cout << std::endl;

	sort(list);
	for (auto i : list) std::cout << i << " ";

	return 0;
}