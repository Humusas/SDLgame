#pragma once

#include "GameState.h"
#include "Sprite.h"
#include "Background.h"
#include "Input.h"


class HelloState : public GameState
{

public:

	~HelloState() override {}

	bool OnEnter() override;
	GameState* Update() override;
	bool Render() override;
	void OnExit() override;

	bool userClicksSecretButton;
	bool userClicksExitGameButton;

private:

	//All menu stuff declared here!
	Screen& m_screen;
	Sprite m_image;

};