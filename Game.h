#pragma once
#include <SDL.h>
#include <iostream>
#include <string>
#include "GameState.h"
#include "Input.h"
#include "Music.h"
#include "Screen.h"
#include "Text.h"

class Game
{
public:

	//Game(GameState* initialState);

	//	const std::string& filename - to initialize from file
	bool Initialize(std::string gameName);	//set everything here. physics, audio, screen.
	bool Run(GameState* initialState);			//if game stops running. everything runs here
	void Shutdown();    //shutdown all that was initialized 

private:

	std::unique_ptr<GameState> m_gameState;

//	Screen screen; // output screen window
//	Input input; //
	Music music;  //music all
	Text text; //any font-style

};