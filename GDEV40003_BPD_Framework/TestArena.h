#ifndef ARENA_H
#define ARENA_H

#include <vector>
#include "BasicEnemy.h"
#include "Character.h"
#include "Level1BackgroundManager.h"
#include "GameObject.h"
using namespace std;

class GameText;
class Goblin;
class Bat;
class Slime;

class TestArena : public GameObject
{
public:
    TestArena(SDL_Renderer* renderer, Vector2D start_position);
    ~TestArena();

    void Update(float deltaTime, SDL_Event e) override;
    void Render() override;
    void IncreaseWave();

    vector<BasicEnemy*> m_enemies;

    void SetLevel1BackgroundPointer(Level1BackgroundManager* m_background) { m_level1background = m_background; }

    int m_currentWave;

private:
    void SpawnEnemies();
    void RemoveDeadEnemies();

    SDL_Texture* m_arena_summon;

    int m_num_of_enemies;
    int m_total_enemies_spawned;
    int m_target_for_next_wave;
    int m_max_num_enemies_spawned;

    float m_spawn_intervals;
    float m_spawn_timer;

    bool m_wave_triggered;

    Character* m_character;
    Level1BackgroundManager* m_level1background;
    GameText* m_text;
};

#endif // ARENA_H

