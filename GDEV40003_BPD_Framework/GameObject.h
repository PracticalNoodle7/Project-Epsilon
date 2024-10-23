#pragma once
#include "Commons.h"
#include "SDL.h"
#include "Texture2D.h"
#include <iostream>
using namespace std;

//foward declarations
class Texture2D;
class BackgroundManager;
class Character;

class GameObject
{
public:
	GameObject(SDL_Renderer* renderer, Vector2D start_position);
	~GameObject();

	virtual void Render() {};
	virtual void Update(float deltaTime, SDL_Event e) {};

	void SetPosition(Vector2D new_position);
	Vector2D GetPosition();

	void MoveGameObject(float deltaTime, SDL_Event e);
	void ChangeFacingDirection(FACING new_Direction) { GameObject::m_facing_direction = new_Direction; };
	void ChangeMovingBool(bool new_state) { GameObject::m_is_moving = new_state; };

	void MoveBack(Character* m_character, int X, int Y, TileType tile, float deltaTime);
	virtual void MoveBack(Character* m_character, GameObject* Obj, BackgroundManager* m_background, float deltaTime);

	float m_width;
	float m_height;

	Rect2D GetCollisionBox() { return Rect2D(m_position.x, m_position.y, m_width, m_height); }
	Rect2D GetCollisionBox(float offset_x, float offset_y);
	virtual Rect2D GetAttackCollision();
	float GetCollisionRadius(Collision_Type Type);

	Vector2D m_position;
	Vector2D previousPosition;

	bool m_can_move;

protected:
	SDL_Renderer* m_renderer;
	Texture2D* m_texture;
	SDL_Rect srcRect;

	static FACING m_facing_direction;

	//Movment variable
	static bool m_is_moving;
	static bool m_rolling;
	static bool m_move_up;
	static bool m_move_left;
	static bool m_move_down;
	static bool m_move_right;
	float m_collision_radius_chase;
	float m_collision_radius_attack;
	float m_collision_radius_basic;

	Vector2D movement;

	virtual void Move(Vector2D movement, float deltaTime);
	virtual void Rolling(Vector2D movement, float deltaTime);
};

