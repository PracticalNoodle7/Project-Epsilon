#pragma once
#include "GameObject.h"
#include "vector"

class Item : public GameObject
{
	Item(SDL_Renderer* renderer, Vector2D start_position);
	~Item();

	virtual void Render() override;
	virtual void Update(float deltaTime, SDL_Event e) override;

	void DropItem(string imagePath, Vector2D m_position, int m_quantity);

	vector<DroppedItems> m_dropped_items;
};

