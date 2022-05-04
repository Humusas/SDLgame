#include <SDL.h>
#include "Game.h"

bool Game::Initialize(std::string gameName)
{
	//Init screen 
	if(!Screen::Instance()->Initialize("game", 1280, 720))//initializes a black screen and checks if not initialized
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
	m_gameState->OnEnter();

	while (m_gameState)  //will break if m_gameState == nullptr
	{
		Input::Instance()->Update();	//update keyboard buttons or mouse clicks
		Screen::Instance()->Clear();	//clearing the screen

		//checking delta time
		
//************************************************updating the current game state*******************************************
	
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
		Screen::Instance()->Present();
	}
	return true;
}

void Game::Shutdown()
{
	//Close down everything you initialized in init()
	Screen::Instance()->Shutdown();
	music.Shutdown();
	text.Unload();
}