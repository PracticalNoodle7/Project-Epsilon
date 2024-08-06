#include "ItemManager.h"

bool ItemManager::m_setUp = false;

ItemManager::ItemManager(SDL_Renderer* renderer, Vector2D start_position) : GameObject(renderer, start_position)
{
	//itemImagePath = imagePath;		
	
	SettingUpItems();
	if (!m_setUp)
	{
		m_setUp = true;
	}
}

ItemManager::~ItemManager()
{

}

void ItemManager::SettingUpItems()
{
	//adding weapons
	AddItem("images/Items/sword1.png", "weapon", 0, 10, 0, 0);
	AddItem("images/Items/sword2.png", "weapon", 0, 25, 0, 400);
	AddItem("images/Items/sword3.png", "weapon", 0, 40, 0, 750);
	AddItem("images/Items/sword4.png", "weapon", 0, 65, 0, 975);
	AddItem("images/Items/sword5.png", "weapon", 0, 85, 0, 1600);

	//adding armor
	AddItem("images/Items/armor1.png", "armor", 0, 0, 35, 250);
	AddItem("images/Items/armor2.png", "armor", 0, 0, 45, 750);
	AddItem("images/Items/armor3.png", "armor", 0, 0, 80, 1350);
	AddItem("images/Items/armor4.png", "armor", 0, 0, 150, 2500);

	//adding shiled
	AddItem("images/Items/shield1.png", "shield", 0, 0, 10, 250);
	AddItem("images/Items/shield2.png", "shield", 0, 0, 25, 750);
	AddItem("images/Items/shield3.png", "shield", 0, 0, 45, 1350);
	AddItem("images/Items/shield4.png", "shield", 0, 0, 80, 2500);

	//adding potions
	AddItem("images/Items/potion1.png", "consumable", 15, 0, 0, 0);
	AddItem("images/Items/potion2.png", "consumable", 35, 0, 0, 675);
	AddItem("images/Items/potion3.png", "consumable", 55, 0, 0, 1150);
}

void ItemManager::Render()
{
	//draw the GameObject
	//m_texture->Render(m_position, SDL_FLIP_NONE);
}

string ItemManager::GetImagePath(ItemManager* item)
{
	return item->itemImagePath;
}

void ItemManager::AddItem(const string& imagePath, const string& itemType, const int& consumable, const int& damage, const int& defence, const int& price)
{
	ItemProperties properties;
	properties.type = itemType;
	properties.consumable = consumable;
	properties.damage = damage;
	properties.defence = defence; 
	properties.price = price;

	itemDatabase[imagePath] = properties;
}

void ItemManager::LoadLevel1Items()
{

}

void ItemManager::CallLevel1ItemsRenderer()
{
	for (ItemManager* item : my_items)
	{
		item->Render();
	}
}

string ItemManager::GetItemType(const string& imagePath) const
{
	auto it = itemDatabase.find(imagePath);
	if (it != itemDatabase.end())
	{
		//Return the type of item
		return it->second.type; 
	}
	else
	{
		// Return an empty type if the item is not found
		return ""; 
	}
}

int ItemManager::GetItemDamage(const string& imagePath) const
{
	auto it = itemDatabase.find(imagePath);
	if (it != itemDatabase.end())
	{
		//Return the type of item
		return it->second.damage;
	}
	else
	{
		// Return an empty type if the item is not found
		return 0;
	}
}

int ItemManager::GetItemDefence(const string& imagePath) const
{
	auto it = itemDatabase.find(imagePath);
	if (it != itemDatabase.end())
	{
		//Return the type of item
		return it->second.defence;
	}
	else
	{
		// Return an empty type if the item is not found
		return 0;
	}
}

int ItemManager::GetItemPrice(const string& imagePath) const
{
	auto it = itemDatabase.find(imagePath);
	if (it != itemDatabase.end())
	{
		//Return the type of item
		return it->second.price;
	}
	else
	{
		// Return an empty type if the item is not found
		return 0;
	}
}

int ItemManager::GetItemConsumable(const string& imagePath) const
{
	auto it = itemDatabase.find(imagePath);
	if (it != itemDatabase.end())
	{
		//Return the type of item
		return it->second.consumable;
	}
	else
	{
		// Return an empty type if the item is not found
		return 0;
	}
}

void ItemManager::DestroyItem(ItemManager* item)
{
	// Find the item in the list of items
	auto it = find(my_items.begin(), my_items.end(), item);
	if (it != my_items.end())
	{
		// Remove the item from the list of items
		my_items.erase(it);

		// Optionally, you can also delete the item object to free memory
		delete item;
	}
	else
	{
		// Item not found in the list
		cout << "Item not found." << endl;
	}
}



