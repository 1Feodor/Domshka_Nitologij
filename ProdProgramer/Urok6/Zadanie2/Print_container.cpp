#include <iostream>
#include <Windows.h>
#include <vector>
#include <set>
#include <list>


template<class T>
void print_container(const T& arr)
{
	for (auto i : arr) std::cout << i << " ";
}

////////////////////////////////////////////////////

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	std::set<std::string> test_set = { "one", "two", "three", "four" };
	print_container(test_set); // four one three two. помните почему такой порядок? :)
	std::cout << "\n";

	std::list<std::string> test_list = { "one", "two", "three", "four" };
	print_container(test_list); // one, two, three, four
	std::cout << "\n";

	std::vector<std::string> test_vector = { "one", "two", "three", "four" };
	print_container(test_vector); // one, two, three, four
	std::cout << "\n";
	
	return 0;
}