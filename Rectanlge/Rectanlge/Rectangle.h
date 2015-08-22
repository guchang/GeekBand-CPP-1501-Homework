#pragma once
class Shape
{
public:
	Shape(int _no = 0) :no(_no) {}
	virtual ~Shape() {}

private:
	int no;
};

class Point
{
public:
	Point(int _x = 0, int _y = 0) :x(_x), y(_y) {}
	Point(const Point& _point) :x(_point.x), y(_point.y) {}
	int getX() const { return x; }
	int getY() const { return y; }
	void setX(int _x) { x = _x; }
	void setY(int _y) { y = _y; }
private:
	int x, y;
};

#include <iostream>
using namespace std;
class Rectangle :public Shape
{
public:
	Rectangle(int _width = 0, int _height = 0, int _x = 0, int _y = 0) : width(_width), height(_height), leftUp(new Point(_x, _y)) {}
	Rectangle(const Rectangle& other);
	Rectangle& operator=(const Rectangle& other);
	~Rectangle();

private:
	int width, height;
	Point *leftUp;
};

Rectangle::Rectangle(const Rectangle& other) :Shape(other), width(other.width), height(other.height)
{
	if (other.leftUp != nullptr)
	{
		leftUp = new Point(*other.leftUp);
	}
	else
	{
		leftUp = nullptr;
	}
}

Rectangle& Rectangle::operator=(const Rectangle& other)
{
	if (this == &other)
		return *this;

	Shape::operator=(other);

	width = other.width;
	height = other.height;

	if (leftUp != nullptr&&other.leftUp != nullptr)
	{
		*leftUp = *other.leftUp;
	}
	else if (leftUp == nullptr && other.leftUp != nullptr)
	{
		leftUp = new Point(*other.leftUp);
	}
	else
	{
		delete leftUp;
		leftUp = nullptr;
	}

	return *this;
}
Rectangle::~Rectangle()
{
	delete leftUp;
}