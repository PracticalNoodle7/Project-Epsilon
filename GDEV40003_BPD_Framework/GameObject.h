#pragma once
#include "Commons.h"
#include "SDL.h"
#include <iostream>
using namespace std;

//foward declarations
class Texture2D;

class GameObject
{
public:
	GameObject(SDL_Renderer* renderer, string imagePath, Vector2D start_position);
	~GameObject();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	void SetPosition(Vector2D new_position);
	Vector2D GetPosition();
	Vector2D m_position;

protected:
	SDL_Renderer* m_renderer;
	Texture2D* m_texture;

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

