#include <iostream>
#include <SDL.h>
#include "Input.h"
#include "Sound.h"

Input* Input::Instance()
{
	static Input* inputObject = new Input();
	return inputObject;
	std::cout << "Input object created" << std::endl;
}

Input::Input()
{
	std::cout << "Input created" << std::endl;
}


char Input::GetKeyUp()
{
	return m_KeyUp;
}

char Input::GetKeyDown()
{
	return m_KeyDown;
}

bool Input::isKeyPressed()
{
	return m_isKeyPressed;
}

bool Input::isWindowClosed()
{
	return m_isWindowClosed;
}

void Input::Update()
{
	SDL_Event events;

	//SDL_PollEvent(&events);// takes one event and puts into events classs
							// 0-no events, 1 is . while there is event
	while (SDL_PollEvent(&events))
	{
		if (events.type == SDL_QUIT)	//esc pressed
		{
			std::cout << "esc pressed" << std::endl;
			m_isWindowClosed = true;
		}

		else if (events.type == SDL_KEYDOWN)
		{
			m_isKeyPressed = true;
			m_KeyDown = events.key.keysym.sym;
			std::cout << m_KeyDown << std::endl;
		}

		else if (events.type == SDL_KEYUP)
		{
			m_isKeyPressed = false;
			m_KeyDown = ' ';
			m_KeyUp = events.key.keysym.sym;
		}

		else if (events.type == SDL_MOUSEBUTTONDOWN) //mouse button pressed DOWN
		{
			m_isMouseClicked = true;
			m_MouseButtonDown = events.button.button; //which button pressed
			

		}

		else if (events.type == SDL_MOUSEBUTTONUP)
		{
			m_isMouseClicked = false;
			m_MouseButtonUp = events.button.button;
		}

		else if (events.type == SDL_MOUSEMOTION)
		{
			m_MousePosition.x = events.motion.x;
			m_MousePosition.y = events.motion.y;
		}
	}
}

const MousePos& Input::GetMousePosition()
{
	return m_MousePosition;
}

void Input::MouseSound()
{
	m_mouseSound.Load("ASSETS/Sounds/blade.ogg");
	m_mouseSound.Play(0);
	m_mouseSound.SetVolume(10);
}

int Input::GetMouseButtonUp()
{
	return m_MouseButtonUp;
}

int Input::GetMouseButtonDown()
{
	return m_MouseButtonUp;
}

bool Input::isMouseClicked()
{
	return m_isMouseClicked;
}