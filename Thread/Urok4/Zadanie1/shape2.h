#pragma once
#include <vector>

enum point : int { A, B, C, D, A1, B1, C1, D1 };

struct point_shape
{
	point_shape(int x, int y, int z);
	int x{ 0 };
	int y{ 0 };
	int z{ 0 };
};

class Shape2
{
public:
	Shape2() = default;
	
	void offset(int m, int n, int k);
	void scaleX(int m);
	void scaleY(int n);
	void scaleZ(int k);
	void scale(int s);
protected:
	std::vector<point_shape> points;
	double R{ 0 };
	double H{ 0 };
	double volume{ 0 };
	double square{ 0 };
	virtual std::vector<point_shape> get_points() = 0;
};


class Segment : public Shape2
{
public:
	Segment(std::vector<point_shape> points);
	std::vector<point_shape> get_points() override final;
private:

};

class Sqr : public Segment
{
public:
	Sqr(std::vector<point_shape> points);
	double get_square();
private:

};

class Cube : public Sqr
{
public:
	Cube(std::vector<point_shape> points);
	double get_volume();
private:

};


class Circle : public Shape2
{
public:
	Circle(std::vector<point_shape> points, double R);
	std::vector<point_shape> get_points() override;
	double get_square();
private:
	void offset(int m, int n, int k) = delete;
	void scaleX(int m) = delete;
	void scaleY(int n) = delete;
	void scaleZ(int k) = delete;
	void scale(int s) = delete;
};


class Cylinder : public Circle
{
public:
	Cylinder(std::vector<point_shape> points, double R, double H);
	double get_volume();

private:

};

