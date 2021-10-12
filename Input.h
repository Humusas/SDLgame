#pragma once
#include <SDL.h>
#include "Sound.h"

struct MousePos
{
	int x = 1;
	int y = 1;
};

class Input  //keyboard, mouse
{
	//constructor
public:
	Input();

	bool isKeyPressed();
	bool isMouseClicked();
	bool isWindowClosed();

	char GetKeyUp();		//state of button not pressed
	char GetKeyDown();		//state of button pressed down
	
	const MousePos& GetMousePosition();
	
	void MouseSound();

	//state of button pressed down
	int GetMouseButtonUp();
	int GetMouseButtonDown();

	void Update();

private:

	Sound m_mouseSound;

	bool m_isKeyPressed = false;
	bool m_isMouseClicked = false;
	bool m_isWindowClosed = false;
		
	//keyboard
	char m_KeyUp;	//key released
	char m_KeyDown; //key pressed
	//mouse
	int m_MouseButtonUp;
	int m_MouseButtonDown;

	MousePos m_MousePosition; //returning references and struct as const
};