#pragma once
#include <memory>
#include <vector>
#include "Button.h"
#include "GameState.h"
//#include "Music.h"
#include "Image.h"
#include "MenuState.h"

class CreditsState : public GameState
{
public:

	~CreditsState() override {}

	bool OnEnter() override;
	bool Render() override;
	void OnExit() override;

	GameState* Update() override;

private:

	//All menu stuff declared here!
	//Background m_background; //unique background for MenuState
	//unique pointer to avoid shadow button deleting image for the button
	std::vector <std::unique_ptr<Button>>buttone; //vector of many Button class buttons
	Vector2D buttonPosition;
	Sound m_buttonSound;
	
	//Music m_music;
};