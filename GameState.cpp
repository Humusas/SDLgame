#include "GameState.h"

bool GameState::OnEnter(Screen& screen)
{
	return 1;
}

bool GameState::Render(Screen& screen)
{
	return true;
}

void GameState::OnExit()
{
}

GameState* GameState::Update(Input& input, Screen& screen)
{
	return this;
}
