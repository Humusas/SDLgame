/*
#include "BoxCollider.h"
#include "Cop.h"
#include "Player.h"
#include "Score.h"
#include "Text.h"
*/

#include <iostream>
#include <memory> // to have heap memory
#include "Game.h"
#include "HelloState.h"
#include "GameState.h"

int main(int argc, char* argv[]) 
{
	//do not use raw pointers. use smart ones instead. to have game on the heap:
	std::unique_ptr<Game> NewGame = std::make_unique<Game>();

	if (NewGame->Initialize("New Game"))
	{
		NewGame->Run(new HelloState); // if can't run new game -> shut it down
		NewGame->Shutdown();
	}	
	return 0;


/*
int main(int argc, char* argv[])
{
	//=============================================================================================================
	//Main game loop
	//=============================================================================================================

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
		switch (game_screen)
		{
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

		case 3://credits and thank you notes
		{
			Screen.Clear();
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
	*/
}