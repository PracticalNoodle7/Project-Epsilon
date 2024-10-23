#include "Teleporter.h"
#include "Texture2D.h"
#include "Constants.h"


Teleporter::Teleporter(SDL_Renderer* renderer, Vector2D start_position) : GameObject(renderer, start_position)
{
	if (m_texture != nullptr)
	{
		m_teleporter = m_texture->LoadFromTileMap("images/Overworld_Tile/TX Props.png");
	}
}

Teleporter::~Teleporter()
{
	m_teleporter = nullptr;
	delete m_teleporter;
}

void Teleporter::Render()
{
	srcRect.x = 352;
	srcRect.y = 256;
	srcRect.w = 96;
	srcRect.h = 96;

	m_texture->Render(m_teleporter, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);
}