#include "InventoryManager.h"
#include "Texture2D.h"
#include "Constants.h"

//initialise instance to nullptr
InventoryManager* InventoryManager::m_instance = nullptr;

InventoryManager::InventoryManager(SDL_Renderer* renderer)
{
	m_renderer = renderer;
	imagePath = "images/Inventory/EmptySlot.png";
	EmptyImage = "images/Inventory/EmptySlot.png";
	m_is_inventory_open = false;
	m_loaded = false;

	//load base inv texture
	baseImage = new Texture2D(m_renderer);
	if (!baseImage->LoadFromFile(imagePath))
	{
		cout << "Failed to load Inventory slots texture!" << endl;
	}

	//load new inv texture
	itemImage = new Texture2D(m_renderer);
	if (!itemImage->LoadFromFile(imagePath))
	{
		cout << "Failed to load Item slot texture! " << endl;
	}

	//my_items = new ItemManager(m_renderer, "images/1Tiles/Tile_51.png", Vector2D(0, 0));
}

InventoryManager::~InventoryManager()
{
	delete baseImage;
	baseImage = nullptr;

	delete itemImage;
	itemImage = nullptr;

	delete my_items;
	my_items = nullptr;

	m_renderer = nullptr;
	m_instance = nullptr;
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
	if (imagePath != EmptyImage) 
	{
		itemImage = new Texture2D(m_renderer);
		if (!itemImage->LoadFromFile(this->imagePath))
		{
			cout << "Failed to load Item slot texture! " << endl;
		}

		itemImage->Render(m_position, SDL_FLIP_NONE, 0.0);
	}
	else 
	{	
		//if no item render base else render item image
		baseImage->Render(m_position, SDL_FLIP_NONE, 0.0);
	}
}

void InventoryManager::CallInventoryRenderer()
{
	for (InventoryManager* Inv_pannel : my_back_pannel)
	{
		Inv_pannel->Render();
	}

	for (InventoryManager* Inv_slots : my_inv_slots)
	{
		Inv_slots->Render();
	}

	for (InventoryManager* Equip_slots : my_equip_slots)
	{
		Equip_slots->Render();
	}
}

void InventoryManager::LoadInventory()
{
	if (!m_loaded)
	{
		LoadBackPanel();
		LoadInvSlots();
		m_loaded = true;
	}
}

void InventoryManager::LoadBackPanel()
{
	InventoryManager* Inv_pannel = new InventoryManager(m_renderer);
	Inv_pannel->SetPosition(Vector2D(100, 125));
	Inv_pannel->SetImagePath("images/Inventory/InventoryPannel1.png");
	my_back_pannel.push_back(Inv_pannel);
	
	for (int i = 0; i < 25; ++i)
	{
		// Render inventory slots
		InventoryManager* Inv_pannel = new InventoryManager(m_renderer);

		// Set position for each slot
		if (i < 8)
		{
			Inv_pannel->SetPosition(Vector2D(500 + i * 80, 190));
		}
		else if (i < 16)
		{
			Inv_pannel->SetPosition(Vector2D(500 + (i - 8) * 80, 270));
		}
		else if (i < 24)
		{
			Inv_pannel->SetPosition(Vector2D(500 + (i - 16) * 80, 350));
		}
		else if (i < 32)
		{
			Inv_pannel->SetPosition(Vector2D(500 + (i - 24) * 80, 430));
		}
		else
		{
			Inv_pannel->SetPosition(Vector2D(500 + (i - 32) * 80, 510));
		}

		my_back_pannel.push_back(Inv_pannel);
	}

	for (int i = 0; i < 6; ++i)
	{
		InventoryManager* Inv_pannel = new InventoryManager(m_renderer);

		if (i < 2)
		{
			Inv_pannel->SetPosition(Vector2D(175 + i * 200, 190));
		}
		else if (i < 4)
		{
			Inv_pannel->SetPosition(Vector2D(175 + (i - 2) * 200, 270));
		}
		else
		{
			Inv_pannel->SetPosition(Vector2D(175 + (i - 4) * 200, 350));
		}
	 
		my_back_pannel.push_back(Inv_pannel);
	}

}

