#include "TestArena.h"

TestArena::TestArena(SDL_Renderer* renderer)
{
    m_renderer = renderer;
    // Initial wave spawn
    SpawnWave(3);
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
        SpawnWave(5 + m_currentWave * 2);
    }

    for (Goblin* enemy : m_goblin)
    {
        enemy->Update(deltaTime, e);
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
    for (int i = 0; i < numberOfEnemies; ++i)
    {
        Vector2D startPosition(rand() % 800, 585); // Random spawn position at the top
        Goblin* enemy = new Goblin(m_renderer, startPosition);
        m_goblin.push_back(enemy);
    }
}

void TestArena::RemoveDeadEnemies()
{
    auto it = m_goblin.begin();
    while (it != m_goblin.end())
    {
        if ((*it)->m_is_dead)
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