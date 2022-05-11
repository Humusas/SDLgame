#include <iostream>
#include "Button.h"

Button::Button(const std::string& filename)
{
	//function to set button name (set name to game object -> button)
	SetTag(filename);
	m_buttonImage.Load("ASSETS/Images/"+GetTag()+".png"); //pick image by image name tag
	m_buttonImage.SetImageDimention(2,1,1200,600);
	m_buttonImage.SetSpriteDimention(150,150);

	m_buttonSound.Load("ASSETS/Sounds/blade.ogg");
	m_buttonSound.SetVolume(20);

	std::cout << "Button created" << std::endl;
}

Button::~Button()
{
	m_buttonImage.Unload();
	m_buttonSound.Unload();
	std::cout << "Button destroyed" << std::endl;
}

const Button::ButtonStates& Button::GetButtonState() const
{
	return m_buttonState;
}

void Button::Update()
{
	m_buttonImage.SetImageCell(1, 1);
	m_mouseRect.x = Input::Instance()->GetMousePosition().x;
	m_mouseRect.y = Input::Instance()->GetMousePosition().y;
	m_mouseRect.w = 1;
	m_mouseRect.h = 1;

	m_buttonRect.x = m_position.x;
	m_buttonRect.y = m_position.y;
	m_buttonRect.w = m_buttonImage.GetSpriteDimention().x;
	m_buttonRect.h = m_buttonImage.GetSpriteDimention().y;

	if (static_cast<bool>(SDL_HasIntersection(&m_mouseRect, &m_buttonRect)))
	{
		m_buttonState = ButtonStates::hovered;
		m_buttonImage.SetImageCell(2, 1);
		
		if (Input::Instance()->IsMouseClicked()) //if mouse clicked true
		{
			m_buttonState = ButtonStates::pressed;
			m_buttonImage.SetImageCell(2, 1);
			m_buttonSound.Play();
		}
	}
	else
	{
		m_buttonState = ButtonStates::idle;
	}
}

void Button::Render()
{
	m_buttonImage.Render(m_position.x, m_position.y, m_angle, Sprite::Flip::NO_FLIP);
}