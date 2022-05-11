#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "BoxCollider.h"
#include "Vector2D.h"
//#include "Music.h"
#include "Screen.h"
#include "Input.h"
//#include "Score.h"

//inheritense: IS-A
//containment: HAS-A

class Player : public GameObject //player IS A game object
{
public:

//	enum class Direction { Left, Right }

	enum State
	{
		Idle,
		Acellerating,
		Braking,
		Crash,
		Total_States
	};

	//constructor, deconst.
	Player();
	~Player();

//	void idleEngine();
	State GetState() const;

//	const BoxCollider& GetCollider() const;

	void SetDirection(Vector2D direction);
	void SetVelocity(int velocity);

	virtual void Update();
	virtual void Render();

private:

	State m_state{State::Idle};
	Sprite m_playerImage[State::Total_States];//*because enum class


	//player HAS a
//	BoxCollider m_collider;

//	Music m_idleEngine;

	int m_velocity=5;

//	Direction m_facingDirection;

	//Sprite m_image[TOTAL_STATES]; //containment: player HAS AN image 
//	Score m_score;
	
	Vector2D m_direction;
	Vector2D m_currentPossition;

};