#include <iostream>
#include "Background2.h"

Background2::Background2(Screen& screen)
{
	std::cout << "Background created" << std::endl;
	m_image.Load("ASSETS/Images/garage.jpg", screen);
	m_image.SetImageDimention(1, 1, 1920, 1080);
	m_image.SetSpriteDimention(1280, 720);
		
}

Background2::~Background2()
{
	std::cout << "Background destroyed" << std::endl;
	
	m_image.Unload();
}

void Background2::Update(Input& input)
{

	m_collider.SetDimension(m_size.x, m_size.y);
	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();
}

void Background2::Render(Screen& screen)
{
	m_image.Render(m_position.x, m_position.y, m_angle, screen, Sprite::Flip::NO_FLIP);
}



const BoxCollider& Background2::GetCollider() const
{
	return m_collider;
}