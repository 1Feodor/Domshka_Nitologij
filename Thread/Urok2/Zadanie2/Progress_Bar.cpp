#include <iostream>
#include <Windows.h>
#include <thread>
#include <mutex>
#include <chrono>
#include <string>
#include <random>

std::mutex m;

void progress_bar(size_t x, size_t y)
{
	std::string space;
	x < 3 ? space = "            " : x > 24 ? space = "          " : space = "           ";

	std::string str{ space + std::to_string(x * 4) + "%           "};
	std::cout << "\033[" << y + 1 << ";13H";
	std::cout << "\033[37;4" << y + 1 <<"m";
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (i >= x) std::cout << "\033[30;47m";
		std::cout << str[i];
	}
	std::cout << "\033[0m";
}

void consol_info_thread(int ind, size_t time)
{
	std::chrono::steady_clock::time_point start{ std::chrono::high_resolution_clock::now() };
	m.lock();
	std::cout << "\033[" << ind + 1 << ";1H";
	std::cout << ind << "     ";
	std::cout << std::this_thread::get_id();
	m.unlock();
	for (size_t i = 0; i < 26; i += 1)
	{
		m.lock();
		progress_bar(i, ind);
		m.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(time * 100));
	}
	std::chrono::steady_clock::time_point finish{ std::chrono::high_resolution_clock::now() };
	std::chrono::duration<float> duration = finish - start;
	m.lock();
	std::cout << "\033[" << ind + 1 << ";38H";
	std::cout << "   " << duration.count() << " s";
	m.unlock();
}

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	std::random_device rd;
	std::mt19937 gen{ rd() };
	std::uniform_int_distribution<> dis(1, 3);

	int size_thread{ 5 };
	std::thread* t = new std::thread[size_thread];

	std::cout << "\033[?25l";	// скрыл курсор
	std::cout << "#\tid\t   Progress Bar\t\tTime" << std::endl;

	for (int i = 0; i < size_thread; ++i)
		t[i] = std::thread(consol_info_thread, i + 1, dis(gen));
	for (int i = 0; i < size_thread; i++)
		t[i].join();

	std::cout << "\033[" << size_thread + 2 << ";1H";
	std::cout << "\033[?25h";	// показал курсор
	return 0;
}