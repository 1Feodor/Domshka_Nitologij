#include <iostream>
#include <Windows.h>
#include <thread>
#include <mutex>

class data
{
public:
	data();
	data(int);
	data(const data&);
	data& operator =(const data&);
	~data();
	std::mutex& set_mutex();
	friend std::ostream& operator <<(std::ostream&, const data&);
private:
	int x_data;
	std::mutex m;
};

data::data() : x_data{ 0 }
{
}

data::data(int x) : x_data{x}
{
}

data::data(const data& that)
{
	this->x_data = that.x_data;
}

data& data::operator=(const data& that)
{
	this->x_data = that.x_data;
	return *this;
}

data::~data()
{
}

std::mutex& data::set_mutex()
{
	return this->m;
}

std::ostream& operator<<(std::ostream& rezul, const data& that)
{
	return rezul << that.x_data;
}

void svap(data& D1, data& D2)
{
	std::lock(D1.set_mutex(), D2.set_mutex());
	std::lock_guard<std::mutex> Lk1{ D1.set_mutex(), std::adopt_lock };
	data buf{ D1 };
	std::lock_guard<std::mutex> Lk2{ D2.set_mutex(), std::adopt_lock };
	D1 = D2;
	D2 = buf;
	std::cout << "swap_lock left: " << D1 << std::endl;
	std::cout << "swap_lock right: " << D2 << std::endl;
}

void svap1(data& D1, data& D2)
{
	std::unique_lock<std::mutex> Lk1{ D1.set_mutex(), std::defer_lock };
	data buf{ D1 };
	std::unique_lock<std::mutex> Lk2{ D2.set_mutex(), std::defer_lock };
	std::lock(Lk1, Lk2);
	D1 = D2;
	D2 = buf;
	std::cout << "swap_unique_lock left: " << D1 << std::endl;
	std::cout << "swap_unique_lock right: " << D2 << std::endl;
}

void svap2(data& D1, data& D2)
{
	std::scoped_lock Sl{ D1.set_mutex(), D2.set_mutex() };
	data buf{ D1 };
	D1 = D2;
	D2 = buf;
	std::cout << "swap_scoped_lock left: " << D1 << std::endl;
	std::cout << "swap_scoped_lock right: " << D2 << std::endl;
}


int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	data left(1);
	data right(9);
	std::cout << "left: " << left  << std::endl;
	std::cout << "right: " << right << std::endl;

	std::cout << "swap" << std::endl;
	std::thread t1(svap, std::ref(left), std::ref(right));
	std::thread t2(svap, std::ref(left), std::ref(right));
	t1.join();
	t2.join();
	
	std::cout << "swap1" << std::endl;
	t1 = std::thread(svap1, std::ref(left), std::ref(right));
	t2 = std::thread(svap1, std::ref(left), std::ref(right));
	t1.join();
	t2.join();
	
	std::cout << "swap2" << std::endl;
	t1 = std::thread(svap2, std::ref(left), std::ref(right));
	t2 = std::thread(svap2, std::ref(left), std::ref(right));
	t1.join();
	t2.join();

	return 0;
}