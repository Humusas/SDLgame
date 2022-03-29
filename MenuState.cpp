#include <iostream>
#include "MenuState.h"
#include "PlayState.h"
#include "GameState.h"



bool MenuState::OnEnter(Screen& screen)
{
	//Background garage(Screen m_screen)

	Sprite carkey;
	//carkey.Load("ASSETS/Images/car_key.png", screen);
	carkey.SetImageDimention(1, 1, 473, 418);
	carkey.SetSpriteDimention(50, 50);

	Sprite papers;
//	papers.Load("ASSETS/Images/papers.png", screen);
	papers.SetImageDimention(1, 1, 1037, 789);
	papers.SetSpriteDimention(80, 80);

	Sprite sign;
//	sign.Load("ASSETS/Images/sign.png", screen);
	sign.SetImageDimention(1, 1, 480, 480);
	sign.SetSpriteDimention(100, 100);


	//Load assets for menu buttons
	//Load menu background music
	//Load backdrop image
	return true;
}

GameState* MenuState::Update()
{
//	MousePos MousePos = input.GetMousePosition();
//	std::cout << "Mouse cursor at (" << MousePos.x << ", " << MousePos.y << ")" << std::endl;


	//Check keypress and mouse clicks
	//check if buttons are clicked on
	//check if user scrolls up or down a menu

/*	if (userClicksPlayGameButton)
	{
		return new PlayState;
	}

	if (userClicksExitGameButton)
	{
		return nullptr;
	}*/

	return this;
}

bool MenuState::Render(Screen& screen)
{

	//render all buttons
	//render menu text

	return false;
}

void MenuState::OnExit()
{
	//unload all music, text, sprites for this state

}