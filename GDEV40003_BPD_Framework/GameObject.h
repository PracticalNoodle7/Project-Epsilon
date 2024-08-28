#pragma once
#include "Commons.h"
#include "SDL.h"
#include "Texture2D.h"
#include <iostream>
using namespace std;

//foward declarations
class Texture2D;

class GameObject
{
public:
	GameObject(SDL_Renderer* renderer, Vector2D start_position);
	~GameObject();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	void SetPosition(Vector2D new_position);
	Vector2D GetPosition();
	void ChangeFacingDirection(FACING new_Direction) { GameObject::m_facing_direction = new_Direction; };
	void ChangeMovingBool(bool new_state) { GameObject::m_is_moving = new_state; };

	Rect2D GetCollisionBox() { return Rect2D(m_position.x, m_position.y, m_texture->GetWidth(), m_texture->GetHeight()); }
	float GetCollisionRadius(Collision_Type Type);

	Vector2D m_position;
	Vector2D previousPosition;

protected:
	SDL_Renderer* m_renderer;
	Texture2D* m_texture;
	SDL_Rect srcRect;

	static FACING m_facing_direction;

	//Movment variable
	static bool m_can_move;
	static bool m_is_moving;
	static bool m_rolling;
	bool m_move_up;
	bool m_move_left;
	bool m_move_down;
	bool m_move_right;
	float m_acceleration;
	float m_collision_radius_chase;
	float m_collision_radius_attack;

	//Movment Functions
	virtual void MoveUp(float deltaTime);
	virtual void MoveLeft(float deltaTime);
	virtual void MoveDown(float deltaTime);
	virtual void MoveRight(float deltaTime);
};

