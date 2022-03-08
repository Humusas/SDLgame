#include <iostream>
#include <SDL.h>
#include <string>
#include "Background.h"
#include "Background2.h"
#include "BoxCollider.h"
#include "Cop.h"
#include "GameObject.h"
#include "Input.h"
#include "Music.h"
#include "Player.h"
#include "Score.h"
#include "Screen.h"
#include "Sprite.h"
#include "Sound.h"
#include "Text.h"
#include "Vector2D.h"
#include "Game.h"
#include "GameState.h"
#include "MenuState.h"
#include "PlayState.h"

bool isGameRunning = true;
int game_screen = 0;

int main(int argc, char* argv[])
{
	std::cout << "Hello, user. Game screen size is 1280x720. Enjoy" << std::endl;
	system("pause");

	//srand(time(0));
	Screen Screen;
	Input Input;

	Music::Initialize();
	Text::Initialize();

	//========================================================================================
	//create SDL environment ant create new game window
	//========================================================================================

	if (!Screen.Initialize("My game", 1280, 720)) //initializes a black screen and checks if not initialized
	{
		return 0;
	}

	//=============================================================================================================
	//Main game loop
	//=============================================================================================================

	Background forest(Screen);
	Background2 garage(Screen);


	Sprite welcome; //game by humusas
	welcome.Load("ASSETS/Images/wilcomen.png", Screen);
	welcome.SetImageDimention(1, 1, 1280, 720);
	welcome.SetSpriteDimention(1280, 720);

	Sprite carkey;
	carkey.Load("ASSETS/Images/car_key.png", Screen);
	carkey.SetImageDimention(1, 1, 473, 418);
	carkey.SetSpriteDimention(50, 50);

	Sprite papers;
	papers.Load("ASSETS/Images/papers.png", Screen);
	papers.SetImageDimention(1, 1, 1037, 789);
	papers.SetSpriteDimention(80, 80);

	Sprite sign;
	sign.Load("ASSETS/Images/sign.png", Screen);
	sign.SetImageDimention(1, 1, 480, 480);
	sign.SetSpriteDimention(100, 100);

	Sprite credits;
	credits.Load("ASSETS/Images/credits.png", Screen);
	credits.SetImageDimention(1, 1, 1200, 532);
	credits.SetSpriteDimention(1280, 720);

	Player gto(Screen);
	gto.SetPosition(1, 419); //if y 418 it moves left automode ???
	gto.SetVelocity(5);
	gto.SetAngle(0.0);

	Cop cop(Screen);
	cop.SetPosition(1300, 419);
	cop.SetVelocity(0);
	cop.SetAngle(0.0);

	Sprite win;
	win.Load("ASSETS/Images/FIN.png", Screen);
	win.SetImageDimention(1, 1, 1230, 644);
	win.SetSpriteDimention(1280, 720);

	Score* score = new Score;
	score->SetScore(0);
	score->SetPosition(20, 20);
	score->SetSize(50, 50);

	while (isGameRunning) //bool = 1;
	{

		if (Input.isWindowClosed())
		{
			isGameRunning = false;
		}
		if (Input.GetKeyDown() == SDLK_ESCAPE)  //close game window with Esc button
		{
			isGameRunning = false;
		}

		MousePos MousePos = Input.GetMousePosition();
		//std::cout << "Mouse cursor at (" << MousePos.x << ", " << MousePos.y << ")" << std::endl;

		Input.Update();//update keyboard buttons or mouse clicks

		switch (game_screen)
		{
		case 0: // 2D Game by Humusas
		{
			//std::cout << "case 0" << std::endl;
			Screen.Clear(); //clear screen (frame buffer)

			welcome.Render(0, 0, 0.0, Screen, Sprite::NO_FLIP);

			if (MousePos.x > 650 && MousePos.x < 700)
			{
				if (MousePos.y > 550 && MousePos.y < 600 && Input.isMouseClicked() == true)
				{
					Input.MouseSound();
					std::cout << "target hit" << std::endl;
					game_screen = 2; //game menu screen
				}
			}
			Screen.Present();
		}
		break;

		case 1: //game_screen = 1
		{
			//std::cout << "case 1" << std::endl;
			Screen.Clear(); //clear screen (frame buffer)
			forest.Update(Input);
			forest.BackgroundMusic();
			cop.Update(Input);
			gto.Update(Input);

			//collision tests and reactions here=====================

			BoxCollider playerCollider = gto.GetCollider();
			BoxCollider copCollider = cop.GetCollider();
			BoxCollider screenCollider = forest.GetCollider();

			if (playerCollider.IsColliding(screenCollider))
			{
				//std::cout << "Collision!" << std::endl;
				//while moving in screen to right - collect points until you reach end of screen
			}
			else
			{
				//std::cout << "Player out of screen" << std::endl;
				score->AddScore(10);
				gto.SetPosition(1, 419);
			}

			if (score->GetScore() == 100) // appears win screen
			{
				game_screen = 4;
				cop.SetDirection(Cop::Direction::LEFT);
				cop.SetVelocity(100);
				cop.GetPosition();
				
			}

			if (playerCollider.IsColliding(copCollider))
			{
				std::cout << "Collision!" << std::endl;

			}
			else
			{
				//std::cout << "NO collision!" << std::endl;
			}

			forest.Render(Screen);
			gto.Render(Screen);
			cop.Render(Screen);
			score->Render(Screen);

			Screen.Present();
		}
		break;

		case 2:	//game_screen = 2 ============ game menu screen
		{
			//std::cout << "case2" << std::endl;
			Screen.Clear();

			garage.Update(Input);
			garage.Render(Screen);

			carkey.Update();
			carkey.Render(400, 575, 25.0, Screen, Sprite::NO_FLIP);

			papers.Update();
			papers.Render(315, 529, 0.0, Screen, Sprite::NO_FLIP);

			if (MousePos.x > 399 && MousePos.x < 456) //car key
			{
				if (MousePos.y > 582 && MousePos.y < 606 && Input.isMouseClicked() == true)
				{
					Input.MouseSound();
					std::cout << "target hit" << std::endl;
					game_screen = 1; //game play screen
				}
			}

			if (MousePos.x > 321 && MousePos.x < 391) //pile of papers
			{
				if (MousePos.y > 534 && MousePos.y < 581 && Input.isMouseClicked() == true)
				{
					Input.MouseSound();
					std::cout << "target hit" << std::endl;
					game_screen = 3; //game credits screen
				}
			}

			Screen.Present();
		}
		break;

		case 3://credits and thank you notes
		{
			Screen.Clear();

			credits.Render(0, 0, 0.0, Screen, Sprite::NO_FLIP);

			sign.Update();
			sign.Render(1161, 600, 0.0, Screen, Sprite::NO_FLIP);

			if (MousePos.x > 1161 && MousePos.x < 1261) //sign
			{
				if (MousePos.y > 599 && MousePos.y < 701 && Input.isMouseClicked() == true)
				{
					Input.MouseSound();
					std::cout << "target hit" << std::endl;
					game_screen = 2; //game menu screen
				}
			}
			Screen.Present();
		}
		break;

		case 4: //win screen
		{
			Screen.Clear();
			score->SetScore(0);
			win.Render(0, 0, 0.0, Screen, Sprite::NO_FLIP);

			if (MousePos.x > -1 && MousePos.x < 1281) //sign
			{
				if (MousePos.y > -1 && MousePos.y < 721 && Input.isMouseClicked() == true)
				{
					Input.MouseSound();
					std::cout << "target hit" << std::endl;
					game_screen = 2; //game menu screen
				}
			}

			Screen.Present();
		}
		break;

		}
	}

	//==============================================================================================================
	//Shut down tasks. Clear everything from memmory
	//==============================================================================================================

	delete score;

	Screen.Shutdown();

	system("pause");
	return 0;
}