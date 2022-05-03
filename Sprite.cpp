#include <iostream>
#include <SDL_image.h>
#include "Sprite.h"
#include "Screen.h"
#include "SDL.h"

Sprite::Sprite()
{
	m_image = nullptr;

	m_imageCell = 0;
	

	m_isAnimated = false;
	m_isAnimationDead = false;
	m_isAnimationLooping = false;

	m_cellDimention = { 0, 0 };
	m_imageDimention = { 0, 0 };
	m_spriteDimention = { 0, 0 };

	m_animationVelocity = 0.0f;

	std::cout << "Image created" << std::endl;
}

Sprite::~Sprite()
{
	std::cout << "Image destroyed" << std::endl;
}

void Sprite::Render(int xPos, int yPos, double angle, Flip flip)
{
	//if(!IsAnimationDead)

	SDL_Rect sourceRect;	//source in memmory
	SDL_Rect targetRect;	//destination

	//location in sprite sheet what to cut for target rect
	sourceRect.x = (m_imageCell % m_imageDimention.x) * m_cellDimention.x;
	sourceRect.y = (m_imageCell / m_imageDimention.x) * m_cellDimention.y;
	sourceRect.w = m_cellDimention.x;
	sourceRect.h = m_cellDimention.y;

	//destination to show image on screen
	targetRect.x = xPos;
	targetRect.y = yPos;
	targetRect.w = m_spriteDimention.x;
	targetRect.h = m_spriteDimention.y;

	SDL_Point centre{ m_spriteDimention.x * 0.5f, m_spriteDimention.y * 0.5f }; //vidurys sprite 

	SDL_RenderCopyEx(Screen::Instance()->GetRenderer(), m_image, &sourceRect, &targetRect, angle, &centre, SDL_FLIP_NONE/* static_cast<SDL_RendererFlip>(flip)*/);
}

void Sprite::Update()
{
	if (m_isAnimated)
	{
		static float total = 0.0f;
		total += 0.1f;

		std::cout << total << std::endl;

		//m_imageCell = total % (m_imageDimention.x * m_imageDimention.y);

		m_imageCell = static_cast<int>(total * m_animationVelocity) % (m_imageDimention.x * m_imageDimention.y);

		if (!m_isAnimationLooping && m_imageCell == (m_imageDimention.x * m_imageDimention.y - 1))
		{
			m_isAnimationDead = true;
		}
	}
}

bool Sprite::Load(const std::string& filename)
{	//from raw data we do texture
	SDL_Surface* rawImageData = IMG_Load(filename.c_str());
	if (!rawImageData)
	{
		std::cout << "Error loading image file" << std::endl;
		return false;
	}

	m_image = SDL_CreateTextureFromSurface(Screen::Instance()->GetRenderer(), rawImageData);
	return true;
}

void Sprite::Unload()
{
	SDL_DestroyTexture(m_image);
}

void Sprite::IsAnimated(bool flag)
{
	m_isAnimated = flag;
}

void Sprite::IsAnimationLooping(bool flag)
{
	m_isAnimationLooping = flag;
}

void Sprite::SetImageCell(int column, int row)
{
	m_imageCell = ((row - 1) * m_imageDimention.x) + (column - 1);
}

//resolution of sprite image how it will appear on screen
void Sprite::SetSpriteDimention(int width, int height)
{
	m_spriteDimention.x = width;
	m_spriteDimention.y = height;
}

//resolution of collum/rows dimention of sprite image in asset forlder
void Sprite::SetImageDimention(int columns, int rows, int width, int height)
{
	m_imageDimention.x = columns;
	m_imageDimention.y = rows;

	m_cellDimention.x = width / columns;
	m_cellDimention.y = height / rows;
}

void Sprite::SetAnimationVelocity(float velocity)
{
	m_animationVelocity = velocity;
}
