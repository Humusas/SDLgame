#include <iostream>
#include "Background.h"
#include "Music.h"
#include "BoxCollider.h"
#include "Image.h"

Background::Background(Screen& screen)
{
	std::cout << "Background created" << std::endl;
	m_image.Load("ASSETS/Images/forest.png", screen);
	m_image.SetImageDimention(1,1,1920, 1080);
	m_image.SetSpriteDimention(1280,720);

	m_music.Load("ASSETS/Sounds/bensound_punky.mp3");

	m_collider.SetDimension(1280, 720);
}

Background::~Background()
{
	std::cout << "Background destroyed" << std::endl;
	m_music.Stop();
	m_image.Unload();
}

void Background::Update(Input& input)
{
	m_music.SetVolume(3);

	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();	
}

void Background::Render(Screen& screen)
{
	m_image.Render(m_position.x, m_position.y, m_angle, screen, Sprite::Flip::NO_FLIP);
}

const BoxCollider& Background::GetCollider() const
{
	return m_collider;
}

void Background::BackgroundMusic()
{
	m_music.Play(Music::PlayLoop::Play_Endless);
}

void Background::BackgroundImage()
{
	

}