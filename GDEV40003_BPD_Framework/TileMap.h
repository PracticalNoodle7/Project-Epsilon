#pragma once
#include "Commons.h"
#include "SDL.h"
#include <iostream>
using namespace std;

//foward declarations
class Texture2D;

class TileMap
{
public:
	TileMap(SDL_Renderer* renderer);
	~TileMap();

	void LoadTileMap(int arr[20][25]);
	void Renderer();

private:
	Vector2D m_position;

	SDL_Texture* dirt;
	SDL_Texture* dirt_edge;
	SDL_Texture* water;

	int m_tile_map[20][25];

protected:
	SDL_Renderer* m_renderer;
	Texture2D* m_texture;
};

