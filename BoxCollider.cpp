#include "BoxCollider.h"


void BoxCollider::SetPosition(int x, int y)
{//vectors
	m_position.x = m_min.x;
	m_position.y = m_min.y;
}

void BoxCollider::SetDimension(int width, int height)
{//vectors
	m_dimension.x = m_position.x + width;
	m_dimension.y = m_position.y + height;
}

void BoxCollider::Update()
{//vectors
	m_min.x = m_position.x;
	m_min.y = m_position.y;
	m_max.x = m_position.x + m_dimension.x;
	m_max.y = m_position.y + m_dimension.y;
}

bool BoxCollider::IsColliding(const BoxCollider& secondBox) const
{
	//or just return instead of if
	return (m_max.x > secondBox.m_min.x && secondBox.m_max.x > m_min.x &&
		m_max.y > secondBox.m_min.y && secondBox.m_max.y > m_min.y);
}
