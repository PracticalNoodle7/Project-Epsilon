#pragma once
#include "GameObject.h"

class Character : public GameObject
{
public:
	Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position);
	~Character();

	virtual void Render() override;
	virtual void Update(float deltaTime, SDL_Event e) override;

private:
	FACING m_facing_direction;

protected:
	//Movment variable
	bool m_move_left;
	bool m_move_right;
	bool m_can_jump;
	bool m_jumping;
	float m_acceleration;

	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);
	virtual void Jump();
};