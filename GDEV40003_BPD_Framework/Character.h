#pragma once
#include "GameObject.h"

class Character : public GameObject
{
public:
	Character(SDL_Renderer* renderer, Vector2D start_position);
	~Character();

	virtual void Render() override;
	virtual void Update(float deltaTime, SDL_Event e) override;

	virtual void FrameUpdate(float deltaTime, float delay);

	//Character textures
	SDL_Texture* m_character_walk;
	SDL_Texture* m_character_slash;
	SDL_Texture* m_character_rolling;

	//Health bar textures
	SDL_Texture* m_health_bar;
	SDL_Texture* m_health_bar_boarder;

protected:
	//animation variables
	float m_frame_time;
	int m_current_frame;
	const int m_num_of_frames = 4;

	//Attacking variables
	bool m_attacking;
	static bool m_rolling;

	//Health variables
	int maxHealth;
	int currentHealth;
	int fullBarWidth;
	int healthBarWidth;
};