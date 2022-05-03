#include <iostream>
#include <SDL.h>
#include "Input.h"
#include "Sound.h"

Input* Input::Instance()
{
	static Input* inputObject = new Input();
	return inputObject;
}

/*char Input::GetKeyUp()
{
	return m_KeyUp;
}*/

char Input::GetKeyDown()
{
	return m_keyDown;
}

bool Input::IsKeyPressed()
{
	return m_isKeyPressed;
}

bool Input::IsWindowClosed()
{
	return m_isWindowClosed;
}

void Input::Update()
{
	SDL_Event events;

	m_mouseMotion.x = 0;
	m_mouseMotion.y = 0;
	
	//SDL_PollEvent(&events);// takes one event and puts into events classs
							// 0-no events, 1 is . while there is event
	while (SDL_PollEvent(&events))
	{
		switch (events.type)
		{
			//when key press down
			case SDL_QUIT:
			{
				m_isWindowClosed = true;
				break;
			}

			case SDL_KEYUP:
			{
				m_isKeyPressed = false;
				m_keyDown = SDLK_UNKNOWN;
				m_modifier = events.key.keysym.mod;
				break;
			}

			case SDL_KEYDOWN:
			{
				m_isKeyPressed = true;
				m_keyDown |= events.key.keysym.mod;
				m_modifier |= events.key.keysym.mod;
				break;
			}

			case SDL_MOUSEMOTION:
			{
				m_mousePosition.x = events.motion.x;
				m_mousePosition.y = events.motion.y;
				
				m_mouseMotion.x = events.motion.xrel;
				m_mouseMotion.y = events.motion.yrel;
				break;
			}

			case SDL_MOUSEBUTTONUP:
			{
				m_isMouseClicked = false;
				m_mouseButtonUp = events.button.button;
				m_mousePosition.x = events.motion.x;
				m_mousePosition.y = events.motion.y;

				switch (events.button.button)
				{
				case SDL_BUTTON_LEFT:
				{
					m_mouseButtonDown ^= HM_MOUSE_LEFT;
					break;
				}

				case SDL_BUTTON_MIDDLE:
				{
					m_mouseButtonDown = HM_MOUSE_MIDDLE;
					break;
				}
				case SDL_BUTTON_RIGHT:
				{
					m_mouseButtonDown = HM_MOUSE_RIGHT;
					break;
				}
				}
				break;
			}
			
			case SDL_MOUSEBUTTONDOWN:
			{
				m_isMouseClicked = true;
				m_mousePosition.x = events.motion.x;
				m_mousePosition.y = events.motion.y;
				
				switch (events.button.button)
				{
					case SDL_BUTTON_LEFT:
					{
						m_mouseButtonDown ^= HM_MOUSE_LEFT;
						break;
					}
					case SDL_BUTTON_MIDDLE:
					{
						m_mouseButtonDown = HM_MOUSE_MIDDLE;
						break;
					}
					case SDL_BUTTON_RIGHT:
					{
						m_mouseButtonDown = HM_MOUSE_RIGHT;
						break;
					}
				}
				break;			
			}
		}
		/*		
		else if (events.type == SDL_MOUSEMOTION)
		{
			m_MousePosition.x = events.motion.x;
			m_MousePosition.y = events.motion.y;
		}*/
	}
}

const Vector2D& Input::GetMousePosition()
{
	return m_mousePosition;
}

const Vector2D& Input::GetMouseMotion()
{
	return m_mouseMotion;
}

void Input::MouseSound()
{
	m_mouseSound.Load("ASSETS/Sounds/blade.ogg");
	m_mouseSound.Play(0);
	m_mouseSound.SetVolume(5);
}

int Input::GetMouseButtonUp()
{
	return m_mouseButtonUp;
}

int Input::GetMouseButtonDown()
{
	return m_mouseButtonUp;
}

bool Input::IsMouseClicked()
{
	return m_isMouseClicked;
}

void Input::SetCursorState(bool isCursorEnabled, bool isCursorVisible)
{
	SDL_SetRelativeMouseMode(static_cast<SDL_bool>(isCursorEnabled));
	SDL_ShowCursor(static_cast<int>(isCursorVisible));
}

bool Input::IsKeyPressed(int keyCode) const
{
	const Uint8* m_keyStates = SDL_GetKeyboardState(nullptr);
	return m_keyStates[keyCode];
}

bool Input::IsModifierKeyPressed(int modifier_1, int modifier_2)
{
	return m_modifier == (modifier_1|modifier_2);
}

bool Input::IsMouseClicked(int mouseButton_1, int mouseButton_2)
{
	return m_mouseButtonDown == (mouseButton_1|mouseButton_2);
}
