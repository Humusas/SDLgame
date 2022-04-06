#include "Credits.h"

Credits::Credits()
{
	//m_score = 0;
	//m_text.Load("Assets/Fonts/", 100);
	m_text.SetColor(255, 0, 0, 255); //red
	m_text.SetDimension(200, 75);
}

Credits::~Credits()
{
	m_text.Unload();
}

void Credits::SetCredits(std::string credits)
{
	//m_credits = credits;
}

void Credits::Update()
{
	//m_text.SetText(std::to_string(m_credits));
}

void Credits::Render()
{
	m_text.Render(20, 20);
}
