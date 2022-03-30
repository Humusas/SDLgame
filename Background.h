#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "BoxCollider.h"
#include "Music.h"

//inheritense: IS-A
//containment: HAS-A

class Background : public GameObject //background IS A game object
{
public:

	//constructor, deconst.
	Background(Screen& screen);
	~Background();

	void BackgroundMusic();
	void BackgroundImage();

	virtual void Update(Input& input);
	virtual void Render(Screen& screen);

	const BoxCollider& GetCollider() const;

private:

	Music m_music;
	BoxCollider m_collider;
	Sprite m_image; //containment: background HAS AN image 
};