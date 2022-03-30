#include <iostream>
#include "Player.h"
#include "Vector2D.h"
#include "Music.h"
#include "Score.h"

Player::Player(Screen& screen) : m_screen(screen)
{
	std::cout << "Player created" << std::endl;
	//m_state = IDLE;

	m_image.Load("Assets/Images/judge.png", screen);
	m_image.SetImageDimention(1, 1, 1080, 500);
	m_image.SetSpriteDimention(270, 125);

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
	//m_image[TOTAL_STATES].Unload();
	m_image.Unload();
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

void Player::Update(Input& input)
{
	if (input.GetKeyDown() == SDL_SCANCODE_LEFT)//'a')
	{
		m_facingDirection = Direction::Left;
		m_direction.x = -1;
		m_direction.y = 0;
		m_direction = m_direction.Scale(m_velocity);
		m_position = m_position.Add(m_direction);
		
		//m_position.x -= m_velocity; //floats on x axis
	}
	else if (input.GetKeyDown() == SDL_SCANCODE_RIGHT)// 'd')
	{
		m_facingDirection = Direction::Right;
		m_direction.x = 1;
		m_direction.y = 0;
		m_direction = m_direction.Scale(m_velocity);
		m_position = m_position.Add(m_direction);
		
		//m_position.x += m_velocity; //floats on x axis
	}
	else if (input.GetKeyDown() == SDL_SCANCODE_UP) //'w')
	{
		m_direction.x = 0;
		m_direction.y = -1;

		m_direction = m_direction.Scale(m_velocity);
		m_position = m_position.Add(m_direction);

		m_state = State::Acellerating;

		//m_position.y -= m_velocity; //floats on x axis
	}
	else if (input.GetKeyDown() == SDL_SCANCODE_DOWN)//'s')
	{
		m_direction.x = 0;
		m_direction.y = 1;
		m_direction = m_direction.Scale(m_velocity);
		m_position = m_position.Add(m_direction);

		m_state = State::Braking;

		//m_position.y += m_velocity; //floats on x axis
	}
	else
	{
		m_direction.x = 0;
		m_direction.y = 0;

		m_direction = m_direction.Scale(m_velocity);
		m_position = m_position.Add(m_direction);

		m_state = State::Idle;
		m_idleEngine.SetVolume(5);

	}

	if (m_facingDirection == Direction::Right && m_velocity > 0)
	{
		//CAR MOVES - count how much it moved from starting point
	//m_score = m_position.Add(m_direction.x);

	}


	//m_collider.SetDimension(m_size.x, m_size.y);
	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();
	
}

void Player::Render(Screen& screen)
{
	//m_image[TOTAL_STATES].Render(m_position.x, m_position.y, m_angle, screen, Sprite::HO_FLIP); //doesnt flip
	m_image.Render(m_position.x, m_position.y, m_angle, screen, Sprite::NO_FLIP); //doesnt flip

}