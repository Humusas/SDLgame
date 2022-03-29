#pragma once
#include <iostream>

#include "Background.h"
#include "Input.h"
#include "GameState.h"
#include "MenuState.h"
#include "Game.h"
#include "Sprite.h"

class HelloState : public GameState
{

public:
	
	~HelloState() override {}

	bool OnEnter(Screen& screen) override;
	bool Render(Screen& screen) override;
	void OnExit() override;

	GameState* Update() override;

private:

	//All menu stuff declared here!
	Sprite m_image;
	Input m_input;
};