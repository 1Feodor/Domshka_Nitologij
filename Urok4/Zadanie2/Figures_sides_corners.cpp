#include <iostream>
#include <Windows.h>
#include <string>

class Figure
{
public:
	Figure();
	~Figure();
	std::string get_sides_count()const;
	std::string get_side_length()const;
	std::string get_side_corner()const;
private:

protected:
	std::string name;
	int storona = 0;
	int* h = nullptr;
	int* ugl = nullptr;
	virtual void Stron() = 0;
	virtual void Name_Fig() = 0;
	void Num_Stron_Corner();
	void Del_Stron();
};

Figure::Figure()
{
}

Figure::~Figure()
{
}

std::string Figure::get_sides_count()const
{
	return name + ": " + std::to_string(storona);
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

void Figure::Num_Stron_Corner()
{
	this->h = new int[this->storona];
	this->ugl = new int[this->storona];
}

void Figure::Del_Stron()
{
	if (!(this -> h == nullptr))
	{
		delete[] this -> h;
		this -> h = nullptr;
	}
	if (!(this->ugl == nullptr))
	{
		delete[] this->ugl;
		this->ugl = nullptr;
	}
}
///////////////////////////////////////////////////////
class Triangle : public Figure
{
public:
	Triangle(int, int, int, int, int, int);
	~Triangle();
protected:
	void Stron() override;
	void Name_Fig() override;
};

Triangle::Triangle(int a, int b, int c, int A, int B, int C)
{
	
	Name_Fig();
	Stron();
	Num_Stron_Corner();
	this->h[0] = a;
	this->h[1] = b;
	this->h[2] = c;
	this->ugl[0] = A;
	this->ugl[1] = B;
	this->ugl[2] = C;
}

Triangle::~Triangle()
{
	Del_Stron();
}

void Triangle::Stron()
{
	storona = 3;
}
void Triangle::Name_Fig()
{
	name = "Треугольник";
}
//////////////////////////////////////////////////////
class Quadrangle : public Figure
{
public:
	Quadrangle(int, int, int, int, int, int, int, int);
	~Quadrangle();
protected:
	void Stron() override;
	void Name_Fig() override;
};

Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
{
	Name_Fig();
	Stron();
	Num_Stron_Corner();
	this->h[0] = a;
	this->h[1] = b;
	this->h[2] = c;
	this->h[3] = d;
	this->ugl[0] = A;
	this->ugl[1] = B;
	this->ugl[2] = C;
	this->ugl[3] = D;
}

Quadrangle ::~Quadrangle()
{
	Del_Stron();
}

void Quadrangle::Stron()
{
	storona = 4;
}
void Quadrangle::Name_Fig()
{
	name = "Четырёхугольник";
}
////////////////////////////////////////////
class Right_Triangle : public Triangle
{
public:
	Right_Triangle(int, int, int, int, int);
	~Right_Triangle();
protected:
	void Name_Fig() override;	
};

Right_Triangle::Right_Triangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90)
{
	Name_Fig();
}

Right_Triangle::~Right_Triangle()
{
}
void Right_Triangle::Name_Fig()
{
	name = "Прямоугольный треугольник";
}
///////////////////////////////////////////
class Isosceles_Triangle : public Triangle
{
public:
	Isosceles_Triangle(int, int, int, int);
	~Isosceles_Triangle();
protected:
	void Name_Fig() override;
};

Isosceles_Triangle::Isosceles_Triangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A)
{
	Name_Fig();
}

Isosceles_Triangle::~Isosceles_Triangle()
{
}

void Isosceles_Triangle::Name_Fig()
{
	name = "Равнобедренный треугольник";
}
////////////////////////////////////////////
class Equilateral_Triangle : public Isosceles_Triangle
{
public:
	Equilateral_Triangle(int);
	~Equilateral_Triangle();
protected:
	void Name_Fig() override;
};

Equilateral_Triangle::Equilateral_Triangle(int a) : Isosceles_Triangle(a, a, 60, 60)
{
	Name_Fig();
}

Equilateral_Triangle::~Equilateral_Triangle()
{
}
void Equilateral_Triangle::Name_Fig()
{
	name = "Равносторонний треугольник";
}
////////////////////////////////////////////
class Parallelogram : public Quadrangle
{
public:
	Parallelogram(int, int, int, int);
	~Parallelogram();
protected:
	void Name_Fig() override;
};

Parallelogram::Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B)
{
	Name_Fig();
}

Parallelogram::~Parallelogram()
{
}
void Parallelogram::Name_Fig()
{
	name = "Параллелограмм";
}
////////////////////////////////////////////
class Reectangle : public Parallelogram
{
public:
	Reectangle(int, int);
	~Reectangle();
protected:
	void Name_Fig() override;
};

Reectangle::Reectangle(int a, int b) : Parallelogram(a, b, 90, 90)
{
	Name_Fig();
}

Reectangle::~Reectangle()
{
}
void Reectangle::Name_Fig()
{
	name = "Прямоугольник";
}
////////////////////////////////////////////
class Square: public Reectangle
{
public:
	Square(int);
	~Square();
protected:
	void Name_Fig() override;
};

Square::Square(int a) : Reectangle(a, a)
{
	Name_Fig();
}

Square::~Square()
{
}
void Square::Name_Fig()
{
	name = "Квадрат";
}
////////////////////////////////////////////
class Rhombus : public Parallelogram
{
public:
	Rhombus(int, int, int);
	~Rhombus();
protected:
	void Name_Fig() override;
};

Rhombus::Rhombus(int a, int A, int B) : Parallelogram(a, a, A, B)
{
	Name_Fig();
}

Rhombus::~Rhombus()
{
}

void Rhombus::Name_Fig()
{
	name = "Ромб";
}

void Print_Info(const Figure*);
////////////////////////////////////////////

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Triangle tri(10, 20, 30, 92, 49, 39);
	Print_Info(&tri);
	std::cout << std::endl;
	
	Right_Triangle rt(14, 24, 34, 21, 69);
	Print_Info(&rt);
	std::cout << std::endl;
	
	Isosceles_Triangle it(13, 24, 51, 78);
	Print_Info(&it);
	std::cout << std::endl;

	Equilateral_Triangle et(33);
	Print_Info(&et);
	std::cout << std::endl;
	
	Quadrangle qua(10, 20, 30, 25, 75, 88, 64, 96);
	Print_Info(&qua);
	std::cout << std::endl;

	Reectangle rec(10, 35);
	Print_Info(&rec);
	std::cout << std::endl;

	Square squ(27);
	Print_Info(&squ);
	std::cout << std::endl;

	Parallelogram parll(16, 38, 104, 76);
	Print_Info(&parll);
	std::cout << std::endl;

	Rhombus rhom(24, 101, 79);
	Print_Info(&rhom);
	std::cout << std::endl;

	return 0;
}

void Print_Info(const Figure* figur)
{
	std::cout << figur->get_sides_count() << std::endl;
	std::cout << figur->get_side_length() << std::endl;
	std::cout << figur->get_side_corner() << std::endl;
}