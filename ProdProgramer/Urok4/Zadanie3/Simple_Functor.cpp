#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>


class simple_functor {
	int sum{ 0 };
	int count{ 0 };
public:
	simple_functor() = default;
	void operator()(int i)
	{
		if (!(i % 3))
		{
			this->sum += i;
			++this->count;
		}
	}
	int get_sum() { return this->sum; }
	int get_count() { return this->count; }
};


int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	std::vector<int> myvector{ 4, 1, 3, 6, 25, 54 };
	std::for_each(std::begin(myvector), std::end(myvector), [](int i)
		{
			std::cout << i << " ";
		});
	std::cout << std::endl;
	simple_functor test;
	for (auto i: myvector) test(i);
	std::cout << test.get_sum() << std::endl;
	std::cout << test.get_count() << std::endl;
	return 0;
}