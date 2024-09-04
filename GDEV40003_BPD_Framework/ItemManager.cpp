#include "ItemManager.h"

//initialise instance to nullptr
ItemManager* ItemManager::m_instance = nullptr;

ItemManager::ItemManager(SDL_Renderer* renderer, Vector2D start_position) : GameObject(renderer, start_position)
{

}

ItemManager::~ItemManager()
{

}

ItemManager* ItemManager::Instance(SDL_Renderer* renderer, Vector2D start_position)
{
	if (!m_instance)
	{
		m_instance = new ItemManager(renderer, start_position);
		ItemManager* SetUpItems();
	}

	return m_instance;
}

void ItemManager::SetUpItems()
{
	AddItem("1", "", 0, 10, 0, 0);
	AddItem("2", "", 0, 10, 0, 0);
	AddItem("3", "", 0, 10, 0, 0);
	AddItem("4", "", 0, 10, 0, 0);
	AddItem("5", "", 0, 10, 0, 0);
	AddItem("6", "", 0, 10, 0, 0);
	AddItem("7", "", 0, 10, 0, 0);
	AddItem("8", "", 0, 10, 0, 0);
	AddItem("9", "", 0, 10, 0, 0);
	AddItem("0", "", 0, 10, 0, 0);
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




