#pragma once
#include "GameObject.h"
#include <vector>


class ItemManager : public GameObject
{
public:
	~ItemManager();

	static ItemManager* Instance(SDL_Renderer* renderer, Vector2D start_position);
	int GetItemData(string imagePath);

protected:
	vector<ItemProperties> m_items;

private:
	ItemManager(SDL_Renderer* renderer, Vector2D start_position);
	static ItemManager* m_instance;

	void SetUpItems();
	void AddItem(string imagePath,string caregory, int consumable, int damage, int defence, int price);
};

