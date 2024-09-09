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

struct Velocity2D
{
	float x;
	float y;
};

enum SCREENS
{
	SCREEN_INTRO,
	SCREEN_MENU,
	SCREEN_LEVEL1,
	SCREEN_LEVEL2,
	SCREEN_GAMEOVER,
	SCREEN_HIGHSCORS
};

enum class FACING
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
	SDL_Texture* imagePath;
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



