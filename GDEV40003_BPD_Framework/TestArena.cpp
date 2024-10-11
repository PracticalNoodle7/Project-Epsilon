
#include "TestArena.h"
#include <ctime>

TestArena::TestArena(SDL_Renderer* renderer)
{
    m_currentWave = 0;
    m_num_of_enemies = 0;
    m_total_enemies_spawned = 0;
    m_target_for_next_wave = 0;

    m_spawn_timer = 0;
    m_spawn_intervals = 15;

    m_wave_triggered = false;

    m_renderer = renderer;
    srand(static_cast<unsigned int>(time(0)));
}

TestArena::~TestArena()
{
    for (Goblin* enemy : m_goblin)
    {
        delete enemy;
    }
    m_goblin.clear();
}

void TestArena::Update(float deltaTime, SDL_Event e)
{
    if (m_wave_triggered)
    {
        m_spawn_timer += deltaTime;

        if (m_spawn_timer == m_spawn_intervals || m_num_of_enemies == 0)
        {
            m_spawn_timer = 0;

            if (m_total_enemies_spawned < m_target_for_next_wave)
            {
                SpawnEnemies();
            }
            else
            {
                if (m_num_of_enemies = 0)
                {
                    IncreaseWave();
                }
            }
        }

        RemoveDeadEnemies();
    }
}

void TestArena::Render()
{
    for (Goblin* enemy : m_goblin)
    {
        enemy->Render();
    }
}

void TestArena::IncreaseWave()
{
    m_currentWave++;

    if (m_currentWave % 5 == 0)
    {
        m_wave_triggered = false;

        //TODO :: Spawn loot chest
    }
    else
    {
        m_wave_triggered = true;
        m_total_enemies_spawned = 0;
        m_target_for_next_wave += 5;
    }
}

void TestArena::SpawnEnemies()
{
    if (m_level1background != nullptr)
    {
        m_level1background->SetSpawnPoints();

        for (int i = 0; i < 3; ++i)
        {
            if (7 < m_num_of_enemies && m_total_enemies_spawned != m_target_for_next_wave)
            {
                if (!m_level1background->spawnPoints.empty())
                {
                    // Randomly select a spawn point
                    int randomIndex = rand() % m_level1background->spawnPoints.size();
                    Vector2D spawnPosition = m_level1background->spawnPoints[randomIndex];

                    // Create an enemy at the spawn position (replace with your actual enemy creation logic)
                    Goblin* enemy = new Goblin(m_renderer, spawnPosition);
                    m_goblin.push_back(enemy);

                    m_num_of_enemies++;
                    m_total_enemies_spawned++;

                    m_level1background->spawnPoints.erase(m_level1background->spawnPoints.begin() + randomIndex);
                }
            }
            else if (m_total_enemies_spawned == m_target_for_next_wave && m_num_of_enemies == 0)
            {
                IncreaseWave();
            }
        }
    }
}

void TestArena::RemoveDeadEnemies()
{
    vector<Goblin*>::iterator it = m_goblin.begin();
    while (it != m_goblin.end())
    {
        if ((*it)->m_health.m_is_dead)
        {
            delete* it;
            it = m_goblin.erase(it);
            m_num_of_enemies -= 1;
        }
        else
        {
            ++it;
        }
    }
}