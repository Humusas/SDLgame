#pragma once
#include "Vector2D.h"


class BoxCollider
{
public:

	void SetPosition(int x, int y);
	void SetDimension(int width, int height);

	void Update(); //when dimension changes
	bool IsColliding(const BoxCollider& secondBox) const;

private:

	Vector2D m_min;
	Vector2D m_max;
	Vector2D m_position;
	Vector2D m_dimension;

};
