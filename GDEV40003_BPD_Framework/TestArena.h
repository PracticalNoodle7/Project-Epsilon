#ifndef ARENA_H
#define ARENA_H

#include <vector>
#include "BasicEnemy.h"
#include "Goblin.h"
#include "Character.h"
#include "Level1BackgroundManager.h"
using namespace std;

class TestArena
{
public:
    TestArena(SDL_Renderer* renderer);
    ~TestArena();

    void Update(float deltaTime, SDL_Event e);
    void Render();

    vector<Goblin*> m_goblin;

    void SetLevel1BackgroundPointer(Level1BackgroundManager* m_background) { m_level1background = m_background; }

private:
    void SpawnWave(int numberOfEnemies);
    void RemoveDeadEnemies();

    SDL_Renderer* m_renderer;

    int m_currentWave;
    float m_waveTimer;
    const float WAVE_INTERVAL = 5.0f; // Interval between waves in seconds 

    Character* m_character;
    Goblin* enemy;
    Level1BackgroundManager* m_level1background;
};

#endif // ARENA_H

