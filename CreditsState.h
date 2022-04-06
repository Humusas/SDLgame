#pragma once
#include "GameState.h"
#include "Music.h"
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
	Sprite m_sign;
	Sprite m_credits;
	Music m_music;

};