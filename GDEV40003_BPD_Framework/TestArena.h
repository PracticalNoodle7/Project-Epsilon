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
    void IncreaseWave();
    void SpawnEnemies();
    void RemoveDeadEnemies();

    SDL_Renderer* m_renderer;

    int m_currentWave;
    int m_num_of_enemies;
    int m_total_enemies_spawned;
    int m_target_for_next_wave;

    float m_spawn_intervals;
    float m_spawn_timer;

    bool m_wave_triggered;

    Character* m_character;
    Goblin* enemy;
    Level1BackgroundManager* m_level1background;
};

#endif // ARENA_H

