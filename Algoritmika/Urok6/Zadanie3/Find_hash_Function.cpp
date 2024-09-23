#include <iostream>
#include <Windows.h>
#include <string>

int find_substring_light_rabin_karp(std::string, std::string);


int main()
{
	/*SetConsoleCP(1251);
	SetConsoleOutputCP(1251);*/
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	std::string stri{ "\0" };
	std::string pod_str{ "\0" };
	int rezul{ 0 };
	
	std::cout << "Введите строку, в которой будет осуществляться поиск: ";
	std::cin >> stri;
	do
	{
		std::cout << "Введите подстроку, которую нужно найти: ";
		std::cin >> pod_str;
		rezul = find_substring_light_rabin_karp(stri, pod_str);
		if (rezul == -1)
		{
			std::cout << "Подстрока " << pod_str << " не найдена" << std::endl;
		}
		else
		{
			std::cout << "Подстрока " << pod_str << " найдена по индексу " << rezul << std::endl;
		}
		
	} while (pod_str != "exit");
	return 0;
}

int find_substring_light_rabin_karp(std::string str, std::string pod_str)
{
	if (pod_str.size() > str.size()) return -1;

	unsigned long long hash_str{ 0 };
	unsigned long long hash_pod_str{ 0 };
	for (int i = 0; pod_str[i] != '\0'; ++i)
	{
		hash_str += str[i];
		hash_pod_str += pod_str[i];
	}
	for (int i = 0; i <= str.size() - pod_str.size(); i++)
	{
		if (hash_str == hash_pod_str)
		{
			bool flag = true;
			for (int j = 0; pod_str[j] != '\0'; ++j)
			{
				if (str[i + j] != pod_str[j])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				return i;
			}
		}
		if (i + pod_str.size() < str.size())
		{
			hash_str = hash_str - str[i] + str[i + pod_str.size()];
		}
		
	}
	return -1;
}