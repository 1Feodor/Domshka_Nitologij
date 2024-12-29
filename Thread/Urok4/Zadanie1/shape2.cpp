#define _USE_MATH_DEFINES
#include "shape2.h"

point_shape::point_shape(int x, int y, int z) : x{x}, y{y}, z{z}
{}

/////////////////////////////////////////////////////

void Shape2::offset(int m, int n, int k)
{
	for (auto axis : this->points)
	{
		axis.x += m;
		axis.y += n;
		axis.z += k;
	}
}

void Shape2::scaleX(int m)
{
	for (auto axis : this->points)
		axis.x *= m;
}

void Shape2::scaleY(int n)
{
	for (auto axis : this->points)
		axis.y *= n;
}

void Shape2::scaleZ(int k)
{
	for (auto axis : this->points)
		axis.z *= k;
}

void Shape2::scale(int s)
{
	if (s == 0)
	{
		throw std::exception("error: value = 0!!!");
	}
	else
	{
		for (auto axis : this->points)
		{
			axis.x /= s;
			axis.y /= s;
			axis.z /= s;
		}
	}
}

//////////////////////////////////////////////////////////////

Segment::Segment(std::vector<point_shape> points)
{
	for (int i = 0; i < 2; i++)
	{
		this->points.push_back(points.at(i));
	}
}

std::vector<point_shape> Segment::get_points()
{
	return this->points;
}

//////////////////////////////////////////////////////////////

Sqr::Sqr(std::vector<point_shape> points) : Segment(points)
{
	for (int i = 2; i < 4; i++)
	{
		this->points.push_back(points.at(i));
	}
	int a = abs(this->points.at(point::A).x - this->points.at(point::B).x);
	int b = abs(this->points.at(point::A).y - this->points.at(point::B).y);
	this->square = a * b;
}

double Sqr::get_square()
{
	return this->square;
}

//////////////////////////////////////////////////////////////

Cube::Cube(std::vector<point_shape> points) : Sqr(points)
{
	for (int i = 4; i < 8; i++)
	{
		this->points.push_back(points.at(i));
	}
	int a = abs(this->points.at(point::A).x - this->points.at(point::B).x);
	int b = abs(this->points.at(point::A).y - this->points.at(point::B).y);
	int c = abs(this->points.at(point::A).z - this->points.at(point::B).z);
	this->square = (a * b + a * c + b * c) * 2;
	this->volume = a * b * c;
}

double Cube::get_volume()
{
	return this->volume;
}

////////////////////////////////////////////////////////////

Circle::Circle(std::vector<point_shape> points, double R)
{
	this->points.push_back(points.at(point::A));
	this->R = R;
	this->square = M_PI * this->R * this->R;
}

std::vector<point_shape> Circle::get_points()
{
	return this->points;
}

double Circle::get_square()
{
	return this->square;
}

////////////////////////////////////////////////////////////

Cylinder::Cylinder(std::vector<point_shape> points, double R, double H) : Circle(points, R)
{
	this->H = H;
	this->square = M_PI * this->R * this->R + 2 * this->R * this->H;
	this->volume = M_PI * this->R * this->R * this->H;
}

double Cylinder::get_volume()
{
	return this->volume;
}
