#include "GameObject.h"
#include "Texture2D.h"

GameObject::GameObject(SDL_Renderer* renderer, string imagePath, Vector2D start_position)
{
	m_renderer = renderer;
	m_position = start_position;

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

}

void GameObject::SetPosition(Vector2D new_position)
{
	m_position = new_position;
}

Vector2D GameObject::GetPosition()
{
	return m_position;
}








