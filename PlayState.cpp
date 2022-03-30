#include "PlayState.h"
#include "MenuState.h"

bool PlayState::OnEnter(Screen& screen)
{	
	m_image.Load("ASSETS/Images/forest.png", screen);
	m_image.SetImageDimention(1, 1, 1920, 1080);
	m_image.SetSpriteDimention(1280, 720);

	m_music.Load("ASSETS/Music/bensound_punky.mp3");
	m_music.SetVolume(5);
	m_music.Play(Music::PlayLoop::Play_Endless);

	//player
	Player player();
	
	return true;
}

GameState* PlayState::Update(Input& input)
{

	//All main game mechanics are updated here

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

bool PlayState::Render(Screen& screen)
{
	m_image.Render(0,0,0.0f,screen, Sprite::Flip::NO_FLIP);
	//Render player
	//m_player.Render(10, 10, 0.0f, screen, Sprite::Flip::NO_FLIP);
	//render enemy
	//render ...

	return true;
}

void PlayState::OnExit()
{
	//unload all music, text, sprites for this state
	m_image.Unload();
	//m_player.Unload();
	m_music.Unload();
}