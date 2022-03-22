#pragma once

#include "GameState.h"
#include "Sprite.h"
#include "Background.h"
#include "Input.h"

class MenuState : public GameState
{

public:

	~MenuState() override {}

	bool OnEnter() override;
	GameState* Update() override;
	bool Render() override;
	void OnExit() override;

	bool userClicksPlayGameButton;
	bool userClicksExitGameButton;

private:

	//All menu stuff declared here!



};