
#include "TestArena.h"
#include <ctime>

TestArena::TestArena(SDL_Renderer* renderer)
{
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
    m_waveTimer += deltaTime;
    if (m_waveTimer >= WAVE_INTERVAL)
    {
        m_waveTimer = 0.0f;
        m_currentWave++;
        if (m_currentWave > 10)
        {
            m_currentWave = 10;
        }
        SpawnWave(3 + m_currentWave);
    }

    RemoveDeadEnemies();
}

void TestArena::Render()
{
    for (Goblin* enemy : m_goblin)
    {
        enemy->Render();
    }
}

void TestArena::SpawnWave(int numberOfEnemies)
{
    if (m_level1background != nullptr)
    {
        m_level1background->SetSpawnPoints();

        for (int i = 0; i < numberOfEnemies; ++i)
        {

            if (!m_level1background->spawnPoints.empty())
            {
                // Randomly select a spawn point
                int randomIndex = rand() % m_level1background->spawnPoints.size();
                Vector2D spawnPosition = m_level1background->spawnPoints[randomIndex];

                // Create an enemy at the spawn position (replace with your actual enemy creation logic)
                Goblin* enemy = new Goblin(m_renderer, spawnPosition);
                m_goblin.push_back(enemy);

                m_level1background->spawnPoints.erase(m_level1background->spawnPoints.begin() + randomIndex);
            }
        }
    }
}

void TestArena::RemoveDeadEnemies()
{
    auto it = m_goblin.begin();
    while (it != m_goblin.end())
    {
        if ((*it)->m_health.m_is_dead)
        {
            delete* it;
            it = m_goblin.erase(it);
        }
        else
        {
            ++it;
        }
    }
}