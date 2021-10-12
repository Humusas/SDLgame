#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "BoxCollider.h"


//inheritense: IS-A
//containment: HAS-A

class Background2 : public GameObject //background IS A game object
{
public:


	//constructor, deconst.
	Background2(Screen& screen);
	~Background2();

	virtual void Update(Input& input);
	virtual void Render(Screen& screen);



	const BoxCollider& GetCollider() const;

private:



	BoxCollider m_collider;

	Sprite m_image; //containment: background HAS AN image 
};