#include <iostream>
#include "MenuState.h"

bool MenuState::OnEnter()
{
	//Background
	m_background.Load("ASSETS/Images/garage.jpg");
	m_background.SetImageDimention(1, 1, 1920, 1080);
	m_background.SetSpriteDimention(1280, 720);

	//Load assets for menu buttons
	buttons.push_back(std::make_unique<Button>("keys"));
	buttons.push_back(std::make_unique<Button>("pappers"));

	//Load menu background music
	m_music.SetVolume(50);
	m_music.Load("Assets/Music/joshua-mclean_dreams-left-behind.mp3");
	m_music.Play(Music::PlayLoop::Play_Endless);

	return true;
}

GameState* MenuState::Update()
{
	buttonsPosition.y = 450;
	int count = 1;
	for (auto& button : buttons)
	{
		button->SetPosition(buttonsPosition);
		buttonsPosition.x = count++ * 300;
		button->Update();

		if (button->GetButtonState() == Button::ButtonStates::hovered) {}
		if (button->GetButtonState() == Button::ButtonStates::pressed)
		{
			if (button->GetTag() == "keys")
			{
				return new PlayState;
			}
			if (button->GetTag() == "pappers")
			{
				return new CreditsState;
			}
		}
		if (button->GetButtonState() == Button::ButtonStates::idle) {}
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_ESCAPE) == true)
	{
		return nullptr;
	}

	//std::cout << Input::Instance()->GetMousePosition().x << std::endl;
	//std::cout << Input::Instance()->GetMousePosition().y << std::endl;

	return this;
}

bool MenuState::Render()
{
	m_background.Render(0, 0, 0.0f, Sprite::Flip::NO_FLIP); //background
	//render all buttons
	for (auto& button : buttons)
	{
		button->Render();
	}
	//render menu text
	return false;
}

void MenuState::OnExit()
{
	std::cout << "Menu on exit" << std::endl;
	//unload all music, text, sprites for this state
	m_background.Unload();
	m_music.Unload();
	buttons.~vector();
}