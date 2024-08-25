#pragma once
#include "GameObject.h"

class BasicEnemy : public GameObject
{
public:
	BasicEnemy(SDL_Renderer* renderer, Vector2D start_position);
	~BasicEnemy();

	virtual void Render() override;
	virtual void Update(float deltaTime, SDL_Event e) override;

	virtual void FrameUpdate(float deltaTime, float delay);

	//Health bar textures
	SDL_Texture* m_health_bar;
	SDL_Texture* m_health_bar_boarder;

protected:
	//animation variables
	float m_frame_time;
	int m_current_frame;
	const int m_num_of_frames = 4;
	ANIMATION_STATES m_current_animation;

	//Attacking variables
	bool m_attacking;

	//Health variables
	int maxHealth;
	int currentHealth;
	int fullBarWidth;
	int healthBarWidth;
};

