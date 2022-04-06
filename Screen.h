#pragma once
#include <SDL.h>
#include <string>
#include <iostream>

class Screen
{
public:

	//void SetWidth;
	//void SetHeight;
	
	static Screen* Instance(); //singleton

	bool Initialize(const std::string& windowTitle = "<No name>", int width = 1000, int height = 1000);
	void Shutdown();
	void Present();
	void Clear();

	SDL_Renderer* GetRenderer();

	//State
private:

	Screen() { std::cout << "Screen object created" << std::endl; };						//constructor
	Screen(const Screen&);				//copy constructor
	Screen& operator=(const Screen&);   //assignment operator

	//int m_width = 1000;
	//int m_height = 750;

	SDL_Window* window = nullptr;		//no value in pointer
	SDL_Renderer* renderer = nullptr;	//no value in pointer
};