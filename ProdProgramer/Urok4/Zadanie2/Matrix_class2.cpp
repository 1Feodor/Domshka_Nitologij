#include <iostream>
#include <Windows.h>

template <class T>
class Proxy {
public:
	Proxy(T* line_ptr, int column) : line_ptr{ line_ptr }, proxy_column{ column } {}
	T& operator[](int col)
	{
		if (col < 0 || col >= this->proxy_column)
		{
			throw std::exception("Error: index column outside the array!");
		}
		return this->line_ptr[col];
	}
private:
	T* line_ptr;
	int proxy_column;
};

template <class T>
class Matrix
{
public:
	Matrix(int, int);
	~Matrix();
	Proxy<T> operator[](int);
	int GetSize()const;
	//Matrix(const Matrix&) = delete;//запрещаем конструктор копирования
	Matrix& operator= (const Matrix&) = delete; //запрещаем оператор присваивания
private:
	int line;
	int column;
	T** arr{ nullptr };
	int size;
};

template <typename T>
Matrix<T>::Matrix(int line, int column) : line{ line }, column{ column }, size{ line * column }
{
	if (line < 1 || column < 1)
	{
		throw std::exception("Error: capacity < 1");
	}
	this->arr = new T * [this->line];
	for (int i = 0; i < this->line; i++)
	{
		this->arr[i] = new T[this->column]{ 0 };
	}
}

template <typename T>
Matrix<T>::~Matrix()
{
	if (this->arr != nullptr)
	{
		for (int i = 0; i < this->line; i++)
		{
			delete[]this->arr[i];
		}
		delete[]this->arr;
		this->arr = nullptr;
	}
}

template<class T>
Proxy<T> Matrix<T>::operator[](int lin)
{
	if (lin < 0 || lin >= this->line)
	{
		throw std::exception("Error: index line outside the array!");
	}
	return Proxy<T>(this->arr[lin], this->column);
}

template<class T>
int Matrix<T>::GetSize()const
{
	return this->size;
}

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	auto mm{ Matrix<const char*>(2,3) };
	//Matrix<const char*> mm (2,3);
	mm[0][0] = "Masha";
	mm[0][1] = "Glasha";
	mm[1][0] = "Серожа";
	mm[1][1] = "Никита";
	auto gg = mm[1][1];
	
	std::cout << mm[0][0] << std::endl;
	std::cout << mm[0][1] << std::endl;
	std::cout << mm[1][0] << std::endl;
	std::cout << mm[1][1] << std::endl;
	std::cout << gg << std::endl;
	return 0;
}