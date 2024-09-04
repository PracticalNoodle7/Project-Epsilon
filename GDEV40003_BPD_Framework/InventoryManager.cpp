#include "InventoryManager.h"
#include "Texture2D.h"
#include "Constants.h"

//initialise instance to nullptr
InventoryManager* InventoryManager::m_instance = nullptr;

//initialising the slot arrays
int InventorySlot[10][15] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
int EquipmentSlot[3][2] = {
	{0,0},
	{0,0},
	{0,0}
};
string categories[3][2] = {
	{"weapon", "armor"},
	{"shield", "helmet"},
	{"potion", "amulet"}
};

InventoryManager::InventoryManager(SDL_Renderer* renderer)
{
	m_renderer = renderer;
	m_is_inventory_open = false;

	//load new inv texture
	m_texture = new Texture2D(m_renderer);
	if (m_texture != nullptr)
	{
		m_empty_slot = m_texture->LoadFromTileMap("images/Inventory/EmptySlot.png");
		m_Inv_back_panel = m_texture->LoadFromTileMap("images/Inventory/Inventory_back_panel.png");
	}

	LoadInventory(InventorySlot);
	LoadEquip(EquipmentSlot);
}

InventoryManager::~InventoryManager()
{
	m_renderer = nullptr;
	m_instance = nullptr;

	delete m_empty_slot;
	m_empty_slot = nullptr;

	delete m_Inv_back_panel;
	m_Inv_back_panel = nullptr;
}

InventoryManager* InventoryManager::Instance(SDL_Renderer* renderer)
{
	if (!m_instance)
	{
		m_instance = new InventoryManager(renderer);
	}

	return m_instance;
}

void InventoryManager::Render()
{
	srcRect.x = srcRect.y = 0;
	srcRect.w = 1100;
	srcRect.h = 600;
	m_texture->Render(m_Inv_back_panel, srcRect, Vector2D(80, 65), SDL_FLIP_NONE);

	for (int row = 0; row < 10; row++)
	{
		for (int column = 0; column < 15; column++)
		{
			m_position.x = m_inv_slot[row][column].x;
			m_position.y = m_inv_slot[row][column].y;


			switch (m_inv_slot[row][column].type)
			{
			case 0:
				srcRect.x = 0, srcRect.y = 0, srcRect.w = 32, srcRect.h = 32;
				m_texture->Render(m_empty_slot, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				m_texture->Render(m_inv_slot[row][column].imagePath, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			}
		}
	}

	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 2; column++)
		{
			m_position.x = m_equip_slot[row][column].x;
			m_position.y = m_equip_slot[row][column].y;


			switch (m_equip_slot[row][column].type)
			{
			case 0:
				srcRect.x = 0, srcRect.y = 0, srcRect.w = 64, srcRect.h = 64;
				m_texture->Render(m_empty_slot, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				m_texture->Render(m_equip_slot[row][column].imagePath, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
				break;
			}
		}
	}
}

void InventoryManager::LoadInventory(int arr[10][15])
{
	for (int row = 0; row < 10; row++)
	{
		for (int column = 0; column < 15; column++)
		{
			m_inv_slot[row][column].type = arr[row][column];
			m_inv_slot[row][column].x = (column + 13) * 40;
			m_inv_slot[row][column].y = (row + 3) * 40;
			m_inv_slot[row][column].imagePath = m_empty_slot;
			m_inv_slot[row][column].amount = 0;
			m_inv_slot[row][column].is_full = false;
		}
	}
}

void InventoryManager::LoadEquip(int arr[3][2])
{
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 2; column++)
		{
			m_equip_slot[row][column].type = arr[row][column];
			m_equip_slot[row][column].x = (column + 1.5) * 100;
			m_equip_slot[row][column].y = (row + 1.75) * 70;
			m_equip_slot[row][column].category = m_categories[row][column];
			m_equip_slot[row][column].amount = 0;
			m_equip_slot[row][column].is_full = false;
		}
	}
}

