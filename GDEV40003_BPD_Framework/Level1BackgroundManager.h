#pragma once
#include "GameObject.h"

class Level1BackgroundManager : public GameObject
{
public:
	Level1BackgroundManager(SDL_Renderer* renderer, Vector2D start_position);
	~Level1BackgroundManager();

	void LoadTileMap(int arr[30][35]);
	void Render() override;
	void Update(float deltaTime, SDL_Event e);

protected:
	SDL_Texture* m_grass;
	Tile m_tile_map[30][35];

	//Movment Functions
	void Move(Vector2D movement, float deltaTime);
	void Rolling(Vector2D movement, float deltaTime);

	float m_movment_speed;

};

