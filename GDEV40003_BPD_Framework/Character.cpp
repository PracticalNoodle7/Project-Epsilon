#include "Character.h"
#include "Texture2D.h"
#include "Constants.h"
#include "ItemManager.h"
#include "InventoryManager.h"
#include "GameText.h"

Character::Character(SDL_Renderer* renderer, Vector2D start_position) : GameObject(renderer, start_position), m_stats(0, 0, 100, 128)
{
	//initialising moving variables
	m_attacking = false;
	m_frame_time = 0;
	m_current_frame = 0;

	m_width = 32;
	m_height = 32;

	//load texture
	if (m_texture != nullptr)
	{
		m_character_walk = m_texture->LoadFromTileMap("images/Character/Character_Walk.png");
		m_character_slash = m_texture->LoadFromTileMap("images/Character/Character_Slash.png");
		m_character_rolling = m_texture->LoadFromTileMap("images/Character/Character_Rolling.png");

		m_health_bar = m_texture->LoadFromTileMap("images/Character/HealthBar.png");
		m_health_bar_boarder = m_texture->LoadFromTileMap("images/Character/HealthBar_Boarder.png");
	}

	m_text = new GameText(m_renderer, "fonts/arial.ttf", 12);
	m_interact_text = false;
}

Character::~Character()
{
	delete m_character_walk;
	m_character_walk = nullptr;

	delete m_character_slash;
	m_character_slash = nullptr;

	delete m_character_rolling;
	m_character_rolling = nullptr;

	delete m_health_bar;
	m_health_bar = nullptr;

	delete m_health_bar_boarder;
	m_health_bar_boarder = nullptr;
}

