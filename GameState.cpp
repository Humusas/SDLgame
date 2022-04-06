#include "GameState.h"

bool GameState::OnEnter()
{
	return 1;
}

bool GameState::Render()
{
	return true;
}

void GameState::OnExit()
{
}

GameState* GameState::Update()
{
	return this;
}
