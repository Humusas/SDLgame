#pragma once

#include "GameState.h"

class PlayState : public GameState
{

public:

	~PlayState() override {}

	bool OnEnter() override;
	GameState* Update() override;
	bool Render() override;
	void OnExit() override;

private:

	//All play variables declared here!
	//All main game play mechanics live in this class!!!!!

};