void InventoryManager::AddToInventory(string imagePath, int amount)
{
	for (int row = 0; row < 10; row++)
	{
		for (int column = 0; column < 15; column++)
		{
			if (m_inv_slot[row][column].is_full, m_inv_slot[row][column].imagePath = m_texture->LoadFromTileMap(imagePath))
			{
				//TODO: Make function to check if there is enough space in the slot and add it to the slot.
				//If there isnt leave the remainig behind if they can not be added to another slot

				CheckSlotForSpace(imagePath, amount, row, column);
			}
			else
			{
				m_inv_slot[row][column].imagePath = m_texture->LoadFromTileMap(imagePath);

				if (amount <= 20)
				{
					m_inv_slot[row][column].amount = amount;

					if (m_inv_slot[row][column].amount = 20)
					{
						m_inv_slot[row][column].is_full = true;
					}
					
					//TODO: Make a way to delete the physical item
				}
				else
				{
					CheckSlotForSpace(imagePath, amount, row, column);
				}
			}
		}
	}
}

void InventoryManager::CheckSlotForSpace(string imagePath, int amount, int row, int column)
{
	if (m_inv_slot[row][column].amount + amount > 20)
	{
		int m_left_over = m_inv_slot[row][column].amount + amount - 20;
		m_inv_slot[row][column].amount = 20;
		m_inv_slot[row][column].is_full = true;
		
		AddToInventory(imagePath, m_left_over);
	}
	else
	{
		m_inv_slot[row][column].amount += amount; 
		
		//TODO: Make a way to delete the physical item
	}
}

void InventoryManager::Update(float deltaTime, SDL_Event e)
{
	// Variables to hold the mouse position
	int x, y;
	SDL_GetMouseState(&x, &y);

	switch (e.type)
	{
		// Detecting if a keyboard button is down
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
			// click E
		case SDLK_e:
			m_is_inventory_open = !m_is_inventory_open;
			break;
		}
		break;

		// Detecting if the mouse button is down
	case SDL_MOUSEBUTTONDOWN:
		if (e.button.button == SDL_BUTTON_LEFT && m_is_inventory_open)
		{
			// Check for clicks in inventory slots
			for (int row = 0; row < 10; row++)
			{
				for (int column = 0; column < 15; column++)
				{
					int slotX = m_inv_slot[row][column].x;
					int slotY = m_inv_slot[row][column].y;
					int slotWidth = 32;
					int slotHeight = 32;

					if (x >= slotX && x <= slotX + slotWidth &&
						y >= slotY && y <= slotY + slotHeight)
					{
						// Slot at (row, column) is clicked
						HandleSlotClick(row, column);
						break;
					}
				}
			}

			// Check for clicks in equipment slots
			for (int row = 0; row < 3; row++)
			{
				for (int column = 0; column < 2; column++)
				{
					int slotX = m_equip_slot[row][column].x;
					int slotY = m_equip_slot[row][column].y;
					int slotWidth = 64; // Assuming the slot size is 64x64
					int slotHeight = 64;

					if (x >= slotX && x <= slotX + slotWidth &&
						y >= slotY && y <= slotY + slotHeight)
					{
						// Equipment slot at (row, column) is clicked
						HandleEquipSlotClick(row, column);
						break;
					}
				}
			}
		}
		break;
	}
}

void InventoryManager::HandleSlotClick(int row, int column)
{
	if (m_inv_slot[row][column].imagePath != m_empty_slot)
	{
		if (m_inv_slot[row][column].category == "weapon")
		{

		}
		else if (m_inv_slot[row][column].category == "armor")
		{

		}
		else if (m_inv_slot[row][column].category == "shield")
		{

		}
		else if (m_inv_slot[row][column].category == "helmet")
		{

		}
		else if (m_inv_slot[row][column].category == "potion")
		{

		}
		else if (m_inv_slot[row][column].category == "amulet")
		{

		}
	}
}

void InventoryManager::HandleEquipSlotClick(int row, int column)
{
	if (m_equip_slot[row][column].imagePath != m_empty_slot)
	{
		//AddToInventory(m_equip_slot[row][column].imagePath, m_equip_slot[row][column].amount);
	}
}






