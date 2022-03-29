#include <iostream>
#include "Button.h"
#include "Sound.h"
#include "BoxCollider.h"

Button::Button(Screen& screen)
{
	std::cout << "Button created" << std::endl;
	m_image.Load("ASSETS/Images/forest.png", screen);
	m_image.SetImageDimention(1, 1, 1920, 1080);
	m_image.SetSpriteDimention(1280, 720);

	m_sound.Load("ASSETS/Sounds/bensound_punky.mp3");

	m_collider.SetDimension(1280, 720);
}

Button::~Button()
{
	std::cout << "Background destroyed" << std::endl;
	m_sound.Unload();
	m_image.Unload();
}

void Button::Update(Input& input)
{
	m_sound.SetVolume(3);

	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();
}

void Button::Render(Screen& screen)
{
	m_image.Render(m_position.x, m_position.y, m_angle, screen, Sprite::Flip::NO_FLIP);
}

const BoxCollider& Button::GetCollider() const
{
	return m_collider;
}

void Button::ButtonSound()
{
	//m_music.Play(Music::PlayLoop::Play_Endless);
}