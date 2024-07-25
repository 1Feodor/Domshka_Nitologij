#include "Class_Figure.h"

Figure::Figure()
{
	Set_Stron();
	Set_Name_Fig();
	Print_error();
}

Figure::~Figure()
{
}

void Figure::print_info()
{
	std::cout << Figure::get_sides_count() << std::endl;
	if (check())
	{
		std::cout << "Правильная" << std::endl;
	}
	else
	{
		std::cout << "Неправильная" << std::endl;
	}
}

std::string Figure::get_sides_count()const
{
	return name + ": \nКоличество сторон: " + std::to_string(storona);
}

std::string Figure::get_side_length() const
{
	std::string get_len = "Стороны: ";
	for (int i = 0; i < storona; i++)
	{
		get_len = get_len + static_cast<char>('a' + i) + '=' + std::to_string(this->h[i]) + ' ';
	}
	return get_len;
}

std::string Figure::get_side_corner() const
{
	std::string get_corn = "Углы: ";
	for (int i = 0; i < storona; i++)
	{
		get_corn = get_corn + static_cast<char>('A' + i) + '=' + std::to_string(this->ugl[i]) + ' ';
	}
	return get_corn;
}

bool Figure::check()
{
	if (storona)
	{
		return false;
	}
	return true;
}

void Figure::Print_error()
{
	if (!check())
	{
		this->~Figure();
		throw std::string{ "количество сторон не равно 0." };
	}
}

void Figure::Set_Stron()
{
	storona = 0;
}

void Figure::Set_Name_Fig()
{
	name = "Фигура";
}

void Figure::Num_Stron_Corner()
{
	this->h = new int[this->storona];
	this->ugl = new int[this->storona];
}

void Figure::Del_Stron()
{
	if (!(this->h == nullptr))
	{
		delete[] this->h;
		this->h = nullptr;
	}
	if (!(this->ugl == nullptr))
	{
		delete[] this->ugl;
		this->ugl = nullptr;
	}
}