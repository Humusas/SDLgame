#include <SDL.h>
#include "Game.h"

bool Game::Initialize()
{
	//Init screen 
	if (!screen.Initialize("New game", 1280, 720)) //initializes a black screen and checks if not initialized
	{
		return 0;
	}
	music.Initialize();
	text.Initialize();


	//Init third-party libraries
	std::cout << "Initialize finished" << std::endl;

	return true;
}

bool Game::Run(GameState* initialState)
{
	m_gameState.reset(initialState);
	m_gameState->OnEnter(screen);

	while (m_gameState)  //will break if m_gameState == nullptr
	{
		input.Update();//update keyboard buttons or mouse clicks
		//clearing the screen
		input.isMouseClicked();
		input.GetKeyDown();
		screen.Clear();

		//checking delta time

		
		//updating the current game state*******************************************
		//current game state will return a pointer to a different state if a switch is required 
		//If no switch is required then the current states pointer is returned
		GameState* nextState = m_gameState->Update(); 

		m_gameState->Render(screen);

		//This will only run if a switch is required
		if (nextState != m_gameState.get())
		{
			m_gameState->OnExit();
			m_gameState.reset(nextState);

			if (m_gameState)
			{
				m_gameState->OnEnter(screen);
			}
		}

		//rendering the screen
		screen.Present();
	}

	return true;
}

void Game::Shutdown()
{
	//Close down everything you initialized in init()
	screen.Shutdown();
	music.Shutdown();
	text.Unload();
}