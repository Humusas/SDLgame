#pragma once
#include <SDL.h>
#include <string>

class Screen
{
	//Getter, setter
public:

	//void SetWidth;
	//void SetHeight;

	//Behaviour
public:

	//const std::string&window_title="<no name>", int width= 1250, int height= 500
	bool Initialize(const std::string& windowTitle = "<No name>", int width = 1000, int height = 1000);
	void Shutdown();
	void Present();
	void Clear();

	SDL_Renderer* GetRenderer();

	//State
private:
	//int m_width = 1000;
	//int m_height = 750;

	SDL_Window* window = nullptr;		//no value in pointer
	SDL_Renderer* renderer = nullptr;	//no value in pointer
};