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
	SDL_Renderer* m_renderer;

	SDL_Rect src, dest;

	Texture2D* dirt;
	Texture2D* grass;
	SDL_Texture* water;

	int m_tile_map[20][25];
};

