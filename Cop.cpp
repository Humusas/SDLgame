#include <iostream>
#include "Cop.h"
#include "Vector2D.h"

Cop::Cop(Screen& screen) : m_screen(screen)
{
	std::cout << "Player created" << std::endl;
	m_image.Load("Assets/Images/cop.png", screen);
	m_image.SetImageDimention(1, 1, 1000, 415);
	m_image.SetSpriteDimention(250, 110);

	m_collider.SetDimension(240,70);
}

Cop::~Cop()
{
	std::cout << "Player destroyed" << std::endl;
	m_image.Unload();
}

const BoxCollider& Cop::GetCollider() const
{
	return m_collider;
}

void Cop::SetDirection(Direction direction)
{
	if (direction == LEFT)
	{
		m_direction.x = -1;
		m_direction.y = 0;
	}
	if (direction == RIGHT)
	{
		m_direction.y = 0;
		m_direction.x = 1;
	}
}

void Cop::SetVelocity(int velocity)
{
	m_velocity = velocity;
}

void Cop::Update(Input& Input)
{
	m_direction = m_direction.Scale(m_velocity);
	m_position = m_position.Add(m_direction);
	//m_collider.SetDimension(m_size.x, m_size.y);
	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();

}

void Cop::Render(Screen& screen)
{
	m_image.Render(m_position.x, m_position.y, m_angle, screen, Sprite::Flip::NO_FLIP);
}