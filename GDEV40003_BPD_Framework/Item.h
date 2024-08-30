#pragma once
#include "ItemManager.h"

class Item : public ItemManager
{
	Item(SDL_Renderer* renderer, Vector2D start_position);
	~Item();

	virtual void Render() override;
	virtual void Update(float deltaTime, SDL_Event e) override;

	void DropItem(int itemNum);
};

