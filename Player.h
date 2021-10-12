#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "BoxCollider.h"
#include "Vector2D.h"
#include "Music.h"
#include "Score.h"

//inheritense: IS-A
//containment: HAS-A

class Player : public GameObject //player IS A game object
{
public:

	enum Direction { LEFT, RIGHT };

	enum State { IDLE, ACCELERATING, BRAKING, CRASH, TOTAL_STATES };

	//constructor, deconst.
	Player(Screen& screen);
	~Player();

	void idleEngine();

	const BoxCollider& GetCollider() const;

	void SetDirection(Direction);
	void SetVelocity(int velocity);

	virtual void Update(Input& input);
	virtual void Render(Screen& screen);

private:
	Score m_score;

	Music m_idleEngine;

	State m_state;

	int m_velocity;

	BoxCollider m_collider;
	Direction m_facingDirection;
	Screen& m_screen;
	Sprite m_image;
	//Sprite m_image[TOTAL_STATES]; //containment: player HAS AN image 
	
	Vector2D m_direction;
	Vector2D m_currentPossition;


};