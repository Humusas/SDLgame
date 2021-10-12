#pragma once
#include <string>
#include "Screen.h"
#include "SDL.h"

class Image
{
public:
	Image();
	~Image();

public:

	bool Load(const std::string& filename, Screen& screen);
	void Unload();
	void Render(int xPos, int yPos, double angle, int width, int height, Screen& screen);

	void GetResolution();
	void SetResolution(int width, int height);

private:
	SDL_Point m_resolution; //width and hight of image
	SDL_Texture* m_image = nullptr;
};