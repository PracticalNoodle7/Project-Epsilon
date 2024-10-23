#include "GameObject.h"
#include "Texture2D.h"
#include "Character.h"
#include "BackgroundManager.h"

FACING GameObject::m_facing_direction = FACING::FACING_RIGHT;
bool GameObject::m_is_moving = false;
bool GameObject::m_rolling;
bool GameObject::m_move_up = false;
bool GameObject::m_move_left = false;
bool GameObject::m_move_down = false;
bool GameObject::m_move_right = false;

GameObject::GameObject(SDL_Renderer* renderer, Vector2D start_position)
{
	m_renderer = renderer;
	m_position = start_position;
	previousPosition = start_position;
	m_width = 32;
	m_height = 32;

	m_can_move = true;

	//load texture
	m_texture = new Texture2D(m_renderer);

	//Initialising Movment variable
	movement.x = movement.y = 0;

	m_collision_radius_chase = 100;
	m_collision_radius_attack = 10;
	m_collision_radius_attack = 0;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 32;
	srcRect.h = 32;
}

GameObject::~GameObject()
{
	m_renderer = nullptr;
}

void GameObject::MoveGameObject(float deltaTime, SDL_Event e)
{
	previousPosition = m_position;
	movement.x = movement.y = 0;

	if (m_can_move && !m_rolling)
	{
		// Calculate movement vector
		if (m_move_up)
		{
			movement.y += 1;
		}
		if (m_move_left)
		{
			movement.x += 1;
		}
		if (m_move_down)
		{
			movement.y -= 1;
		}
		if (m_move_right)
		{
			movement.x -= 1;
		}

	}

	if (m_rolling)
	{
		Rolling(movement, deltaTime);
	}

	// Normalize the movement vector to prevent faster diagonal movement
	if (movement.x != 0 || movement.y != 0)
	{
		movement = movement.Normalize();
		m_is_moving = true;

		// Apply movement
		if (!m_rolling)
		{
			Move(movement, deltaTime);
		}
	}

	m_collision_radius_basic = srcRect.w / 2;
}

void GameObject::MoveBack(Character* m_character, int X, int Y, TileType tile, float deltaTime)
{
	Vector2D Difference;

	Difference.x = X - m_character->m_position.x;
	Difference.y = Y - m_character->m_position.y;

	switch (tile)
	{
	case LEFT:
		if (Difference.x < 0)
		{
			movement.x -= 2;
		}
		else
		{
			movement.x += 2;
		}
		break;

	case RIGHT:
		if (Difference.x < -5)
		{
			movement.x -= 2;
		}
		else
		{
			movement.x += 2;
		}
		break;

	case TOP:
		if (Difference.y < 0)
		{
			movement.y -= 2;
		}
		else
		{
			movement.y += 2;
		}
		break;

	case BOTTOM:
		if (Difference.y < 0)
		{
			movement.y -= 2;
		}
		else
		{
			movement.y += 2;
		}

		if (Difference.x < 0)
		{
			movement.x -= 2;
		}
		else
		{
			movement.x += 2;
		}
		break;
	}

	// Normalize the movement vector to prevent faster diagonal movement
	if (movement.x != 0 || movement.y != 0)
	{
		movement = movement.Normalize();

		// Apply movement to the GameObjects
		m_position.x += movement.x * deltaTime * 200;
		m_position.y += movement.y * deltaTime * 200;
	}
}

void GameObject::MoveBack(Character* m_character, GameObject* Obj, BackgroundManager* m_background, float deltaTime)
{
	Vector2D Difference;
	TileType Direction_for_background;

	Difference.x = Obj->m_position.x - m_character->m_position.x;
	Difference.y = Obj->m_position.y - m_character->m_position.y;

	//Player is above the object
	if (Difference.y > 0)
	{
		movement.y += 2;
		Direction_for_background = BOTTOM;
	}
	//Player is next to the object
	else if (Difference.y < 0 && m_character->m_position.y < Obj->m_position.y + 92)
	{

		//Player is left of the object
		if (Difference.x > 0)
		{
			movement.x += 2;
			Direction_for_background = RIGHT;
		}
		//Player is right of the object
		else
		{
			movement.x -= 2;
			Direction_for_background = LEFT;
		}
	}
	//Player is under the object
	else
	{
		movement.y -= 2;
		Direction_for_background = TOP;
	}

	// Normalize the movement vector to prevent faster diagonal movement
	if (movement.x != 0 || movement.y != 0)
	{
		movement = movement.Normalize();

		// Apply movement to the GameObjects
		m_position.x += movement.x * deltaTime * 200;
		m_position.y += movement.y * deltaTime * 200;
	}

	m_background->PreventOutOfBounds(Direction_for_background, deltaTime);
}

void GameObject::Move(Vector2D movement, float deltaTime)
{
	// Apply movement to the GameObjects
	m_position.x += movement.x * deltaTime * 200;
	m_position.y += movement.y * deltaTime * 200;
}

void GameObject::Rolling(Vector2D movement, float deltaTime)
{
	switch (m_facing_direction)
	{
	case FACING::FACING_RIGHT:
		movement.x -= 1.5;
		movement.y = 0;
		break;

	case FACING::FACING_LEFT:
		movement.x += 1.5;
		movement.y = 0;
		break;

	case FACING::FACING_DOWN:
		movement.y -= 1.5;
		movement.x = 0;
		break;

	case FACING::FACING_UP:
		movement.y += 1.5;
		movement.x = 0;
		break;
	}

	m_position.x += movement.x * deltaTime * 200;
	m_position.y += movement.y * deltaTime * 200;
}

void GameObject::SetPosition(Vector2D new_position)
{
	m_position = new_position;
}

Vector2D GameObject::GetPosition()
{
	return m_position;
}

Rect2D GameObject::GetCollisionBox(float offset_x, float offset_y)
{
	return Rect2D(m_position.x + offset_x, m_position.y + offset_y, m_width, m_height);
}

Rect2D GameObject::GetAttackCollision()
{
	switch (m_facing_direction)
	{
	case FACING::FACING_RIGHT:
		return Rect2D(m_position.x + 5, m_position.y, 16, 16);
		break;

	case FACING::FACING_LEFT:
		return Rect2D(m_position.x - 18, m_position.y, 16, 16);
		break;

	case FACING::FACING_DOWN:
		return Rect2D(m_position.x, m_position.y + 5, 16, 16);
		break;

	case FACING::FACING_UP:
		return Rect2D(m_position.x, m_position.y - 18, 16, 16);
		break;
	}
}

float GameObject::GetCollisionRadius(Collision_Type Type)
{
	if (Type == CHASE)
	{
		return m_collision_radius_chase;
	}
	else if (Type == ATTACK)
	{
		return m_collision_radius_attack;
	}
	else if (Type == BASIC)
	{
		return  m_collision_radius_basic;
	}
}