void InventoryManager::LoadInvSlots()
{
	for (int i = 0; i < 40; ++i)
	{
		// Render inventory slots
		InventoryManager* Inv_slots = new InventoryManager(m_renderer);

		// Set position for each slot
		if (i < 8)
		{
			Inv_slots->SetPosition(Vector2D(500 + i * 80, 190));
		}
		else if (i < 16)
		{
			Inv_slots->SetPosition(Vector2D(500 + (i - 8) * 80, 270));
		}
		else if (i < 24)
		{
			Inv_slots->SetPosition(Vector2D(500 + (i - 16) * 80, 350));
		}
		else if (i < 32)
		{
			Inv_slots->SetPosition(Vector2D(500 + (i - 24) * 80, 430));
		}
		else
		{
			Inv_slots->SetPosition(Vector2D(500 + (i - 32) * 80, 510));
		}
	
		my_inv_slots.push_back(Inv_slots);
	}

	for (int i = 0; i < 6; ++i)
	{
		InventoryManager* Equip_slots = new InventoryManager(m_renderer);

		if (i == 0)
		{
			Equip_slots->SetPosition(Vector2D(175, 190));
			Equip_slots->SetSlotType("armor");
		}
		if (i == 1)
		{
			Equip_slots->SetPosition(Vector2D(375, 190));
			Equip_slots->SetSlotType("weapon");
		}
		if (i == 2)
		{
			Equip_slots->SetPosition(Vector2D(175, 270));
			Equip_slots->SetSlotType("shield");
		}
		if (i == 3)
		{
			Equip_slots->SetPosition(Vector2D(375, 270));
			Equip_slots->SetSlotType("relic");
		}
		if (i == 4)
		{
			Equip_slots->SetPosition(Vector2D(175, 350));
			Equip_slots->SetSlotType("ability");
		}
		if (i == 5)
		{
			Equip_slots->SetPosition(Vector2D(375, 350));
			Equip_slots->SetSlotType("consumable");
		}

		my_equip_slots.push_back(Equip_slots);
	}
}

//void InventoryManager::SetStatsText()
//{
//	m_gameText->SetColor({ 255, 255, 255, 255 });
//
//	m_gameText->RenderTextAt("Damage: ", 200, 400);
//	m_gameText->RenderNumberAt(GetPlayerAttackDamage(), 290, 400);
//
//	m_gameText->RenderTextAt("Defence: ", 200, 425);
//	m_gameText->RenderNumberAt((GetShieldDefence()), 290, 425);
//
//	m_gameText->RenderTextAt("Health: ", 200, 450);
//	//m_gameText->RenderNumberAt(m_character->GetCharacterHealth(), 290, 450);
//}

void InventoryManager::Update(float deltaTime, SDL_Event e)
{
	switch (e.type)
	{
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
		break;
	case SDL_JOYBUTTONDOWN:
		switch (e.jbutton.button)
		{
		case 3:
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
	}
}

void InventoryManager::SetPosition(Vector2D new_position)
{
	m_position = new_position;
}

void InventoryManager::SetSlotType(string SlotType)
{
	m_slot_type = SlotType;
}

bool InventoryManager::AddItemToInventory(string imagePath)
{
	// Check if the item is already in the inventory
	for (InventoryManager* Inv_slots : my_inv_slots)
	{
		//avoid duplicate items
		if (Inv_slots->GetImagePath() == imagePath)
		{
			return true;
		}
	}
	
	// Item not found in inventory, find an empty slot and add it
	for (InventoryManager* Inv_slots : my_inv_slots)
	{
		if (Inv_slots->IsEmpty())
		{
			// Empty slot found, add the item
			Inv_slots->SetImagePath(imagePath);
			return true;
		}
	}

	return false;
}

bool InventoryManager::AddItemToEquipSlot(string imagePath)
{
	// Check if the item is already in the inventory
	for (InventoryManager* Equip_slots : my_equip_slots)
	{
		if (Equip_slots->GetImagePath() == imagePath)
		{
			return true;
		}
	}

	// Item not found in inventory, find an empty slot and add it
	for (InventoryManager* Equip_slots : my_equip_slots)
	{
		if (Equip_slots->IsEmpty() && Equip_slots->GetType() == my_items->GetItemType(imagePath))
		{
			//Empty slot found, add the item
			Equip_slots->SetImagePath(imagePath);

			if (Equip_slots->GetType() == "armor")
			{
				//m_character->IncreaseCharacterHealth();
			}
			return true;
		}
	}
	return false;
}

void InventoryManager::ResetInvSlot(int Slot)
{
	my_inv_slots[Slot]->imagePath = EmptyImage;
}

void InventoryManager::ResetEquipSlot(int Slot)
{
	my_equip_slots[Slot]->imagePath = EmptyImage;
}

int InventoryManager::GetPlayerAttackDamage()
{
	for (InventoryManager* Equip_slots : my_equip_slots)
	{
		if (Equip_slots->GetType() == "weapon")
		{
			return my_items->GetItemDamage(Equip_slots->GetImagePath());

		}
	}
}

int InventoryManager::GetPlayerUpdatedHealth()
{
	for (InventoryManager* Equip_slots : my_equip_slots)
	{
		if (Equip_slots->GetType() == "armor")
		{
			return my_items->GetItemDefence(Equip_slots->GetImagePath());
		}
	}
}

int InventoryManager::GetShieldDefence()
{
	for (InventoryManager* Equip_slots : my_equip_slots)
	{
		if (Equip_slots->GetType() == "shield")
		{
			return my_items->GetItemDefence(Equip_slots->GetImagePath());
		}
	}
} 

int InventoryManager::GetConsumableAmount()
{
	for (InventoryManager* Equip_slots : my_equip_slots)
	{
		if (Equip_slots->GetType() == "consumable")
		{
			return my_items->GetItemConsumable(Equip_slots->GetImagePath());
		}
	}
}