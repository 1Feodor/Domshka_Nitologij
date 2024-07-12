#include <iostream>
#include <Windows.h>
#include <string>

class Figure
{
public:
	 Figure();
	~Figure();
	std::string get_sides_count()const;
private:

protected:
	std::string name;
	int storona;
	virtual void Constr();
};

Figure::Figure()
{
	Constr();
}

Figure::~Figure()
{
}

std::string Figure::get_sides_count()const
{
	return name + ": " + std::to_string(storona);
}

void Figure::Constr()
{
	name = "Фигура";
	storona = 0;
}

class Triangle : public Figure
{
public:
	Triangle();
	~Triangle();
	void Constr() override;
};

Triangle::Triangle()
{
	Constr();
}

Triangle::~Triangle()
{
}

void Triangle::Constr()
{
	name = "Треугольник";
	storona = 3;
}

class Quadrangle : public Figure
{
public:
	Quadrangle ();
	~Quadrangle ();
	void Constr() override;
};

Quadrangle ::Quadrangle ()
{
	Constr();
}

Quadrangle ::~Quadrangle ()
{
}

void Quadrangle::Constr()
{
	name = "Четырёхугольник";
	storona = 4;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "Количество сторон:" << std::endl;
	Figure krug;
	std::cout << krug.get_sides_count() << std::endl;
	Triangle tri;
	std::cout << tri.get_sides_count() << std::endl;
	Quadrangle qua;
	std::cout << qua.get_sides_count() << std::endl;
	return 0;
}