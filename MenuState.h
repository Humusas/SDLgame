#pragma once

#include <vector>
#include "GameState.h"
#include "Button.h"
#include "Input.h"
#include "Sprite.h"
#include "PlayState.h"
#include "CreditsState.h"

class MenuState : public GameState
{
public:

	~MenuState() override {}

	bool OnEnter() override;
	bool Render() override;
	void OnExit() override;

	GameState* Update() override;

private:

	//All menu stuff declared here!
	//Background m_background; //unique background for MenuState
	Sprite m_image; //background
	Music m_music;

	std::vector<Button> buttons;
	Vector2D buttonPosition;
};