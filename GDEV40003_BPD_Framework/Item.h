#pragma once
#include "GameObject.h"
#include "vector"

class Character;
class BackgroundManager;

class Item : public GameObject
{
public:
	Item(SDL_Renderer* renderer, Vector2D start_position);
	~Item();

	virtual void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

	void Move(Vector2D movement, float deltaTime) override;
	void Rolling(Vector2D movement, float deltaTime) override;

	void DropItem(string imagePath, Vector2D m_position, int m_quantity);
	void RemoveItem(const std::string& imagePath);

	vector<DroppedItems> m_dropped_items;
};

