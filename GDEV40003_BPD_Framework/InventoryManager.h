#pragma once
#include "Commons.h"
#include "SDL.h"
#include "Texture2D.h"
#include "Character.h"
#include "ItemManager.h"
#include <iostream>
#include <vector>

//foward declarations
class Texture2D;
class ItemManager;
class Character;

class InventoryManager
{
public:
	~InventoryManager();

	static InventoryManager* Instance(SDL_Renderer* renderer);

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	void SetPosition(Vector2D new_position);
	void SetSlotType(string SlotType);

	void LoadInvSlots();
	void LoadBackPanel();
	void LoadInventory();
	void CallInventoryRenderer();
	//void SetStatsText();
	bool AddItemToInventory(string imagePath);
	bool AddItemToEquipSlot(string imagePath);
	void ResetInvSlot(int Slot);
	void ResetEquipSlot(int Slot);

	string GetImagePath() { return imagePath; }
	string GetType() const { return m_slot_type; }
	void SetImagePath(string imagePath) { this->imagePath = imagePath; }
	bool IsEmpty() { return imagePath == EmptyImage; }
	int GetPlayerAttackDamage();
	int GetShieldDefence();
	int GetConsumableAmount();
	int GetPlayerUpdatedHealth();
	Rect2D GetCollisionBox() { return Rect2D(m_position.x, m_position.y, baseImage->GetWidth(), baseImage->GetHeight()); }
	//void SetTextPointer(GameText* m_gameText) { this->m_gameText = m_gameText; }
	void SetCharacterPointer(Character* m_character) { this->m_character = m_character; }
	
	vector<InventoryManager*> my_inv_slots;
	vector<InventoryManager*> my_equip_slots;

	bool m_is_inventory_open;
	bool m_loaded;
private:
	InventoryManager(SDL_Renderer* renderer);
	static InventoryManager* m_instance;

	string imagePath;
	string EmptyImage;

protected:
	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Vector2D m_previouse_position;
	string m_slot_type;

	Texture2D* baseImage;
	Texture2D* itemImage;


	vector<InventoryManager*> my_back_pannel;
	ItemManager* my_items;
	//GameText* m_gameText;
	Character* m_character;
};

