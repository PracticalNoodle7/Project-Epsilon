#pragma once
#include "GameObject.h"


class ItemManager : public GameObject
{
public:
	ItemManager(SDL_Renderer* renderer, Vector2D start_position);
	~ItemManager();

	virtual void Render() override;

protected:
	ItemProperties m_items[20];
};

