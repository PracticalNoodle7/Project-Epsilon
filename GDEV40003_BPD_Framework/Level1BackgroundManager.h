#pragma once
#include "TileMap.h"


struct Tile
{
	int type;
	int x, y;
};

class Level1BackgroundManager : public TileMap
{
public:
	Level1BackgroundManager(SDL_Renderer* renderer);
	~Level1BackgroundManager();

	void LoadTileMap(int arr[30][35]) override;
	void Render() override;

protected:
	SDL_Texture* m_grass;

	Tile m_tile_map[30][35];

};

