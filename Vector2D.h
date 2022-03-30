#pragma once

class Vector2D
{
	//constructor
public:
	Vector2D(int x = 0, int y = 0); //created empty as 0.0

public:
	Vector2D Add(const Vector2D& second);
	Vector2D Subtract(const Vector2D& second);
	Vector2D Divide(int divider);

	Vector2D Scale(int scale);
	Vector2D Scale(const Vector2D& second);

	Vector2D Negate();

	int Magnitude();
	int Distance(const Vector2D& second);

	int x; // x coordinate
	int y; // y coordinate
};