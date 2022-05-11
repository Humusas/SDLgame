#include <iostream>
#include "CreditsState.h"

bool CreditsState::OnEnter()
{
	buttone.push_back(std::make_unique<Button>("signs"));
	buttonPosition = {1125, 550};

	return true;
}

GameState* CreditsState::Update()
{
	for (auto& button : buttone)
	{
		button->SetPosition(buttonPosition);
		button->Update();

		if (button->GetButtonState() == Button::ButtonStates::hovered) {}
		if (button->GetButtonState() == Button::ButtonStates::pressed)
		{
			if (button->GetTag() == "signs")
			{
				return new MenuState;
			}
		}
		if (button->GetButtonState() == Button::ButtonStates::idle) {}
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_ESCAPE) == true)
	{
		return nullptr;
	}

	//Vector2D MousePos = Input::Instance()->GetMousePosition();
	//std::cout << "Mouse cursor at (" << MousePos.x << ", " << MousePos.y << ")" << std::endl;

	//check if user scrolls up or down a menu

	return this;
}

bool CreditsState::Render()
{
	//m_credits.Render(0, 0, 0.0, screen, Sprite::Flip:: NO_FLIP);
	//m_sign.Render(1161, 600, 0.0f, Sprite::Flip:: NO_FLIP);
	//Sign.Render();
	for (auto& button : buttone)
	{
		button->Render();
	}
	//render menu text
	return false;
}

void CreditsState::OnExit()
{
	//m_sign.Unload();
	//~m_background();
	//unload all music, text, sprites for this state
	//m_background.Unload();
	//m_music.Unload();
	std::cout << "Credits on exit" << std::endl;
	buttone.~vector();
	//Sign.~Button();
}