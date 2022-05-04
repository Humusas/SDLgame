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
	m_buttonImage.Unload();
	m_buttonSound.Unload();
}

void Button::Update()
{
	ButtonStates ButtonState;
	switch (ButtonState)
	{
	case ButtonStates::hovered:
	{
		m_buttonHoveredImage.Load();
		break;
	}	

	case ButtonStates::pressed:
	{
		m_buttonHoveredImage.Render(m_position.x, m_position.y, m_angle, Sprite::Flip::NO_FLIP);
		m_buttonSound.Load("ASSETS/Sounds/blade.ogg");
		break;
	}

	default: //default idle state

		m_buttonImage.Render(m_position.x, m_position.y, m_angle, Sprite::Flip::NO_FLIP);

		break;
	}

	Vector2D m_mouseLocation = Input::Instance()->GetMousePosition();


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

void Button::PlayButtonSound()
{
	m_buttonSound.Load("ASSETS/Sounds/blade.ogg");
}

bool Button::HoveredOver()
{

	//if(mouseP)
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
