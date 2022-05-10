#include <iostream>
#include "MenuState.h"
#include "PlayState.h"

bool MenuState::OnEnter()
{
	//Background
	m_image.Load("ASSETS/Images/garage.jpg");
	m_image.SetImageDimention(1, 1, 1920, 1080);
	m_image.SetSpriteDimention(1280, 720);
	
	buttonPosition.x = 200;
	buttonPosition.y = 500;
	//buttons.push_back(Button("key"));
	buttons.push_back(Button("pappers"));
	buttons.push_back(Button("keys"));

	for (auto& button : buttons)
	{
		button.SetPosition(buttonPosition);
		buttonPosition.x += 300;
	}

	//Load assets for menu buttons
	//Load menu background music
	m_music.SetVolume(50);
	m_music.Load("Assets/Music/joshua-mclean_dreams-left-behind.mp3");
	m_music.Play(Music::PlayLoop::Play_Endless);

	return true;
}

GameState* MenuState::Update()
{
	for (auto& button : buttons)
	{
		button.Update();

		if (button.GetButtonState() == Button::ButtonStates::hovered)
		{
			
		}
		if (button.GetButtonState() == Button::ButtonStates::pressed)
		{
			if (button.GetTag() == "keys")
			{
				return new PlayState;
			}
		}
		if (button.GetButtonState() == Button::ButtonStates::idle)
		{

		}
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_ESCAPE) == true)
	{
		return nullptr;
	}

//	std::cout << Input::Instance()->GetMousePosition().x << std::endl;
//	std::cout << Input::Instance()->GetMousePosition().y << std::endl;

	return this;
}

bool MenuState::Render()
{
	m_image.Render(0, 0, 0.0f, Sprite::Flip::NO_FLIP); //background

	//render all buttons
	for (auto& button : buttons)
	{
		button.Render();
	}
	//render menu text

	return false;
}

void MenuState::OnExit()
{
	//unload all music, text, sprites for this state
	m_image.Unload();
	m_music.Unload();
	buttons.~vector();
}