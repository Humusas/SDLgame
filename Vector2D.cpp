#include <math.h>
#include "Vector2D.h"

Vector2D::Vector2D(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector2D Vector2D::Add(const Vector2D& second)
{
	Vector2D result;
	result.x = x + second.x;
	result.y = y + second.y;
	return result;
}

Vector2D Vector2D::Subtract(const Vector2D& second)
{
	Vector2D subtract;
	subtract.x = x - second.x;
	subtract.y = y - second.y;
	return subtract;
}

Vector2D Vector2D::Divide(int divider)
{
	Vector2D result;
	result.x = x * divider;
	result.y = y * divider;
	return result;
}

Vector2D Vector2D::Scale(int scale)
{
	Vector2D result;
	result.x = x * scale;
	result.y = y * scale;
	return result;
}

Vector2D Vector2D::Scale(const Vector2D& second)
{
	Vector2D result;
	result.x = x * second.x;
	result.y = y * second.y;
	return result;
}

Vector2D Vector2D::Negate()
{
	Vector2D negate;
	negate.x = x * -1;
	negate.y = y * -1;
	return negate;
}

int Vector2D::Distance(const Vector2D& second)
{
	Vector2D temp = Subtract(second);
	return static_cast<int>(temp.Magnitude());
}

int Vector2D::Magnitude()
{
	double x = static_cast<double>(this->x); //makes double from int
	double y = static_cast<double>(this->y); //makes double from int
	return static_cast<int>(sqrt((x * x) + (y * y)));
}