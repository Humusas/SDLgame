#include <iostream>
#include <SDL_image.h>
#include "Image.h"
#include "SDL.h"
#include "Screen.h"

Image::Image()
{
	std::cout << "Image created" << std::endl;
}

Image::~Image()
{
	std::cout << "Image destroyed" << std::endl;
}

void Image::Render(int xPos, int yPos, double angle, int width, int height, Screen& screen)
{
	SDL_Rect sourceRect;
	SDL_Rect targetRect;	//destination

	sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = m_resolution.x;
	sourceRect.h = m_resolution.y;

	//destination to show image
	targetRect.x = xPos;
	targetRect.y = yPos;
	targetRect.w = width;
	targetRect.h = height;

	SDL_Point centre{ 0,0 }; //m_resolution.x * 0.5f, m_resolution.y * 0.5f - midle of image 
																		//angle to rotate image
	SDL_RenderCopyEx(screen.GetRenderer(), m_image, &sourceRect, &targetRect, angle, &centre, SDL_FLIP_NONE);
}

bool Image::Load(const std::string& filename, Screen& screen)
{	//from raw data we do texture
	std::cout << "Image loading started" << std::endl;
	SDL_Surface* rawImageData = IMG_Load(filename.c_str());
	if (!rawImageData)
	{
		std::cout << "Error loading image file" << std::endl;
		return false;
	}

	m_image = SDL_CreateTextureFromSurface(screen.GetRenderer(), rawImageData);

	return true;
}

void Image::Unload()
{
	SDL_DestroyTexture(m_image);
}

void Image::GetResolution()
{
	m_resolution;
}

void Image::SetResolution(int width, int height)
{
	m_resolution = { width, height };
}