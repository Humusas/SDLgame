#pragma once

#include "GameState.h"

class PlayState : public GameState
{

public:

	~PlayState() override {}

	bool OnEnter(Screen& screen) override;
	bool Render(Screen& screen) override;
	void OnExit() override;

	GameState* Update() override;

private:

	//All play variables declared here!
	//All main game play mechanics live in this class!!!!!

};