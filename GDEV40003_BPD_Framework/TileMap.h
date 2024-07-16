#pragma once
#include "Commons.h"
#include "SDL.h"
#include "Texture2D.h"
#include <iostream>
using namespace std;

//foward declarations
class Texture2D;

class TileMap
{
public:
	TileMap(SDL_Renderer* renderer);
	~TileMap();

	virtual void LoadTileMap(int arr[30][35]);
	virtual void Render();
	void Update(float deltaTime, SDL_Event e);

	//void Update(float deltaTime, SDL_Event e);
	//void SetPosition(Vector2D new_position);
	//Vector2D GetPosition();
	Vector2D m_position;

protected:
	SDL_Renderer* m_renderer;
	Texture2D* m_texture;
	SDL_Rect srcRect;
};

