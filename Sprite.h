#pragma once
#include <string>
#include "Screen.h"
#include "SDL.h"
#include "Vector2D.h"

class Sprite
{
public:

	enum class Flip
	{
		NO_FLIP = SDL_FLIP_NONE,
		HO_FLIP = SDL_FLIP_HORIZONTAL,
		VERT_FLIP = SDL_FLIP_VERTICAL
	};

	Sprite();
	~Sprite();

	bool Load(const std::string& filename);
	void Unload();

	void IsAnimated(bool flag);
	void IsAnimationLooping(bool flag);

	void SetImageCell(int column, int row);
	void SetSpriteDimention(int width, int height); // how large on screen
	void SetImageDimention(int columns, int rows, int width, int height); // whole sprite sheet size in-folder

	void SetAnimationVelocity(float velocity);

	void GetCentrePosition();

	void Update(); //cut from sprite animation sheet 1 single shot
	void Render(int xPos, int yPos, double angle, Flip flip);

private:

	Flip m_imageFlip;

	int m_imageCell;

	float m_animationVelocity;

	bool m_isAnimated;
	bool m_isAnimationLooping;
	bool m_isAnimationDead;

	SDL_Texture* m_image;
	//SDL_Point m_spriteDimention; //width and hight of entire sprite image on screen
	//SDL_Point m_cellDimention; //width and hight of one cell in sprite
	//SDL_Point m_imageDimention; //width and hight of entire sprite image
	SDL_Point centre { 0,0 };

	Vector2D m_spriteDimention; //width and hight of entire sprite image on screen
	Vector2D m_cellDimention; //width and hight of one cell in sprite
	Vector2D m_imageDimention; //width and hight of entire sprite image


};