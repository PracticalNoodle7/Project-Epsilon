#include "ItemManager.h"

//initialise instance to nullptr
ItemManager* ItemManager::m_instance = nullptr;

ItemManager::ItemManager(SDL_Renderer* renderer, Vector2D start_position) : GameObject(renderer, start_position)
{
	SetUpItems();
}

ItemManager::~ItemManager()
{

}

ItemManager* ItemManager::Instance(SDL_Renderer* renderer, Vector2D start_position)
{
	if (!m_instance)
	{
		m_instance = new ItemManager(renderer, start_position);
	}

	return m_instance;
}

void ItemManager::SetUpItems()
{
	//weapons
	AddItem("images/Items/tile_0103.png", "Weapon", 0, 10, 0, 0);
	AddItem("images/Items/tile_0104.png", "Weapon", 0, 15, 0, 0);
	AddItem("images/Items/tile_0105.png", "Weapon", 0, 25, 0, 0);
	AddItem("images/Items/tile_0106.png", "Weapon", 0, 35, 0, 0);

	//shields
	AddItem("images/Items/tile_0102.png", "Shield", 0, 0, 10, 0);

	//armor
	AddItem("images/Items/tile_0123.png", "Armor", 0, 0, 15, 0);
	AddItem("images/Items/tile_0124.png", "Armor", 0, 0, 25, 0);
}

void ItemManager::AddItem(string imagePath, string caregory, int consumable, int damage, int defence, int price)
{
	ItemProperties new_item;
	new_item.Id = m_items.size();
	new_item.imagePath = imagePath;
	new_item.category = caregory;
	new_item.consumable = consumable;
	new_item.damage = damage;
	new_item.defence = defence;
	new_item.price = price;

	m_items.push_back(new_item);
}

int ItemManager::GetItemData(string imagePath)
{
	for (ItemProperties m_item : m_items)
	{
		if (m_item.imagePath == imagePath)
		{
			return m_item.Id;
		}
	}
}




