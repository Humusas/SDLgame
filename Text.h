#pragma once
#include <string>
#include <iostream>
#include <SDL_ttf.h>
#include "Screen.h"

class Text
{
public:

	Text();
	~Text() {};

	static bool Initialize();
	static void Shutdown();

	void SetResolution();

	void SetText(std::string text);
	void SetColor(SDL_Color& color);
	void SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void SetDimension(int width, int height);

	bool Load(const std::string& filename, int fontSize);
	void Render(int xPos, int yPos);
	void Unload();

private:


	bool m_isDirty; //update only when changed - when got dirty
	std::string m_text; //actual text

	TTF_Font* m_font;
	SDL_Color m_color;
	SDL_Point m_dimension; //how large on screen
	SDL_Texture* m_texture;
};