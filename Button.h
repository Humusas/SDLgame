#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Sound.h"

class Button : public GameObject //button is a game object
{
public:

	enum class ButtonStates
	{
		idle,
		hovered,
		pressed
	};

	Button(const std::string& filename);
	~Button();

	const ButtonStates& GetButtonState() const; //pointer

	virtual void Update(); //change picture when hovered, play sound when clicked
	virtual void Render(); //render button

protected:

	ButtonStates m_buttonState { ButtonStates::idle };
	Sprite m_buttonImage; // button has an image
	SDL_Rect m_mouseRect;
	SDL_Rect m_buttonRect;//cursor (mouse) and button images positions as rectangles 
	Sound m_buttonSound;
};