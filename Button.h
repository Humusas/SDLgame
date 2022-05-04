#pragma once
#include "BoxCollider.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Sound.h"
#include "Text.h"

class Button : public GameObject //button is a game object
{
public:

	Button();
	~Button();

	enum class ButtonStates
	{
		idle,
		hovered,
		pressed
	};


	void PlayButtonSound(); //click sound when you press the button
	bool HoveredOver(); 
	bool IsClicked();
	void SetButtonCointainer(int width, int height); //button dimensions in which to load sprite
	
	virtual void Update(); //change picture when hovered, play sound when clicked
	virtual void Render(); //render button
	
	const BoxCollider& GetCollider() const;

protected:

	bool m_mouseOverButton;

	Vector2D m_min;
	Vector2D m_max;
	Sound m_buttonSound; //pressed button sound
	Sprite m_buttonImage; // button has an image



	BoxCollider m_collider;


};