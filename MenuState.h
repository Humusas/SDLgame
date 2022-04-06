#pragma once
#include "GameState.h"
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
	Sprite m_carkey;
	Sprite m_papers;
	Music m_music;

};