#pragma once
#include <unordered_map>
#include "GameObject.h"


class ItemManager : public GameObject
{
public:
	ItemManager(SDL_Renderer* renderer, Vector2D start_position);
	~ItemManager();

	virtual void Render() override;

	void AddItem(const string& imagePath, const string& itemType, const int& quantity, const int& damage, const int& defence, const int& price);
	string GetItemType(const string& imagePath) const;
	string GetImagePath(ItemManager* item);
	int GetItemDamage(const string& imagePath) const;
	int GetItemDefence(const string& imagePath) const;
	int GetItemPrice(const string& imagePath) const;
	int GetItemConsumable(const string& imagePath) const;
	void LoadLevel1Items();
	void CallLevel1ItemsRenderer();
	void SettingUpItems();
	void DestroyItem(ItemManager* item);

	vector<ItemManager*> my_items;

		// Structure to hold item properties
	struct ItemProperties
	{
		string type;
		int consumable;
		int damage;
		int defence;
		int price;
	};

	// Map to store item properties
	unordered_map<int, string> imagePath;
	unordered_map<string, ItemProperties> itemDatabase;

	string itemImagePath;

private:

protected:
	static bool m_setUp;

};

