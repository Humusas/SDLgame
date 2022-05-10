#pragma once
#include <iostream>
#include "Background.h"
#include "Button.h"
#include "Input.h"
#include "GameState.h"
#include "MenuState.h"
#include "Game.h"
#include "Sprite.h"

class HelloState : public GameState
{
public:
	
	~HelloState() override {}

	bool OnEnter() override;
	bool Render() override;
	void OnExit() override;

	GameState* Update() override;

private:
	//All menu stuff declared here!
	Sprite m_image; //local images that are applied only in HelloState
	Music m_music; //local music for HelloState
};