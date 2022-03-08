#include <memory>
#include <iostream>
#include "Game.h"
#include "MenuState.h"

int main()
{
	std::unique_ptr<Game> game = std::make_unique<Game>(new MenuState);

	if (game->Initialize())
	{
		game->Run();
		game->Shutdown();
	}

	system("pause");
	return 0;
}