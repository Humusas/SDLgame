#include <iostream>
#include "Player.h"
#include "Vector2D.h"
//#include "Music.h"
//#include "Score.h"

Player::Player()
{
	std::cout << "Player created" << std::endl;
	//m_state = IDLE;
	
	//m_playerImage.Load("ASSETS/Images/maybe.png");
	//m_playerImage.SetImageDimention(1,1,1003, 280 );
	//m_playerImage.SetSpriteDimention(260, 95);

	//============ no car on screen==========
	m_playerImage[State::Idle].Load("ASSETS/Images/1IDLE_anima.png");
	m_playerImage[State::Acellerating].Load("ASSETS/Images/1GAS_anima.png");

	m_position = { 3, 423 };

	for (int i = 0 ; i < State::Total_States; i++)
	{
		m_playerImage[i].SetImageCell(1050, 300);
		m_playerImage[i].SetImageDimention(9,1,9450,300);
		m_playerImage[i].SetSpriteDimention(438,125);
		m_playerImage[i].IsAnimated(true);   // no idle animation just different sounds
		m_playerImage[i].IsAnimationLooping(true);   // no idle animation just different sounds
		m_playerImage[i].SetAnimationVelocity(1.0f); //->
		
	}
	
	//m_collider.SetDimension(260, 95);
}

Player::~Player()
{
	m_playerImage[m_state].Unload();
	std::cout << "Player destroyed" << std::endl;
	
	//m_image[TOTAL_STATES].Unload();
}

Player::State Player::GetState() const
{
	return m_state;
}
//
//void Player::idleEngine()
//{
//	m_idleEngine.Play(Music::PlayLoop::Play_Endless);
//}
//
/*const BoxCollider& Player::GetCollider() const
{
	return m_collider;
}*/

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

			//		m_facingDirection = Direction::Left;
					//m_direction = m_direction.Scale(m_velocity);

					//m_position.x -= m_velocity; //floats on x axis
		}
		else if (Input::Instance()->IsKeyPressed(HM_KEY_D) == true)//SDLK_RIGHT))
		{
			m_direction.x = 1;
			m_direction.y = 0;
			m_position = m_position.Add(m_direction);

			//	m_facingDirection = Direction::Right;
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
	}
	else
	{
		m_direction.x = 0;
		m_direction.y = 0;

		//m_direction = m_direction.Scale(m_velocity);	
		//m_position = m_position.Add(m_direction);
		m_state = State::Idle;
		//m_idleEngine.SetVolume(5);
	}

		/*if (m_facingDirection == Direction::Right && m_velocity > 0)
		{
			//CAR MOVES - count how much it moved from starting point
			//m_score = m_position.Add(m_direction.x);

		}*/
	
	
	//m_collider.SetDimension(m_size.x, m_size.y);
	//m_collider.SetPosition(m_position.x, m_position.y);
	//std::cout << " x axis - " << m_position.x << "  y axis - " << m_position.y << std::endl;
	
	//m_collider.Update();
	//std::cout << static_cast<int>(GetState()) << std::endl; // states turn back and forward
	m_playerImage[m_state].Update();
//	std::cout << GetPosition().x << std::endl;
	//std::cout << GetPosition().y << std::endl;
	
}

void Player::Render()
{
	//m_image[TOTAL_STATES].Render(m_position.x, m_position.y, m_angle, screen, Sprite::HO_FLIP); //doesnt flip
	m_playerImage[m_state].Render(m_position.x, m_position.y, m_angle, Sprite::Flip::NO_FLIP); //doesnt flip
}