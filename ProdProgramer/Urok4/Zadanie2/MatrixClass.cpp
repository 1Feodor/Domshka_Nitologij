#include <iostream>
#include <Windows.h>

template <class T>
class Matrix
{
public:
	Matrix(int, int);
	~Matrix();
	auto operator [](int);
	//auto operator [](int)const;
	int GetSize()const;
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
	this->arr = new T*[this->line];
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
auto Matrix<T>::operator[](int elem)
{
	return this->arr[elem];
}

template<class T>
int Matrix<T>::GetSize()const
{
	return this->size;
}

//template<class T>
//auto Matrix<T>::operator[](int elem) const
//{
//	return this->arr[elem];
//}

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	auto mm = Matrix<const char*>(2,3);
	mm[0][0] = "Masha";
	mm[0][1] = "Glasha";
	////// для кириллицы, почему-то, нужно собрать на х86 платформе (на х64 кириллицу не видно)
	mm[1][0] = "Серожа";
	mm[1][1] = "Никита";
	auto gg = mm[1][1];
	//std::cout << "fff " << std::endl;
	std::cout << mm[0][0] << std::endl;
	std::cout << mm[0][1] << std::endl;
	std::cout << mm[1][0] << std::endl;
	std::cout << mm[1][1] << std::endl;
	std::cout << gg << std::endl;
	return 0;
}