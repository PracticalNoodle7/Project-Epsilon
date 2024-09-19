#pragma once
#include "GameObject.h"
#include <vector>


class ItemManager : public GameObject
{
public:
	~ItemManager();

	static ItemManager* Instance(SDL_Renderer* renderer, Vector2D start_position);
	int GetItemData(string imagePath);	
	void SetUpItems();
	
	vector<ItemProperties> m_items;

protected:
	

private:
	ItemManager(SDL_Renderer* renderer, Vector2D start_position);
	static ItemManager* m_instance;


	void AddItem(string imagePath,string caregory, int consumable, int damage, int defence, int price);
};

