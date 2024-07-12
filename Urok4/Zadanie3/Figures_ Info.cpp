#include <iostream>
#include <Windows.h>
#include <string>

enum dlinna : int { a, b, c, d };
enum ugol : int { A, B, C, D };



class Figure
{
public:
	Figure();
	~Figure();
	virtual void print_info();
protected:
	std::string name;
	int storona;
	int* h = nullptr;
	int* ugl = nullptr;
	void Set_Stron();
	void Set_Name_Fig();
	void Num_Stron_Corner();
	void Del_Stron();
	std::string get_sides_count()const;
	std::string get_side_length()const;
	std::string get_side_corner()const;
	virtual bool check();
};

Figure::Figure()
{
	Set_Stron();
	Set_Name_Fig();
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
///////////////////////////////////////////////////////
class Triangle : public Figure
{
public:
	Triangle(int, int, int, int, int, int);
	~Triangle();
	void print_info() override;
protected:
	void Set_Stron();
	void Set_Name_Fig();
	bool check() override;
};

Triangle::Triangle(int a, int b, int c, int A, int B, int C)
{

	Set_Name_Fig();
	Set_Stron();
	Num_Stron_Corner();
	this->h[dlinna::a] = a;
	this->h[dlinna::b] = b;
	this->h[dlinna::c] = c;
	this->ugl[ugol::A] = A;
	this->ugl[ugol::B] = B;
	this->ugl[ugol::C] = C;
}

Triangle::~Triangle()
{
	Del_Stron();
}

void Triangle::print_info()
{
	Figure::print_info();
	std::cout << Figure::get_side_length() << std::endl;
	std::cout << Figure::get_side_corner() << std::endl;
}

void Triangle::Set_Stron()
{
	storona = 3;
}
void Triangle::Set_Name_Fig()
{
	name = "Треугольник";
}
bool Triangle::check()
{
	if (storona != 3 || (this->ugl[ugol::A] + this->ugl[ugol::B] + this->ugl[ugol::C] != 180))
	{
		return false;
	}
	return true;
}
//////////////////////////////////////////////////////
class Quadrangle : public Figure
{
public:
	Quadrangle(int, int, int, int, int, int, int, int);
	~Quadrangle();
	void print_info() override;
protected:
	void Set_Stron();
	void Set_Name_Fig();
	bool check() override;
};

Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
{
	Set_Name_Fig();
	Set_Stron();
	Num_Stron_Corner();
	this->h[dlinna::a] = a;
	this->h[dlinna::b] = b;
	this->h[dlinna::c] = c;
	this->h[dlinna::d] = d;
	this->ugl[ugol::A] = A;
	this->ugl[ugol::B] = B;
	this->ugl[ugol::C] = C;
	this->ugl[ugol::D] = D;
}

Quadrangle ::~Quadrangle()
{
	Del_Stron();
}

void Quadrangle::print_info()
{
	Figure::print_info();
	std::cout << Figure::get_side_length() << std::endl;
	std::cout << Figure::get_side_corner() << std::endl;
}

void Quadrangle::Set_Stron()
{
	storona = 4;
}
void Quadrangle::Set_Name_Fig()
{
	name = "Четырёхугольник";
}
bool Quadrangle::check()
{
	if (storona != 4 || (this->ugl[ugol::A] + this->ugl[ugol::B] + this->ugl[ugol::C] + this->ugl[ugol::D] != 360))
	{
		return false;
	}
	return true;
}
////////////////////////////////////////////
class Right_Triangle : public Triangle
{
public:
	Right_Triangle(int, int, int, int, int);
	~Right_Triangle();
protected:
	void Set_Name_Fig();
	bool check() override;
};

Right_Triangle::Right_Triangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90)
{
	Set_Name_Fig();
}

Right_Triangle::~Right_Triangle()
{
}
void Right_Triangle::Set_Name_Fig()
{
	name = "Прямоугольный треугольник";
}
bool Right_Triangle::check()
{
	if (!Triangle::check() || this->ugl[ugol::C] != 90)
	{
		return false;
	}
	return true;
}
///////////////////////////////////////////
class Isosceles_Triangle : public Triangle
{
public:
	Isosceles_Triangle(int, int, int, int);
	~Isosceles_Triangle();
protected:
	void Set_Name_Fig();
	bool check() override;
};

Isosceles_Triangle::Isosceles_Triangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A)
{
	Set_Name_Fig();
}

