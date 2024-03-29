#include "HelloState.h"

bool HelloState::OnEnter()
{
	//Load backdrop image
	m_image.Load("Assets/Images/wilcomen.png");
	m_image.SetImageDimention(1, 1, 1280, 720);
	m_image.SetSpriteDimention(1280, 720);

	//Load assets for menu buttons
//	m_buttonImage.Load("Assets/Images/" );
//	buttons.push_back(std::make_unique<Button>("targets"));
	

	//Load menu background music
	m_music.Load("Assets/Music/joshua-mclean_the-well-traveled-path.mp3");
	m_music.SetVolume(5);
	m_music.Play(Music::PlayLoop::Play_Endless);

	return true;
}

GameState* HelloState::Update()
{	
	//asking if ESC button(int 41) pressed
	if (Input::Instance()->IsKeyPressed(HM_KEY_ESCAPE) == true)
	{
		return nullptr;
	}

	Vector2D MousePos = Input::Instance()->GetMousePosition();
	//std::cout << "Mouse cursor at (" << MousePos.x << ", " << MousePos.y << ")" << std::endl;
	
	//convert to button
	Input::Instance()->GetMousePosition();
	if (MousePos.x > 650 && MousePos.x < 700)
	{
		if (MousePos.y > 550 && MousePos.y < 600 && Input::Instance()->IsMouseClicked() == true)
		{
			return new MenuState;
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
	std::cout << "Hello state On Exit" << std::endl;

	//unload all music, text, sprites for this state
	m_image.Unload();
	std::cout << "Hello state background destroyed" << std::endl;
	m_music.Unload();
}