#pragma once
#include "GameState.h"
#include "Input.h"
#include "Sprite.h"
#include "Music.h"
#include "Player.h"
#include "Cop.h"

class PlayState : public GameState
{
public:

	~PlayState() override {}

	bool OnEnter(Screen& screen) override;
	bool Render(Screen& screen) override;
	void OnExit() override;

	GameState* Update(Input& input) override;

private:

	//All play variables declared here!
	//All main game play mechanics live in this class!!!!!
	Sprite m_image;
	Music m_music;


};