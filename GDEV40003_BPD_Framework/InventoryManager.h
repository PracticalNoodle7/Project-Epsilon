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

class InventoryManager
{
public:
	~InventoryManager();
	static InventoryManager* Instance(SDL_Renderer* renderer);

	void Render();
	void Update(float deltaTime, SDL_Event e);

	bool m_is_inventory_open;
private:
	InventoryManager(SDL_Renderer* renderer);
	static InventoryManager* m_instance;

	void LoadInventory(int arr[10][15]);
	void LoadEquip(int arr[3][2]);

	void HandleSlotClick(int row, int column);
	void HandleEquipSlotClick(int row, int column);

	void AddToInventory(string imagePath, int amount);
	void CheckSlotForSpace(string imagePath, int amount, int row, int column);

protected:
	SDL_Renderer* m_renderer;
	Texture2D* m_texture;
	Vector2D m_position;

	//textures
	SDL_Rect srcRect;
	SDL_Texture* m_empty_slot;
	SDL_Texture* m_Inv_back_panel;

	//array
	Slots m_inv_slot[15][25];
	Slots m_equip_slot[3][2];
	string m_categories[3][2];

};

