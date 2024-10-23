#include "TestArena.h"
#include "GameText.h"
#include "Goblin.h"
#include "Bat.h"
#include "Slime.h"
#include <ctime>

TestArena::TestArena(SDL_Renderer* renderer, Vector2D start_position) : GameObject(renderer, start_position)
{
    m_currentWave = 0;
    m_num_of_enemies = 0;
    m_total_enemies_spawned = 0;
    m_target_for_next_wave = 0;
    m_max_num_enemies_spawned = 5;

    m_spawn_timer = 0;
    m_spawn_intervals = 7;

    m_width = 64;
    m_height = 96;

    m_wave_triggered = false;
    srand(static_cast<unsigned int>(time(0)));

    if (m_texture != nullptr)
    {
        m_arena_summon = m_texture->LoadFromTileMap("images/Overworld_Tile/TX Props.png");
    }

    m_text = new GameText(m_renderer, "fonts/arial.ttf", 18);
}

TestArena::~TestArena()
{
    for (BasicEnemy* enemy : m_enemies)
    {
        delete enemy;
    }
    m_enemies.clear();
}

void TestArena::Update(float deltaTime, SDL_Event e)
{
    if (m_wave_triggered)
    {
        m_spawn_timer += deltaTime;

        cout << m_spawn_timer << endl;

        if (m_spawn_timer == m_spawn_intervals || m_num_of_enemies == 0)
        {
            m_spawn_timer = 0;

            if (m_total_enemies_spawned < m_target_for_next_wave)
            {
                SpawnEnemies();
            }
            else
            {
                if (m_num_of_enemies == 0)
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
    srcRect.x = 416;
    srcRect.y = 0;
    srcRect.w = 96;
    srcRect.h = 96;

    m_texture->Render(m_arena_summon, srcRect, Vector2D(m_position.x, m_position.y), SDL_FLIP_NONE);

    for (BasicEnemy* enemy : m_enemies)
    {
        enemy->Render();
    }

    m_text->SetColor({ 255, 0, 0, 255 });
    m_text->RenderTextAt("Wave : ", 15, 25);
    m_text->RenderNumberAt(m_currentWave, 80, 25);
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

        if (m_currentWave > 7)
        {
            m_max_num_enemies_spawned++;
        }
    }
}

void TestArena::SpawnEnemies()
{
    if (m_level1background != nullptr)
    {
        m_level1background->SetSpawnPoints();

        for (int i = 0; i < m_max_num_enemies_spawned; ++i)
        {
            if (7 > m_num_of_enemies && m_total_enemies_spawned != m_target_for_next_wave)
            {
                if (!m_level1background->spawnPoints.empty())
                {
                    // Randomly select a spawn point
                    int randomIndex = rand() % m_level1background->spawnPoints.size();
                    Vector2D spawnPosition = m_level1background->spawnPoints[randomIndex];

                    int randomEnemy = rand() % 4;

                    if (randomEnemy == 1)
                    {
                        Goblin* enemy = new Goblin(m_renderer, spawnPosition);
                        m_enemies.push_back(enemy);
                    }
                    else if (randomEnemy == 2)
                    {
                        Bat* enemy = new Bat(m_renderer, spawnPosition);
                        m_enemies.push_back(enemy);
                    }
                    else
                    {
                        Slime* enemy = new Slime(m_renderer, spawnPosition);
                        m_enemies.push_back(enemy);
                    }

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
    vector<BasicEnemy*>::iterator it = m_enemies.begin();
    while (it != m_enemies.end())
    {
        if ((*it)->m_health.m_is_dead)
        {
            (*it)->Dead();
            delete* it;
            it = m_enemies.erase(it);
            m_num_of_enemies -= 1;
        }
        else
        {
            ++it;
        }
    }
}