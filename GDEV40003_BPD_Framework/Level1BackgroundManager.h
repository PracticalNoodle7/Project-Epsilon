#pragma once
#include "GameObject.h"

class Level1BackgroundManager : public GameObject
{
public:
	Level1BackgroundManager(SDL_Renderer* renderer, Vector2D start_position);
	~Level1BackgroundManager();

	void LoadTileMap(int arr[30][35]);
	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

protected:
	SDL_Texture* m_grass;
	Tile m_tile_map[30][35];

	//Movment variable
	bool m_is_moving;
	bool m_move_up;
	bool m_move_left;
	bool m_move_down;
	bool m_move_right;
	float m_acceleration;

	//Movment Functions
	virtual void MoveUp(float deltaTime);
	virtual void MoveLeft(float deltaTime);
	virtual void MoveDown(float deltaTime);
	virtual void MoveRight(float deltaTime);

};

