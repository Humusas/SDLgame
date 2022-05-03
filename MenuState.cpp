#include <iostream>
#include "MenuState.h"
#include "PlayState.h"

bool MenuState::OnEnter()
{
	//Background
	m_image.Load("ASSETS/Images/garage.jpg");
	m_image.SetImageDimention(1, 1, 1920, 1080);
	m_image.SetSpriteDimention(1280, 720);
	
	m_carkey.Load("ASSETS/Images/car_key.png");
	m_carkey.SetImageDimention(1, 1, 473, 418);
	m_carkey.SetSpriteDimention(50, 50);

	m_papers.Load("ASSETS/Images/papers.png");
	m_papers.SetImageDimention(1, 1, 1037, 789);
	m_papers.SetSpriteDimention(80, 80);

	//Load assets for menu buttons
	//Load menu background music
	m_music.Load("Assets/Music/joshua-mclean_dreams-left-behind.mp3");
	m_music.Play(Music::PlayLoop::Play_Endless);
	m_music.SetVolume(50);

	return true;
}

GameState* MenuState::Update()
{
	Vector2D MousePos = Input::Instance()->GetMousePosition();
	//std::cout << "Mouse cursor at (" << MousePos.x << ", " << MousePos.y << ")" << std::endl;

	//check if user scrolls up or down a menu
	if (Input::Instance()->IsMouseClicked() == true)
	{
		std::cout << "mouse clicked" << std::endl;
	}

	if (Input::Instance()->IsKeyPressed() == true)
	{
		//std::cout << input.GetKeyDown() << std::endl;
		if (Input::Instance()->GetKeyDown() == SDLK_ESCAPE)
		{
			return nullptr;
		}
	}

	if (MousePos.x > 399 && MousePos.x < 456) //car key
	{
		if (MousePos.y > 582 && MousePos.y < 606 && Input::Instance()->IsMouseClicked() == true)
		{
			Input::Instance()->MouseSound();
			std::cout << "target hit" << std::endl;
			return new PlayState; //game play screen
		}
	}

	if (MousePos.x > 321 && MousePos.x < 391) //pile of papers
	{
		if (MousePos.y > 534 && MousePos.y < 581 && Input::Instance()->IsMouseClicked() == true)
		{
			Input::Instance()->MouseSound();
			std::cout << "target hit" << std::endl;
			return new CreditsState; //game credits screen
		}
	}

	return this;
}

bool MenuState::Render()
{
	m_image.Render(0, 0, 0.0f, Sprite::Flip::NO_FLIP); //background
	m_carkey.Render(400, 575, 25.0f, Sprite::Flip::NO_FLIP);
	m_papers.Render(315, 529, 0.0f, Sprite::Flip::NO_FLIP);

	//render all buttons
	//render menu text

	return false;
}

void MenuState::OnExit()
{
	//unload all music, text, sprites for this state
	m_carkey.Unload();
	m_papers.Unload();
	m_image.Unload();
	m_music.Unload();
}