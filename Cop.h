#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "BoxCollider.h"
#include "Vector2D.h"

//inheritense: IS-A
//containment: HAS-A

class Cop : public GameObject //cop IS A game object
{
public:

	enum Direction	{ LEFT,RIGHT	};

	//constructor, deconst.
	Cop();
	~Cop();

	const BoxCollider& GetCollider() const;

	void SetDirection(Direction);
	void SetVelocity(int velocity);

	virtual void Update();
	virtual void Render();

private:

	int m_velocity;

	BoxCollider m_collider;
	Direction m_facingDirection;
	//Screen& m_screen;
	Sprite m_image; //containment: player HAS AN image 
	Vector2D m_direction;
};
