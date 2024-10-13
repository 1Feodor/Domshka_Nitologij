#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	std::string str{ "Hello world!!" };
	std::cout << str << std::endl;

	std::map<char, int> mymap;
	for (const auto c : str) mymap[c] += 1;
	
	std::vector<std::pair<char, int>> arr{ mymap.begin(), mymap.end() };

	std::sort(arr.begin(), arr.end(),
	[](const std::pair<char, int>& a_pair, const std::pair<char, int>& b_pair)
	{
		return a_pair.second > b_pair.second;
	});
	
	for (const auto elem : arr)
	{
		std::cout << elem.first << ": " << elem.second << std::endl;
	}
	return 0;
}