#pragma once
#include "GameObject.h"
#include "Text.h"

class Score : public GameObject
{
public:

	Score();
	~Score();

	int GetScore();

	void SetScore(int score);
	void AddScore(int extraScore);

	virtual void Update(Input& input);
	virtual void Render(Screen& screen);


private:

	int m_score;

	int m_newScore;

	Text m_text;

};