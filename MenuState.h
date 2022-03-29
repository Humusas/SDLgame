#pragma once

#include "GameState.h"
#include "Sprite.h"
#include "Background.h"
#include "Input.h"

class MenuState : public GameState
{

public:

	~MenuState() override {}

	bool OnEnter(Screen& screen) override;
	bool Render(Screen& screen) override;
	void OnExit() override;

	GameState* Update() override;
	//bool userClicksPlayGameButton;
	//bool userClicksExitGameButton;

private:

	//All menu stuff declared here!



};