void Character::Render()
{
	srcRect.h = 32;
	srcRect.w = 32;

	if (!m_attacking && !GameObject::m_rolling)
	{
		switch (m_facing_direction)
		{

		case FACING::FACING_RIGHT:
			srcRect.x = (m_current_frame * 32) + 128;
			srcRect.y = 0;
			m_texture->Render(m_character_walk, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;

		case FACING::FACING_LEFT:
			srcRect.x = m_current_frame * 32;
			srcRect.y = 0;
			m_texture->Render(m_character_walk, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;

		case FACING::FACING_DOWN:
			srcRect.x = m_current_frame * 32;
			srcRect.y = 32;
			m_texture->Render(m_character_walk, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;

		case FACING::FACING_UP:
			srcRect.x = (m_current_frame * 32) + 128;
			srcRect.y = 32;
			m_texture->Render(m_character_walk, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;
		}
	}
	else if (m_attacking)
	{
		switch (m_facing_direction)
		{
		case FACING::FACING_RIGHT:
			srcRect.x = (m_current_frame * 32) + 128;
			srcRect.y = 0;
			m_texture->Render(m_character_slash, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;

		case FACING::FACING_LEFT:
			srcRect.x = m_current_frame * 32;
			srcRect.y = 0;
			m_texture->Render(m_character_slash, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;

		case FACING::FACING_DOWN:
			srcRect.x = m_current_frame * 32;
			srcRect.y = 32;
			m_texture->Render(m_character_slash, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;

		case FACING::FACING_UP:
			srcRect.x = (m_current_frame * 32) + 128;
			srcRect.y = 32;
			m_texture->Render(m_character_slash, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;
		}
	}
	else
	{
		switch (m_facing_direction)
		{
		case FACING::FACING_RIGHT:
			srcRect.x = (m_current_frame * 32) + 128;
			srcRect.y = 0;
			m_texture->Render(m_character_rolling, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;

		case FACING::FACING_LEFT:
			srcRect.x = m_current_frame * 32;
			srcRect.y = 0;
			m_texture->Render(m_character_rolling, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;

		case FACING::FACING_DOWN:
			srcRect.x = m_current_frame * 32;
			srcRect.y = 32;
			m_texture->Render(m_character_rolling, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;

		case FACING::FACING_UP:
			srcRect.x = (m_current_frame * 32) + 128;
			srcRect.y = 32;
			m_texture->Render(m_character_rolling, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
			break;
		}
	}

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = 16;
	srcRect.w = 128;

	m_texture->Render(m_health_bar_boarder, SDL_FLIP_NONE, 0.0, srcRect, Vector2D(10, 10));

	srcRect.w = m_stats.m_health.m_health_bar_width;
	m_texture->Render(m_health_bar, SDL_FLIP_NONE, 0.0, srcRect, Vector2D(10, 10));

	if (m_interact_text)
	{
		m_text->SetColor({ 0, 0, 0, 255 });
		m_text->RenderTextAt("Press F", m_position.x, m_position.y - 10);
	}

}

void Character::Update(float deltaTime, SDL_Event e)
{
	m_stats.m_health.HealthBar();

	if (m_stats.m_health.m_current_health <= 0)
	{
		PlayerDead();
	}

	if (GameObject::m_is_moving && !m_attacking && !GameObject::m_rolling)
	{
		if (m_current_animation != WALKING)
		{
			m_current_animation = WALKING;
			m_current_frame = 0;
		}

		FrameUpdate(deltaTime, 0.1);
	}
	else if(m_attacking)
	{
		if (m_current_animation != ATTACKING)
		{
			m_current_animation = ATTACKING;
			m_current_frame = 0;
		}

		FrameUpdate(deltaTime, 0.12);
	}
	else if (m_rolling && !m_attacking)
	{
		if (m_current_animation != ROLLING)
		{
			m_current_animation = ROLLING;
			m_current_frame = 0;
		}

		FrameUpdate(deltaTime, 0.15);
	}
	else
	{
		m_current_frame = 0;
	}

	switch (e.type)
	{
	case SDL_MOUSEBUTTONDOWN:
		switch (e.button.state)
		{
		case SDL_BUTTON_LEFT:
			m_attacking = true; 
			m_can_move = false;
			m_move_left = false;
			m_move_right = false;
			m_move_down = false;
			m_move_up = false;
			break;
		}

	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_SPACE:
			Character::m_rolling = true;
			break;
		}
	}
}

void Character::FrameUpdate(float deltaTime, float delay)
{
	m_frame_time += deltaTime;

	if (m_frame_time >= delay)
	{
		m_frame_time = 0;
		m_current_frame++;

		if (m_current_frame >= m_num_of_frames)
		{
			m_current_frame = 0;

			if (m_attacking)
			{
				m_attacking = false;
				GameObject::m_can_move = true;
			}
			if (m_rolling)
			{
				Character::m_rolling = false;
			}
		}
	}
}

void Character::UpdatePlayerStats(int row, int column, string state)
{
	int itemID = ItemManager::Instance(m_renderer, Vector2D())->GetItemData(InventoryManager::Instance(m_renderer)->m_equip_slot[row][column].imagePath);

	if (state == "Increase")
	{
		if (InventoryManager::Instance(m_renderer)->m_equip_slot[row][column].category == "Weapon")
		{
			m_stats.m_attack_damage += ItemManager::Instance(m_renderer, Vector2D())->m_items[itemID].damage;
		}
		else if (InventoryManager::Instance(m_renderer)->m_equip_slot[row][column].category == "Armor")
		{
			m_stats.m_defence += ItemManager::Instance(m_renderer, Vector2D())->m_items[itemID].defence;
		}
		else if (InventoryManager::Instance(m_renderer)->m_equip_slot[row][column].category == "Shield")
		{
			m_stats.m_defence += ItemManager::Instance(m_renderer, Vector2D())->m_items[itemID].defence;
		}
		else if (InventoryManager::Instance(m_renderer)->m_equip_slot[row][column].category == "Helmet")
		{
			m_stats.m_defence += ItemManager::Instance(m_renderer, Vector2D())->m_items[itemID].defence;
		}
		else if (InventoryManager::Instance(m_renderer)->m_equip_slot[row][column].category == "Potion")
		{
			//TBA
		}
		else if (InventoryManager::Instance(m_renderer)->m_equip_slot[row][column].category == "Amulet")
		{
			//TBA
		}
	}
	else if (state == "Decrease")
	{
		if (InventoryManager::Instance(m_renderer)->m_equip_slot[row][column].category == "Weapon")
		{
			m_stats.m_attack_damage -= ItemManager::Instance(m_renderer, Vector2D())->m_items[itemID].damage;
		}
		else if (InventoryManager::Instance(m_renderer)->m_equip_slot[row][column].category == "Armor")
		{
			m_stats.m_defence -= ItemManager::Instance(m_renderer, Vector2D())->m_items[itemID].defence;
		}
		else if (InventoryManager::Instance(m_renderer)->m_equip_slot[row][column].category == "Shield")
		{
			m_stats.m_defence -= ItemManager::Instance(m_renderer, Vector2D())->m_items[itemID].defence;
		}
		else if (InventoryManager::Instance(m_renderer)->m_equip_slot[row][column].category == "Helmet")
		{
			m_stats.m_defence -= ItemManager::Instance(m_renderer, Vector2D())->m_items[itemID].defence;
		}
		else if (InventoryManager::Instance(m_renderer)->m_equip_slot[row][column].category == "Potion")
		{
			//TBA
		}
		else if (InventoryManager::Instance(m_renderer)->m_equip_slot[row][column].category == "Amulet")
		{
			//TBA
		}
	}
}

void Character::PlayerDead()
{
	//TODO :: Code to respawn player
}
