#pragma once
#include "GameObject.h"

class Character : public GameObject
{
public:
	Character(SDL_Renderer* renderer, Vector2D start_position);
	~Character();

	virtual void Render() override;
	virtual void Update(float deltaTime, SDL_Event e) override;

	//Character textures
	SDL_Texture* m_character_walk;
	SDL_Texture* m_character_slash;

	//Health bar textures
	SDL_Texture* m_health_bar;
	SDL_Texture* m_health_bar_boarder;

protected:
	//Walk animation variables
	float m_frame_time;
	float m_frame_delay;
	int m_current_frame;
	const int m_num_of_frames = 4;

	//Attack animation variables
	float m_attack_frame_time;
	float m_attack_frame_delay;
	int m_attack_current_frame;

	//Attack animation variables
	float m_roll_frame_time;
	float m_roll_frame_delay;
	int m_roll_current_frame;

	//Attacking variables
	bool m_attacking;

	//Health variables
	int maxHealth;
	int currentHealth;
	int fullBarWidth;
	int healthBarWidth;
};