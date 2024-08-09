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
	m_texture->Render(m_Inv_back_panel, srcRect, Vector2D(80, 65));

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
				m_texture->Render(m_empty_slot, srcRect, Vector2D(m_position.x, m_position.y));
				m_texture->Render(m_empty_slot, srcRect, Vector2D(m_position.x, m_position.y));
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
				m_texture->Render(m_empty_slot, srcRect, Vector2D(m_position.x, m_position.y));
				m_texture->Render(m_empty_slot, srcRect, Vector2D(m_position.x, m_position.y));
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
		}
	}
}

void InventoryManager::Update(float deltaTime, SDL_Event e)
{
	switch (e.type)
	{
		//Detecting if a keyboard button is down
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
			//click E
		case SDLK_e:
			if (m_is_inventory_open)
			{
				m_is_inventory_open = false;
			}
			else
			{
				m_is_inventory_open = true;
			}
			break;
		}

		//Detecting if the mouse button is down
	case SDL_MOUSEBUTTONDOWN:
		switch (e.button.state)
		{
		case SDL_BUTTON_LEFT:
			if (m_is_inventory_open)
			{
				cout << "Left button pressed" << endl;
			}
			break;
		}

	}
	// Variables to hold the mouse position
	int x, y;
	SDL_GetMouseState(&x, &y);
}
