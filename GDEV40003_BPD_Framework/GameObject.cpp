#include "GameObject.h"
#include "Texture2D.h"

GameObject::GameObject(SDL_Renderer* renderer, Vector2D start_position)
{
	m_facing_direction = FACING_LEFT;

	m_renderer = renderer;
	m_position = start_position;

	//load texture
	m_texture = new Texture2D(m_renderer);

	//Initialising Movment variable
	m_is_moving = true;
	m_move_up = false;
	m_move_left = false;
	m_move_down = false;
	m_move_right = false;
	m_acceleration = 5;

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
	//draw the GameObject
	m_texture->Render(m_position, SDL_FLIP_NONE, 0.0);
}

void GameObject::Update(float deltaTime, SDL_Event e)
{
	if (m_is_moving)
	{
		if (m_move_up)
		{
			MoveUp(deltaTime);
		}
		else if (m_move_left)
		{
			MoveLeft(deltaTime);
		}
		else if (m_move_down)
		{
			MoveDown(deltaTime);
		}
		else if (m_move_right)
		{
			MoveRight(deltaTime);
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
				break;

				//Press A to move left
			case SDLK_a:
				m_move_left = true;
				break;

				//Press S to move down
			case SDLK_s:
				m_move_down = true;
				break;

				//Press D to move right
			case SDLK_d:
				m_move_right = true;
				break;
			}
			break;
		case SDL_KEYUP:
			switch (e.key.keysym.sym)
			{
				//Check if w is up
			case SDLK_w:
				m_move_up = false;
				break;

				//Check if a is up
			case SDLK_a:
				m_move_left = false;
				break;

				//Check if s is up
			case SDLK_s:
				m_move_down = false;
				break;

				//Check if d is up
			case SDLK_d:
				m_move_right = false;
				break;
			}
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
		m_facing_direction = FACING_UP;
		m_position.y += deltaTime * 100;
	}
}

void GameObject::MoveLeft(float deltaTime)
{
	if (m_move_left)
	{
		m_facing_direction = FACING_LEFT;
		m_position.x += deltaTime * 100;
	}
}

void GameObject::MoveDown(float deltaTime)
{
	if (m_move_down)
	{
		m_facing_direction = FACING_DOWN;
		m_position.y -= deltaTime * 100;
	}
}

void GameObject::MoveRight(float deltaTime)
{
	if (m_move_right)
	{
		m_facing_direction = FACING_RIGHT;
		m_position.x -= deltaTime * 100;
	}
}

Vector2D GameObject::GetPosition()
{
	return m_position;
}








