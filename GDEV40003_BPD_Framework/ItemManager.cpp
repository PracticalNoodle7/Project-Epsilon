#include "ItemManager.h"

ItemProperties m_items[20] =
{
	{"images/Items/sword1.png", "weapon", 0, 0, 0, 0},
	{"images/Items/sword1.png", "weapon", 0, 0, 0, 0},
	{"images/Items/sword1.png", "weapon", 0, 0, 0, 0},
	{"images/Items/sword1.png", "weapon", 0, 0, 0, 0},
	{"images/Items/sword1.png", "weapon", 0, 0, 0, 0},
	{"images/Items/sword1.png", "weapon", 0, 0, 0, 0},
	{"images/Items/sword1.png", "weapon", 0, 0, 0, 0},
	{"images/Items/sword1.png", "weapon", 0, 0, 0, 0},
	{"images/Items/sword1.png", "weapon", 0, 0, 0, 0},
	{"images/Items/sword1.png", "weapon", 0, 0, 0, 0},
	{"images/Items/sword1.png", "weapon", 0, 0, 0, 0},
	{"images/Items/sword1.png", "weapon", 0, 0, 0, 0},
	{"images/Items/sword1.png", "weapon", 0, 0, 0, 0},
	{"images/Items/sword1.png", "weapon", 0, 0, 0, 0},
	{"images/Items/sword1.png", "weapon", 0, 0, 0, 0},
	{"images/Items/sword1.png", "weapon", 0, 0, 0, 0},
	{"images/Items/sword1.png", "weapon", 0, 0, 0, 0},
	{"images/Items/sword1.png", "weapon", 0, 0, 0, 0},
	{"images/Items/sword1.png", "weapon", 0, 0, 0, 0},
	{"images/Items/sword1.png", "weapon", 0, 0, 0, 0}
};

ItemManager::ItemManager(SDL_Renderer* renderer, Vector2D start_position) : GameObject(renderer, start_position)
{

}

ItemManager::~ItemManager()
{

}

void ItemManager::Render()
{

}



