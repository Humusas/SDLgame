#pragma once
#include "GameObject.h"
#include "Text.h"

class Credits : public GameObject
{
public:

	Credits();
	~Credits();

	void SetCredits(std::string credits);

	virtual void Update(Input& input);
	virtual void Render(Screen& screen);


private:

	std::string m_credits;
	Text m_text;

};