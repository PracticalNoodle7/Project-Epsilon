#include "GameObject.h"
#include "Texture2D.h"

GameObject::GameObject(SDL_Renderer* renderer, string imagePath, Vector2D start_position)
{
	m_renderer = renderer;
	m_position = start_position;
	m_is_moving = true;

	m_move_left = false;
	m_move_right = false;
	m_can_jump = false;
	m_jumping = false;
	m_acceleration = 5;

	//load texture
	m_texture = new Texture2D(m_renderer);
	if (!m_texture->LoadFromFile(imagePath))
	{
		cout << "Failed to load GameObject texture!" << endl;
	}
}

GameObject::~GameObject()
{
	m_renderer = nullptr;
}

void  GameObject::Render()
{
	//draw the GameObject
	m_texture->Render(m_position, SDL_FLIP_NONE);
}

void GameObject::Update(float deltaTime, SDL_Event e)
{
	if (m_is_moving)
	{
		if (m_move_left)
		{
			MoveLeft(deltaTime);
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
				//Press A to move left
			case SDLK_a:
				m_move_left = true;
				break;

				//Press D to move right
			case SDLK_d:
				m_move_right = true;
				break;

				//press space to jump
			case SDLK_SPACE:
				Jump();
				break;
			}
			break;

		case SDL_KEYUP:
			switch (e.key.keysym.sym)
			{
				//Check if a is up
			case SDLK_a:
				m_move_left = false;
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

void GameObject::MoveLeft(float deltaTime)
{
	if (m_move_left)
	{
		m_position.x += deltaTime * 100;
	}
}

void GameObject::MoveRight(float deltaTime)
{
	if (m_move_right)
	{
		m_position.x -= deltaTime * 100;
	}
}

void GameObject::Jump()
{

}


Vector2D GameObject::GetPosition()
{
	return m_position;
}








