#include <iostream>
#include "Player.h"
#include "Vector2D.h"
#include "Music.h"
#include "Score.h"

Player::Player()
{
	std::cout << "Player created" << std::endl;
	//m_state = IDLE;
	
	m_playerImage.Load("ASSETS/Images/maybe.png");
	m_playerImage.SetImageDimention(1,1,1003, 280 );
	m_playerImage.SetSpriteDimention(260, 95);
	m_position = { 3, 423 };

	//============ no car on screen==========
	//m_image[IDLE].Load("Assets/Images/judge.png", screen);
	//m_image[ACCELERATING].Load("Assets/Images/judge.png", screen);
	//m_image[BRAKING].Load("Assets/Images/judge.png", screen);
	//m_image[CRASH].Load("Assets/Images/judge.png", screen);

	/*for (int i = 0 ; i < TOTAL_STATES; i++)
	{
		m_image[i].Load("Assets/Images/judge.png", screen);
		m_image[i].SetImageDimention(1,1,1080,500);
		m_image[i].SetSpriteDimention(270,125);
		m_image[i].IsAnimated(false);   // no idle animation just different sounds
		
		if (i == IDLE)
		{
			m_idleEngine.Load("ASSETS/Sounds/engine.ogg");
			m_image[i].IsAnimationLooping(false);
		}
		else if (i == ACCELERATING)
		{
			m_image[i].IsAnimationLooping(false);
		}
		else if (i == BRAKING)
		{
			m_image[i].IsAnimationLooping(false);
		}
		else if (i == CRASH)
		{
			m_image[i].IsAnimationLooping(false);
		}
	}*/
	
	m_collider.SetDimension(260, 95);
}

Player::~Player()
{
	std::cout << "Player destroyed" << std::endl;
	m_playerImage.Unload();
	
	//m_image[TOTAL_STATES].Unload();
}

void Player::idleEngine()
{
	m_idleEngine.Play(Music::PlayLoop::Play_Endless);
}

const BoxCollider& Player::GetCollider() const
{
	return m_collider;
}

void Player::SetDirection(Vector2D direction)
{
	m_direction = direction;
}

void Player::SetVelocity(int velocity)
{
	m_velocity = velocity;
}

void Player::Update()
{
	if (Input::Instance()->IsKeyPressed() == true)
	{
		//std::cout << "key pressed" << std::endl;
		if (Input::Instance()->IsKeyPressed(HM_KEY_A) == true)// 'a')//SDLK_LEFT))
		{
			m_direction.x = -1;
			m_direction.y = 0;
			m_position = m_position.Add(m_direction);
			
			m_facingDirection = Direction::Left;
			//m_direction = m_direction.Scale(m_velocity);

			//m_position.x -= m_velocity; //floats on x axis
		}
		else if (Input::Instance()->IsKeyPressed(HM_KEY_D) == true)//SDLK_RIGHT))
		{
			m_direction.x = 1;
			m_direction.y = 0;
			m_position = m_position.Add(m_direction);
			
			m_facingDirection = Direction::Right;
			//m_direction = m_direction.Scale(m_velocity);

			//m_position.x += m_velocity; //floats on x axis
		}
		else if (Input::Instance()->IsKeyPressed(HM_KEY_W) == true)//SDLK_UP))
		{
			m_direction.x = 0;
			m_direction.y = -1;
			m_position = m_position.Add(m_direction);

			//m_direction = m_direction.Scale(m_velocity);

			m_state = State::Acellerating;

			//m_position.y -= m_velocity; //floats on x axis
		}
		else if (Input::Instance()->IsKeyPressed(HM_KEY_S) == true)//SDLK_DOWN)//'s')
		{
			m_direction.x = 0;
			m_direction.y = 1;
			m_position = m_position.Add(m_direction);
			
			//			m_direction = m_direction.Scale(m_velocity);

			m_state = State::Braking;

			//	m_position.y += m_velocity; //floats on x axis
		}
		else
		{
			m_direction.x = 0;
			m_direction.y = 0;

			//m_direction = m_direction.Scale(m_velocity);
			//m_position = m_position.Add(m_direction);

			m_state = State::Idle;
			m_idleEngine.SetVolume(5);

		}

		if (m_facingDirection == Direction::Right && m_velocity > 0)
		{
			//CAR MOVES - count how much it moved from starting point
			//m_score = m_position.Add(m_direction.x);

		}
	}
	
	m_collider.SetDimension(m_size.x, m_size.y);
	m_collider.SetPosition(m_position.x, m_position.y);
	//std::cout << " x axis - " << m_position.x << "  y axis - " << m_position.y << std::endl;
	
	m_collider.Update();
	m_playerImage.Update();
	
}

void Player::Render()
{
	//m_image[TOTAL_STATES].Render(m_position.x, m_position.y, m_angle, screen, Sprite::HO_FLIP); //doesnt flip
	m_playerImage.Render(m_position.x, m_position.y, m_angle, Sprite::Flip::NO_FLIP); //doesnt flip

}