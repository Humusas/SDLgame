#include <iostream>
#include "Input.h"
#include "Button.h"
#include "BoxCollider.h"

Button::Button()
{
	std::cout << "Button created" << std::endl;
}

Button::~Button()
{
	std::cout << "Button destroyed" << std::endl;
	m_sound.Unload();
	m_buttonImage.Unload();
}

void Button::Update()
{
	Vector2D m_mouseLocation = Input::Instance()->GetMousePosition();

	m_sound.SetVolume(3);

	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();
}

void Button::Render()
{
	m_buttonImage.Render(m_position.x, m_position.y, m_angle, Sprite::Flip::NO_FLIP);
}

const BoxCollider& Button::GetCollider() const
{
	return m_collider;
}

void Button::SetButtonCointainer(int width, int height)
{
	m_min.x = m_position.x;
	m_min.y = m_position.y;
	m_max.x = m_position.x + width;
	m_max.y = m_position.y + height;

}

void Button::ButtonSound()
{
	//m_music.Play(Music::PlayLoop::Play_Endless);
}

bool Button::HoveredOver()
{
	return true;
}

bool Button::IsClicked()
{
	if (true)//HoveredOver == true && mousedClicked==true)
	{
		
		return true;
	}
	
	else
	{
		return false;
	}
}
