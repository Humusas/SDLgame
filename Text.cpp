#include <iostream>
#include "Screen.h"
#include "Text.h"

bool Text::Initialize()
{
	if (TTF_Init() == -1) // -1 - smthg went wrong 
	{
		std::cout << "Error initializing text" << std::endl;
		return false;
	}
	return true;
}

void Text::Shutdown()
{
	TTF_Quit();
}

Text::Text()
{
	m_font = nullptr;
	m_isDirty = true;
	m_color = { 255,255,255,255 };
	m_dimension = { 10,10 };
}

//Text::~Text()
//{
//}


void Text::SetText(std::string text)
{
	m_text = text;
	m_isDirty = true; //if i change text
}

void Text::SetColor(SDL_Color& color)
{
	m_color = color; //object color
	m_isDirty = true; //if i change color
}

void Text::SetResolution()
{


}

void Text::SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	m_color.r = r;
	m_color.g = g;
	m_color.b = b;
	m_color.a = a;
	m_isDirty = true;
}

void Text::SetDimension(int width, int height)
{
	m_dimension = { width, height };
}

bool Text::Load(const std::string& filename, int fontsize)
{
	m_font = TTF_OpenFont(filename.c_str(), fontsize);

	if (!m_font)
	{
		std::cout << "Error loading font file" << std::endl;
		return false;
	}
	return true;
}

void Text::Render(int xPos, int yPos, Screen& screen)
{
	//we create text in rectangular
	SDL_Rect targetRect;

	targetRect.x = xPos;
	targetRect.y = yPos;
	targetRect.w = m_dimension.x;
	targetRect.h = m_dimension.y;

	if (m_isDirty)
	{
		SDL_DestroyTexture(m_texture); //destroy old texture
		SDL_Surface* textData = TTF_RenderText_Blended(m_font, m_text.c_str(), m_color); //makes text as an image 
		m_texture = SDL_CreateTextureFromSurface(screen.GetRenderer(), textData);
		SDL_FreeSurface(textData);
		m_isDirty = false;
	}

	SDL_RenderCopy(screen.GetRenderer(), m_texture, nullptr, &targetRect);
}

void Text::Unload()
{
	TTF_CloseFont(m_font);
}
