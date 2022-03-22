#include <iostream>
#include "MenuState.h"
#include "HelloState.h"

bool HelloState::OnEnter()
{
	//Load backdrop image
	m_image.Load("Assets/Images/wilcomen.png",m_screen);
	m_image.SetImageDimention(1, 1, 1280, 720);
	m_image.SetSpriteDimention(1280, 720);


		//Load assets for menu buttons
		//m_image.Load("",m_screen);

	//Load menu background music
	

	return true;
}

GameState* HelloState::Update()
{
	//	MousePos MousePos = input.GetMousePosition();
	//	std::cout << "Mouse cursor at (" << MousePos.x << ", " << MousePos.y << ")" << std::endl;


		//Check keypress and mouse clicks
		//check if buttons are clicked on
		//check if user scrolls up or down a menu

	if (userClicksSecretButton)
	{
		return new MenuState;
	}

	if (userClicksExitGameButton)
	{
		return nullptr;
	}

	return this;
}

bool HelloState::Render()
{

	//render all buttons
	//render menu text

	return false;
}

void HelloState::OnExit()
{
	//unload all music, text, sprites for this state

}