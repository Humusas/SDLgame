#include <iostream>
#include "CreditsState.h"

bool CreditsState::OnEnter()
{
	m_sign.Load("ASSETS/Images/sign.png");
	m_sign.SetImageDimention(1, 1, 480, 480);
	m_sign.SetSpriteDimention(100, 100);
	
	//m_credits.Load("ASSETS/Images/credits.png", screen);
	//m_credits.SetImageDimention(1, 1, 1200, 532);
	//m_credits.SetSpriteDimention(1280, 720);

	return true;
}

GameState* CreditsState::Update()
{
	if (Input::Instance()->IsMouseClicked() == true)
	{
		//std::cout << "mouse clicked" << std::endl;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_ESCAPE) == true)
	{
		return nullptr;
	}

	Vector2D MousePos = Input::Instance()->GetMousePosition();
	std::cout << "Mouse cursor at (" << MousePos.x << ", " << MousePos.y << ")" << std::endl;

	if (MousePos.x > 1160 && MousePos.x < 1261) //car key
	{
		if (MousePos.y > 599 && MousePos.y < 701 && Input::Instance()->IsMouseClicked() == true)
		{
			std::cout << "target hit" << std::endl;
			return new MenuState; //game play screen
		}
	}

	//check if user scrolls up or down a menu

	return this;
}

bool CreditsState::Render()
{
	//m_credits.Render(0, 0, 0.0, screen, Sprite::Flip:: NO_FLIP);
	m_sign.Render(1161, 600, 0.0f, Sprite::Flip:: NO_FLIP);

	//render menu text

	return false;
}

void CreditsState::OnExit()
{
	m_sign.Unload();
	//unload all music, text, sprites for this state
	//~m_background();
}