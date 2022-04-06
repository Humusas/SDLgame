#include <iostream>
#include "CreditsState.h"

bool CreditsState::OnEnter(Screen& screen)
{
	m_sign.Load("ASSETS/Images/sign.png", screen);
	m_sign.SetImageDimention(1, 1, 480, 480);
	m_sign.SetSpriteDimention(100, 100);
	
	//m_credits.Load("ASSETS/Images/credits.png", screen);
	m_credits.SetImageDimention(1, 1, 1200, 532);
	m_credits.SetSpriteDimention(1280, 720);

	return true;
}

GameState* CreditsState::Update(Input& input, Screen& screen)
{
	MousePos MousePos = input.GetMousePosition();
	//std::cout << "Mouse cursor at (" << MousePos.x << ", " << MousePos.y << ")" << std::endl;

	//check if user scrolls up or down a menu

	if (input.isMouseClicked() == true)
	{
		std::cout << "mouse clicked" << std::endl;
	}

	if (input.isKeyPressed() == true)
	{
		//std::cout << input.GetKeyDown() << std::endl;
		if (input.GetKeyDown() == SDLK_ESCAPE)
		{
			return nullptr;
		}
	}

	return this;
}

bool CreditsState::Render(Screen& screen)
{
	//m_credits.Render(0, 0, 0.0, screen, Sprite::Flip:: NO_FLIP);
	m_sign.Render(1161, 600, 0.0f, screen, Sprite::Flip:: NO_FLIP);

	//render menu text

	return false;
}

void CreditsState::OnExit()
{
	
	m_sign.Unload();
	//unload all music, text, sprites for this state
	//~m_background();
}