#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <vector>

class Sum_vector_thread
{
public:
	Sum_vector_thread(int);
	Sum_vector_thread(int, unsigned int);
	Sum_vector_thread(const Sum_vector_thread&);
	~Sum_vector_thread();
	void qua_thr(unsigned int);
	std::chrono::duration<double> time_sum();
private:
	unsigned int quantity_threads;
	std::vector<int> number1;
	std::vector<int> number2;
	std::vector<std::thread> thr;
	void sum_vec(size_t);
};

Sum_vector_thread::Sum_vector_thread(int size)
{
	this->quantity_threads = std::thread::hardware_concurrency();
	this->number1 = move( std::vector<int> (size, 2));
	this->number2 = move(std::vector<int>(size, 3));
}

Sum_vector_thread::Sum_vector_thread(int size, unsigned int quantity_threads)
{
	this->number1 = move(std::vector<int>(size, 2));
	this->number2 = move(std::vector<int>(size, 3));
	if (quantity_threads < 1) this->quantity_threads = 1;
	else if (quantity_threads > 16) this->quantity_threads = 16;
	else this->quantity_threads = quantity_threads;
}

Sum_vector_thread::Sum_vector_thread(const Sum_vector_thread& that)
{
	this->quantity_threads = that.quantity_threads;
	this->number1 = that.number1;
	this->number2 = that.number2;
}

Sum_vector_thread::~Sum_vector_thread()
{
}

void Sum_vector_thread::qua_thr(unsigned int quantity_threads)
{
	if (quantity_threads < 1) this->quantity_threads = 1;
	else if (quantity_threads > 16) this->quantity_threads = 16;
	else this->quantity_threads = quantity_threads;
}

std::chrono::duration<double> Sum_vector_thread::time_sum()
{
	auto start = std::chrono::steady_clock::now();
	this->sum_vec(1);
	if (quantity_threads > 1)
	{
		this->thr = std::vector<std::thread>(quantity_threads - 1);
		for (size_t i = 2; i <= quantity_threads; i++)
		{
			thr[i - 2] = move(std::thread([i, this]() { this->sum_vec(i); }));
			//thr[i - 2] = move(std::thread(&Sum_vector_thread::sum_vec, this, i));
		}
		for (size_t i = 2; i <= quantity_threads; i++)
		{
			thr[i - 2].join();
		}
	}
	auto end = std::chrono::steady_clock::now();
	return end - start;
}

void Sum_vector_thread::sum_vec(size_t x)
{
	for (size_t i = x - 1; i < this->number1.size(); i += quantity_threads)
	{
		this->number1[i] += this->number2[i];
	}
}


void sum_Vector(std::vector<int> &number1, std::vector<int> &number2, size_t x, size_t quantity_threads)
{
	for (size_t i = x - 1; i < number1.size(); i += quantity_threads)
	{
		number1[i] += number2[i];
	}
}

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	
	unsigned int n = std::thread::hardware_concurrency();
	std::cout << "Количество аппаратных ядер - " << n << std::endl;
	std::cout << "\nЧерез класс-" << std::endl;
	std::cout << "\t\t1000" << "\t\t10000" << "\t\t100000" << "\t\t1000000" << std::endl;
	for (size_t i = 1; i <= 16; i *= 2)
	{
		std::cout << i << " потоков ";
		for (size_t j = 1000; j <= 1000000; j *= 10)
		{
			Sum_vector_thread test(j, i);
			std::cout << "\t" << std::fixed << test.time_sum().count() << "s";
		}
		std::cout << std::endl;
	}

	//Sleep(300);

	std::cout << "\nБез класса-" << std::endl;
	std::cout << "\t\t1000" << "\t\t10000" << "\t\t100000" << "\t\t1000000" << std::endl;
	for (size_t i = 1; i <= 16; i *= 2)
	{
		std::vector<std::thread> thr;
		if (i > 1)
		{
			thr = std::vector<std::thread> (i - 1);
		}
		std::cout << i << " потоков ";
		for (size_t j = 1000; j <= 1000000; j *= 10)
		{
			std::vector<int> number1(j, 2);
			std::vector<int> number2(j, 3);
			auto start = std::chrono::steady_clock::now();

			sum_Vector(number1, number2, 1, i);
			for (size_t n = 2; n <= i; n++)
			{
				thr[n - 2] = move(std::thread(sum_Vector, std::ref(number1), std::ref(number2), n, i));
			}
			for (size_t n = 2; n <= i; n++)
			{
				thr[n - 2].join();
			}
			auto end = std::chrono::steady_clock::now();
			std::chrono::duration<double> elapsed_seconds = end - start;
			std::cout << "\t" << std::fixed << elapsed_seconds.count() << "s";
		}
		std::cout << std::endl;
	}
	return 0;
}