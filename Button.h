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

	void ButtonSound(); //click sound when you press the button
	bool HoveredOver();
	bool IsClicked();

	virtual void Update();
	virtual void Render();

	void SetButtonCointainer(int width, int height);

	const BoxCollider& GetCollider() const;

protected:

	bool m_mouseOverButton;

	Vector2D m_min;
	Vector2D m_max;

	bool buttonDown;
	Sound m_sound; //pressed button sound
	BoxCollider m_collider;

	Sprite m_buttonImage; // button has an image

};