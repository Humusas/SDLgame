#include "PlayState.h"
#include "MenuState.h"

bool PlayState::OnEnter()
{	
	m_backgroundImage.Load("ASSETS/Images/forest.png");
	m_backgroundImage.SetImageDimention(1, 1, 1920, 1080);
	m_backgroundImage.SetSpriteDimention(1280, 720);

	m_music.Load("ASSETS/Music/bensound_punky.mp3");
	m_music.SetVolume(5);
	m_music.Play(Music::PlayLoop::Play_Endless);

	//player
	
	return true;
}

GameState* PlayState::Update()
{

	//All main game mechanics are updated here
	m_player.Update();
	if (Input::Instance()->isKeyPressed() == true)
	{
		//std::cout << input.GetKeyDown() << std::endl;
		if (Input::Instance()->GetKeyDown() == SDLK_ESCAPE)
		{
			return nullptr;
		}
	}

	return this;
}

bool PlayState::Render()
{
	m_backgroundImage.Render(0, 0, 0.0f, Sprite::Flip::NO_FLIP);
	//Render player
	m_player.Render();
	//render enemy
	//render ...
	//m_player.Render(screen);
	
	return true;
}

void PlayState::OnExit()
{
	//unload all music, text, sprites for this state
	m_backgroundImage.Unload();
	//m_player.Unload();
	m_music.Unload();
}