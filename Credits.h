#pragma once
#include "GameObject.h"
#include "Text.h"

class Credits : public GameObject
{
public:

	Credits();
	~Credits();

	void SetCredits(std::string credits);

	virtual void Update();
	virtual void Render();


private:

	std::string m_credits;
	Text m_text;

};