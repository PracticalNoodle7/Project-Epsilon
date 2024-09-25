#pragma once
#include <string>
#include "SDL.h"
#include "SDL_image.h"
using namespace std;

struct Vector2D
{
	float x;
	float y;
	
	Vector2D()
	{
		x = 0.0f;
		y = 0.0f;
	}

	Vector2D(float initial_x, float initial_y)
	{
		x = initial_x;
		y = initial_y;
	}


	// Method to compute the magnitude (length) of the vector
	float Magnitude() const
	{
		return sqrt(x * x + y * y);
	}

	// Method to normalize the vector (make it unit length)
	Vector2D Normalize() const
	{
		float magnitude = Magnitude();
		if (magnitude > 0)
		{
			return Vector2D(x / magnitude, y / magnitude);
		}
		return Vector2D(0, 0);  // Return zero vector if magnitude is zero
	}
};

struct Health
{

	float m_max_health;
	float m_current_health;
	float m_full_bar_width;
	float m_health_bar_width;

	bool m_is_dead = false;
	bool m_damaged = false;

	Health(float initial_max_health, float initial_bar_width)
	{
		m_max_health = initial_max_health;
		m_full_bar_width = initial_bar_width;
		m_current_health = m_max_health;
		m_health_bar_width = m_full_bar_width;
	}

	void HealthBar()
	{
		// Calculate the width of the health bar portion to display
		m_health_bar_width = (m_current_health * m_full_bar_width) / m_max_health;
	}

	void TakeDamage(float m_damage)
	{
		if (!m_damaged)
		{
			m_current_health -= m_damage;
			m_damaged = true;
		}

		if (m_current_health <= 0)
		{
			m_is_dead = true;
		}
	}
};

struct Damage
{
	float m_base_damage;

	Damage(float initial_damage)
	{
		m_base_damage = initial_damage;
	}

	float GetDamage()
	{
		return m_base_damage;
	}
};

enum Layer
{
	BACKGROUND,
	WALLS,
};

enum SCREENS
{
	SCREEN_MENU,
	SCREEN_THE_RIFT,
	SCREEN_LEVEL1,
	SCREEN_LEVEL2,
	SCREEN_GAMEOVER,
	SCREEN_HIGHSCORS
};

struct Menu
{
	int type;
	SDL_Texture* imageTexture;
	string imagePath;
	float x, y;
};

enum FACING
{
	FACING_LEFT,
	FACING_RIGHT,
	FACING_UP,
	FACING_DOWN
};

enum ROTATION
{
	ZERO,
	NINETY,
	ONE_EIGHTY,
	TWO_SEVENTY
};

enum ANIMATION_STATES
{
	WALKING,
	ATTACKING,
	ROLLING,
	IDLE
};

enum Collision_Type
{
	CHASE,
	ATTACK
};

struct Rect2D
{
	float x;
	float y;
	float width;
	float height;

	Rect2D(float x_pos, float y_pos, float width, float height)
	{
		x = x_pos;
		y = y_pos;
		this->width = width;
		this->height = height;
	}
};

struct Camera
{
	float x, y;
	float width, height;
};
	
struct Tile
{
	int type;
	float x, y;
};

struct Slots
{
	int type;
	SDL_Texture* imageTexture;
	string imagePath;
	float x, y;
	int amount;
	bool is_full;
	string category;
};

struct DroppedItems
{
	SDL_Texture* imageTexture;
	string imagePath;
	Vector2D m_position;
	int quantity;
};

struct ItemProperties
{
	int Id;
	string imagePath;
	string category;
	int consumable;
	int damage;
	int defence;
	int price;
};



