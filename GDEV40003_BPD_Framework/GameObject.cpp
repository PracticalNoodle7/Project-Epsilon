#include "GameObject.h"
#include "Texture2D.h"
#include "Character.h"

FACING GameObject::m_facing_direction = FACING::FACING_RIGHT;
bool GameObject::m_is_moving;
bool GameObject::m_can_move;
bool GameObject::m_rolling;

GameObject::GameObject(SDL_Renderer* renderer, Vector2D start_position)
{
	m_renderer = renderer;
	m_position = start_position;
	previousPosition = start_position;

	//load texture
	m_texture = new Texture2D(m_renderer);

	//Initialising Movment variable
	m_can_move = true;
	m_is_moving = false;
	m_move_up = false;
	m_move_left = false;
	m_move_down = false;
	m_move_right = false;
	m_acceleration = 5;

	m_collision_radius = 30;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 32;
	srcRect.h = 32;
}

GameObject::~GameObject()
{
	m_renderer = nullptr;
}

void  GameObject::Render()
{

}

void GameObject::Update(float deltaTime, SDL_Event e)
{
	if (m_can_move)
	{
		if (m_move_up)
		{
			MoveUp(deltaTime);
		}
		if (m_move_left)
		{
			MoveLeft(deltaTime);
		}
		if (m_move_down)
		{
			MoveDown(deltaTime);
		}
		if (m_move_right)
		{
			MoveRight(deltaTime);
		}
	}

	//handle the events
	switch (e.type)
	{
	case SDL_KEYDOWN:

		switch (e.key.keysym.sym)
		{
			//Press W to move up
		case SDLK_w:
			m_move_up = true;
			m_is_moving = true;
			break;

			//Press A to move left
		case SDLK_a:
			m_move_left = true;
			m_is_moving = true;
			break;

			//Press S to move down
		case SDLK_s:
			m_move_down = true;
			m_is_moving = true;
			break;

			//Press D to move right
		case SDLK_d:
			m_move_right = true;
			m_is_moving = true;
			break;
		}

	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
			//Check if w is up
		case SDLK_w:
			m_move_up = false;
			m_is_moving = false;
			break;

			//Check if a is up
		case SDLK_a:
			m_move_left = false;
			m_is_moving = false;
			break;

			//Check if s is up
		case SDLK_s:
			m_move_down = false;
			m_is_moving = false;
			break;

			//Check if d is up
		case SDLK_d:
			m_move_right = false;
			m_is_moving = false;
			break;
		}
	}
}

void GameObject::SetPosition(Vector2D new_position)
{
	m_position = new_position;
}

void GameObject::MoveUp(float deltaTime)
{
	if (m_move_up)
	{
		m_facing_direction = FACING::FACING_UP;
		m_position.y += deltaTime * 100;
	}
}

void GameObject::MoveLeft(float deltaTime)
{
	if (m_move_left)
	{
		m_facing_direction = FACING::FACING_LEFT;
		m_position.x += deltaTime * 100;
	}
}

void GameObject::MoveDown(float deltaTime)
{
	if (m_move_down)
	{
		m_facing_direction = FACING::FACING_DOWN;
		m_position.y -= deltaTime * 100;
	}
}

void GameObject::MoveRight(float deltaTime)
{
	if (m_move_right)
	{
		m_facing_direction = FACING::FACING_RIGHT;
		m_position.x -= deltaTime * 100;
	}
}

Vector2D GameObject::GetPosition()
{
	return m_position;
}

float GameObject::GetCollisionRadius()
{
	return m_collision_radius;
}