Isosceles_Triangle::~Isosceles_Triangle()
{
}

void Isosceles_Triangle::Set_Name_Fig()
{
	name = "Равнобедренный треугольник";
}
bool Isosceles_Triangle::check()
{
	if (!Triangle::check() || this->h[dlinna::a] != this->h[dlinna::c] || this->ugl[ugol::A] != this->ugl[ugol::C])
	{
		return false;
	}
	return true;
}
////////////////////////////////////////////
class Equilateral_Triangle : public Isosceles_Triangle
{
public:
	Equilateral_Triangle(int);
	~Equilateral_Triangle();
protected:
	void Set_Name_Fig();
	bool check() override;
};

Equilateral_Triangle::Equilateral_Triangle(int a) : Isosceles_Triangle(a, a, 60, 60)
{
	Set_Name_Fig();
}

Equilateral_Triangle::~Equilateral_Triangle()
{
}
void Equilateral_Triangle::Set_Name_Fig()
{
	name = "Равносторонний треугольник";
}
bool Equilateral_Triangle::check()
{
	if (!Isosceles_Triangle::check() || this->h[dlinna::a] != this->h[dlinna::b] || this->ugl[ugol::A] != this->ugl[ugol::B] || this->ugl[ugol::A] != 60)
	{
		return false;
	}
	return true;
}
////////////////////////////////////////////
class Parallelogram : public Quadrangle
{
public:
	Parallelogram(int, int, int, int);
	~Parallelogram();
protected:
	void Set_Name_Fig();
	bool check() override;
};

Parallelogram::Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B)
{
	Set_Name_Fig();
}

Parallelogram::~Parallelogram()
{
}
void Parallelogram::Set_Name_Fig()
{
	name = "Параллелограмм";
}
bool Parallelogram::check()
{
	if (!Quadrangle::check() || this->h[dlinna::a] != this->h[dlinna::c] || this->h[dlinna::b] != this->h[dlinna::d] || this->ugl[ugol::A] != this->ugl[ugol::C] || this->ugl[ugol::B] != this->ugl[ugol::D])
	{
		return false;
	}
	return true;
}
////////////////////////////////////////////
class Reectangle : public Parallelogram
{
public:
	Reectangle(int, int);
	~Reectangle();
protected:
	void Set_Name_Fig();
	bool check() override;
};

Reectangle::Reectangle(int a, int b) : Parallelogram(a, b, 90, 90)
{
	Set_Name_Fig();
}

Reectangle::~Reectangle()
{
}
void Reectangle::Set_Name_Fig()
{
	name = "Прямоугольник";
}
bool Reectangle::check()
{
	if (!Parallelogram::check() || this->ugl[ugol::A] != 90 || this->ugl[ugol::B] != 90)
	{
		return false;
	}
	return true;
}
////////////////////////////////////////////
class Square : public Reectangle
{
public:
	Square(int);
	~Square();
protected:
	void Set_Name_Fig();
	bool check() override;
};

Square::Square(int a) : Reectangle(a, a)
{
	Set_Name_Fig();
}

Square::~Square()
{
}
void Square::Set_Name_Fig()
{
	name = "Квадрат";
}
bool Square::check()
{
	if (!Reectangle::check() || this->h[dlinna::a] != this->h[dlinna::b])
	{
		return false;
	}
	return true;
}
////////////////////////////////////////////
class Rhombus : public Parallelogram
{
public:
	Rhombus(int, int, int);
	~Rhombus();
protected:
	void Set_Name_Fig();
	bool check() override;
};

Rhombus::Rhombus(int a, int A, int B) : Parallelogram(a, a, A, B)
{
	Set_Name_Fig();
}

Rhombus::~Rhombus()
{
}

void Rhombus::Set_Name_Fig()
{
	name = "Ромб";
}

bool Rhombus::check()
{
	if (!Parallelogram::check() || this->h[dlinna::a] != this->h[dlinna::b])
	{
		return false;
	}
	return true;
}

void Print_Info(Figure*);
////////////////////////////////////////////

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Figure fig;
	Print_Info(&fig);
	std::cout << std::endl;

	Triangle tri(10, 20, 30, 92, 49, 39);
	Print_Info(&tri);
	std::cout << std::endl;

	Right_Triangle rt(14, 24, 34, 22, 69);
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

void Print_Info(Figure* figur)
{
	figur->print_info();
}