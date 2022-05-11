#pragma once
#include <memory>
#include <vector>
#include "Button.h"
#include "CreditsState.h"
#include "GameState.h"
#include "Input.h"
#include "PlayState.h"
#include "Sprite.h"

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
	Sprite m_background; //background image
	Music m_music;

	//unique pointer to avoid shadow button deleting image for the button
	std::vector < std::unique_ptr<Button> > buttons; //vector of many Button class buttons
	Vector2D buttonsPosition;
};