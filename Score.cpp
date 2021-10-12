#include "Score.h"



Score::Score()
{
	m_text.Load("ASSETS/Fonts/Wabroye.ttf", 1000);
	m_text.SetColor(255, 0, 0, 255); //red
	m_text.SetDimension(100, 100);

	m_score = 0;
}

Score::~Score()
{
	m_text.Unload();
}

int Score::GetScore()
{
	return m_newScore;
}

void Score::SetScore(int score)
{
	m_score = score;
	m_text.SetText(std::to_string(m_score));
}

void Score::AddScore(int extraScore)
{
	m_score = m_score + extraScore;
	m_text.SetText(std::to_string(m_score));
}

void Score::Update(Input& input)
{

}

void Score::Render(Screen& screen)
{
	m_text.Render(50, 50, screen);
}
