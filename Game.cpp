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
	if (!screen.Initialize("My game", 1280, 720)) //initializes a black screen and checks if not initialized
	{
		return 0;
	}
	std::cout << "Hello, user. Game screen size is 1280x720. Enjoy" << std::endl;

	music.Initialize();
	text.Initialize();
	
	//Init third-party libraries

	return true;
}

bool Game::Run()
{
	m_gameState->OnEnter();

	while (m_gameState)  //will break if m_gameState == nullptr
	{
		input.Update();//update keyboard buttons or mouse clicks
		//clearing the screen

		screen.Clear();

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
		screen.GetRenderer();

	}

	return true;
}

void Game::Shutdown()
{
	//Close down everything you initialized in init()
	screen.Shutdown();
	music.Shutdown();
}