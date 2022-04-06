#pragma once
#include "GameState.h"
#include "Music.h"
#include "Image.h"
#include "MenuState.h"

class CreditsState : public GameState
{
public:

	~CreditsState() override {}

	bool OnEnter(Screen& screen) override;
	bool Render(Screen& screen) override;
	void OnExit() override;

	GameState* Update(Input& input, Screen& screen) override;

private:

	//All menu stuff declared here!
	//Background m_background; //unique background for MenuState
	Sprite m_sign;
	Sprite m_credits;
	Music m_music;

};