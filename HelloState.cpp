#include "HelloState.h"

bool HelloState::OnEnter(Screen& screen)
{
	//Load backdrop image
	m_image.Load("Assets/Images/wilcomen.png", screen);
	m_image.SetImageDimention(1, 1, 1280, 720);
	m_image.SetSpriteDimention(1280, 720);


		//Load assets for menu buttons
		//m_image.Load("",m_screen);

	//Load menu background music
	

	return true;
}

GameState* HelloState::Update()
{
	MousePos MousePos = m_input.GetMousePosition();
		std::cout << "Mouse cursor at (" << MousePos.x << ", " << MousePos.y << ")" << std::endl;

		
		if (MousePos.x > 650 && MousePos.x < 700)
		{
			if (MousePos.y > 550 && MousePos.y < 600 && m_input.isMouseClicked() == true)
			{
				std::cout << "target hit" << std::endl;
				return new MenuState;
			}
		}

		//Check keypress and mouse clicks
		//check if buttons are clicked on
		//check if user scrolls up or down a menu

	/*if (userClicksSecretButton)
	{
	}

	if (userClicksExitGameButton)
	{
		return nullptr;
	}*/

	return this;
}

bool HelloState::Render(Screen& screen)
{
	m_image.Render(0, 0, 0.0f,screen, Sprite::Flip::NO_FLIP);
	//render all buttons
//	m_screen.GetRenderer();
	//render menu text


	return false;
}

void HelloState::OnExit()
{
	//unload all music, text, sprites for this state

}