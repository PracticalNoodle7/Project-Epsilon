#pragma once
#include "Commons.h"
#include "Character.h"
#include "Item.h"

class Character;

class Collisions
{
public:
	~Collisions();

	static Collisions* Instance();

	bool Circle(GameObject* a, GameObject* b, Collision_Type Type);
	bool CircleDropItems(GameObject* a, DroppedItems b, Collision_Type Type);
	bool Box(Rect2D rect1, Rect2D rect2);
	bool Box(Rect2D rect1, BackgroundManager* m_background, int row, int column);

private:
	Collisions();

	static Collisions* m_instance;
};

