#include "TileMap.h"


TileMap::TileMap(SDL_Renderer* renderer)
{
	m_renderer = renderer;

	//load texture
	m_texture = new Texture2D(m_renderer);

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 32;
	srcRect.h = 32;
}

TileMap::~TileMap()
{

}

void TileMap::LoadTileMap(int arr[30][35])
{

}

void TileMap::Render()
{

}

void TileMap::Update(float deltaTime, SDL_Event e)
{

}
