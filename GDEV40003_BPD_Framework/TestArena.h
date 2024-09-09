#ifndef ARENA_H
#define ARENA_H

#include <vector>
#include "BasicEnemy.h"
#include "Goblin.h"
#include "Character.h"
using namespace std;

class TestArena
{
public:
    TestArena(SDL_Renderer* renderer);
    ~TestArena();

    void Update(float deltaTime, SDL_Event e);
    void Render();

    vector<Goblin*> m_goblin;

private:
    void SpawnWave(int numberOfEnemies);
    void RemoveDeadEnemies();

    SDL_Renderer* m_renderer;

    int m_currentWave;
    float m_waveTimer;
    const float WAVE_INTERVAL = 20.0f; // Interval between waves in seconds 

    Character* m_character;
    Goblin* enemy;
};

#endif // ARENA_H

