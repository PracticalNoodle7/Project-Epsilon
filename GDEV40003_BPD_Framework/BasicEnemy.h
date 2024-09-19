#pragma once
#include "GameObject.h"

class Character;
class Item;

class BasicEnemy : public GameObject
{
public:
	BasicEnemy(SDL_Renderer* renderer, Vector2D start_position);
	~BasicEnemy();

	virtual void Render() override;
	virtual void Update(float deltaTime, SDL_Event e) override;

	virtual void FrameUpdate(float deltaTime, float delay);
	virtual Rect2D GetAttackCollision();

	void Move(Vector2D movement, float deltaTime);
	void Rolling(Vector2D movement, float deltaTime);

	void SetCharacter(Character* character) { m_character = character; }
	void SetItem(Item* item) { m_item = item; }
	void ChasePlayer(Vector2D movment, float deltaTime);
	Vector2D GetPlayerLocation();

	void Dead();

	//Health bar textures
	SDL_Texture* m_health_bar;
	SDL_Texture* m_health_bar_boarder;
	SDL_Texture* m_enemy;

	//Enemy state variables
	bool m_player_found;
	bool m_attacking;

		//Health variables
	Health m_health;

protected:
	//animation variables
	float m_frame_time;
	int m_current_frame;
	int m_num_of_frames;
	ANIMATION_STATES m_current_animation;
	Vector2D Chase;
	float Y;
	float X;

	Character* m_character;
	Item* m_item;

	string m_drop_items[3];
};

