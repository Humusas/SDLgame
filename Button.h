#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "BoxCollider.h"
#include "Sound.h"

class Button : public GameObject //button is a game object
{
public:

	Button(Screen& screen);
	~Button();

	void ButtonSound(); //click sound when you press the button

	virtual void Update(Input& input);
	virtual void Render(Screen& screen);

	const BoxCollider& GetCollider() const;

protected:

	Sound m_sound;
	BoxCollider m_collider;
	Sprite m_image; // button has an image

};