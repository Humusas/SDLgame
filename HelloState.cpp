#include "HelloState.h"

bool HelloState::OnEnter()
{
	//Load backdrop image
	m_image.Load("Assets/Images/wilcomen.png");
	m_image.SetImageDimention(1, 1, 1280, 720);
	m_image.SetSpriteDimention(1280, 720);

	//Load assets for menu buttons

	//Load menu background music
	m_music.Load("Assets/Music/joshua-mclean_the-well-traveled-path.mp3");
	m_music.SetVolume(5);
	m_music.Play(Music::PlayLoop::Play_Endless);

	return true;
}

GameState* HelloState::Update()
{
	Vector2D MousePos = Input::Instance()->GetMousePosition(); // not works
	//std::cout << "Mouse cursor at (" << MousePos.x << ", " << MousePos.y << ")" << std::endl;

	if (MousePos.x > 650 && MousePos.x < 700)
	{
		if (MousePos.y > 550 && MousePos.y < 600 && Input::Instance()->IsMouseClicked() == true)
		{
			Input::Instance()->MouseSound();
			return new MenuState;
		}
	}
	
	if (Input::Instance()->IsMouseClicked() == true)
	{
		Input::Instance()->MouseSound();
		std::cout << "mouse clicked" << std::endl;
	}

	if (Input::Instance()->IsKeyPressed() == true)
	{
		if (Input::Instance()->GetKeyDown() == SDLK_ESCAPE)
		{
			return nullptr;
		}
	}

	return this;
}

bool HelloState::Render()
{
	m_image.Render(0, 0, 0.0f, Sprite::Flip::NO_FLIP);
	//render all buttons
	//render menu text

	return false;
}

void HelloState::OnExit()
{
	//unload all music, text, sprites for this state
	m_image.Unload();
	m_music.Unload();
}