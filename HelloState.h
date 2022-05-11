#pragma once
#include <iostream>
#include "Button.h"
#include "Input.h"
#include "GameState.h"
#include "MenuState.h"
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
	Sound m_buttonSound;
	std::vector < std::unique_ptr<Button> > buttons;
};