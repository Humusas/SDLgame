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

	return true;
}

GameState* PlayState::Update()
{
	if (Input::Instance()->IsKeyPressed(HM_KEY_ESCAPE) == true)
	{
		return nullptr;
	}
	//All main game mechanics are updated here

	m_player.Update();


	Vector2D MousePos = Input::Instance()->GetMousePosition();
	//std::cout << "Mouse cursor at (" << MousePos.x << ", " << MousePos.y << ")" << std::endl;

	return this;
}

bool PlayState::Render()
{
	m_backgroundImage.Render(0, 0, 0.0f, Sprite::Flip::NO_FLIP);
	
	m_player.Render();
	//render enemy
	//render ...
	
	return true;
}

void PlayState::OnExit()
{
	//unload all music, text, sprites for this state
	m_backgroundImage.Unload();
	m_music.Unload();
}