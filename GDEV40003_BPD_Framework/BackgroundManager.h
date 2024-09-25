#pragma once
#include "GameObject.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "Character.h"
using namespace std;

class BackgroundManager : public GameObject
{
public:
	BackgroundManager(SDL_Renderer* renderer, Vector2D start_position);
	~BackgroundManager();

	void LoadTileMapFromFile(const std::string& fileName, std::vector<std::vector<int>>& tileMap, int& rows, int& columns, Layer layer);
	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

	void Move(Vector2D movement, float deltaTime);
	void Rolling(Vector2D movement, float deltaTime);

	void SetSpawnPoints();
	bool IsSpawnNearPlayer(int row, int column);

	void SetCharacter(Character* m_character) { this->m_character = m_character; }
	Rect2D GetCollisionBox() { return Rect2D(m_position.x, m_position.y, 16, 16); }

	vector<Vector2D> spawnPoints;
	vector<vector<int>> levelMap;
	vector<vector<Tile>> m_background_map;
	vector<vector<Tile>> m_wall_map;
protected:
	int rows, columns;
	float m_movment_speed;
	Character* m_character;
};
