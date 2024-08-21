#include "Collisions.h"

//initialise instance to nullptr
Collisions* Collisions::m_instance = nullptr;

Collisions::Collisions()
{
	
}

Collisions::~Collisions()
{
	m_instance = nullptr;
}

Collisions* Collisions::Instance()
{
	if (!m_instance)
	{
		m_instance = new Collisions;
	}

	return m_instance;
}

bool Collisions::Circle(GameObject* a, GameObject* b)
{
	Vector2D vec = Vector2D((a->GetPosition().x - b->GetPosition().x), (a->GetPosition().y - b->GetPosition().y));

	double distance = sqrt((vec.x * vec.x) + (vec.y * vec.y));

	double combined_distance = (a->GetCollisionRadius() + b->GetCollisionRadius());

	return distance < combined_distance;
}

bool Collisions::Box(Rect2D rect1, Rect2D rect2)
{
	if (rect1.x + rect1.width > rect2.x &&
		rect1.x < rect2.x + rect2.width &&
		rect1.y + rect1.height > rect2.y &&
		rect1.y < rect2.y + rect2.height)
	{
		return true;
	}

	return false;
}