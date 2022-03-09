#include "Game.h"
#include <SDL.h>

/*Game::Game(GameState* initialState)
{
	m_gameState.reset(initialState);
}*/

Game::Game()
{

}

bool Game::Initialize()
{
	//Init screen 
	if (!ekranas.Initialize("My game", 1280, 720)) //initializes a black screen and checks if not initialized
	{
		return 0;
	}
	std::cout << "Hello, user. Game screen size is 1280x720. Enjoy" << std::endl;
	system("pause");

	muzika.Initialize();
	sriftas.Initialize();
	
	//Init third-party libraries

	return true;
}

bool Game::Run()
{
	m_gameState->OnEnter();

	while (m_gameState)  //will break if m_gameState == nullptr
	{

		if (Input.isWindowClosed())
		{
			//isGameRunning = false;
		}
		if (Input.GetKeyDown() == SDLK_ESCAPE)  //close game window with Esc button
		{
			//isGameRunning = false;
		}

		MousePos MousePos = Input.GetMousePosition();
		std::cout << "Mouse cursor at (" << MousePos.x << ", " << MousePos.y << ")" << std::endl;

		Input.Update();//update keyboard buttons or mouse clicks



		//clearing the screen

		//updating the input

		//checking delta time

		//updating the current game state

		//current game state will return a pointer to a different state if a switch is required 
		//If no switch is required then the current states pointer is returned
		GameState* nextState = m_gameState->Update(); 

		m_gameState->Render();

		//This will only run if a switch is required
		if (nextState != m_gameState.get())
		{
			m_gameState->OnExit();
			m_gameState.reset(nextState);

			if (m_gameState)
			{
				m_gameState->OnEnter();
			}
		}

		//rendering the screen
	}

	return true;
}

void Game::Shutdown()
{
	//Close down everything you initialized in init()
}