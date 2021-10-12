#pragma once
#include <SDL.h>
#include <string>
#include "Input.h"
#include "Screen.h"
#include "Vector2D.h"

//Abstract Based Class - has at lest 1 virtual function that is meant to be overwritten
class GameObject
{
public:
	GameObject();

	//Getter, setter
	const std::string GetTag() const;

	float GetAngle() const;
	const Vector2D& GetPosition() const; //const correct to stay same always
	const Vector2D& GetSize() const;

	void SetTag(const std::string& tag);
	void SetAngle(float angle);

	void SetPosition(int x, int y);
	void SetPosition(const Vector2D& position);

	void SetSize(int width, int height);
	void SetSize(const Vector2D& size);

	virtual void Update(Input& input) = 0;
	virtual void Render(Screen& screen) = 0;

protected:
	std::string m_tag;
	float m_angle;
	Vector2D m_position;   //x y in a struct
	Vector2D m_size;
};