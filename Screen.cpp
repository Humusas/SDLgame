#include <iostream>
#include <SDL.h>
#include "Screen.h"

Screen* Screen::Instance()
{
	static Screen* screenObject = new Screen();
	
	return screenObject;
}

bool Screen::Initialize(const std::string& windowTitle, int width, int height) //has to be bool (T/F)
{
	std::cout << "Initializing started" << std::endl;
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) // if value -1 ->error inializing
	{
		std::cout << "Trouble initializing SDL" << std::endl;
		return false;
	}

	//window is a handle for SDL_CreateWindow. game window we play in
	window = SDL_CreateWindow(windowTitle.c_str(),	//game title
		SDL_WINDOWPOS_CENTERED,				// x
		SDL_WINDOWPOS_CENTERED,				// y
		width,								//width
		height,								//heigh
		0);									//flags

	if (!window) //if no window
	{
		std::cout << "Error creating game window" << std::endl;
		return false;
	}

	//prepare screen to show in game window as next scene ( window, uses GPU and framework of monitor is synchronized with graphics card)
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!renderer)	//if no renderer
	{
		std::cout << "Error creating renderer" << std::endl;
		return false;
	}

	//if no false from if statements -> initialize completed
	std::cout << "Initializing completed" << std::endl;
	return true;
}

void Screen::Clear()
{
	SDL_RenderClear(renderer);
}

SDL_Renderer* Screen::GetRenderer()
{
	return renderer;
}

void Screen::Present()
{
	SDL_RenderPresent(renderer);
}

void Screen::Shutdown()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}