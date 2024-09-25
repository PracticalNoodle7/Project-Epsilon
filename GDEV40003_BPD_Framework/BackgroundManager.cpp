
#include "BackgroundManager.h"
#include "Texture2D.h"
#include "Constants.h"

BackgroundManager::BackgroundManager(SDL_Renderer* renderer, Vector2D start_position) : GameObject(renderer, start_position)
{
    rows = 0;
    columns = 0;
    m_movment_speed = 1;
}

BackgroundManager::~BackgroundManager()
{
    rows, columns, m_movment_speed = 0;

    //cleaning up vectors
    spawnPoints.clear();
    spawnPoints.shrink_to_fit();

    levelMap.clear();
    levelMap.shrink_to_fit();

    m_background_map.clear();
    m_background_map.shrink_to_fit();

    m_wall_map.clear();
    m_wall_map.shrink_to_fit();
}

void BackgroundManager::LoadTileMapFromFile(const std::string& fileName, std::vector<std::vector<int>>& tileMap, int& rows, int& columns, Layer layer)
{
    ifstream file(fileName);
    string line;

    if (!file) {
        cerr << "Failed to open file: " << fileName << endl;
        return;
    }

    // Read the first line to get the number of rows and columns
    getline(file, line);
    stringstream ss(line);
    ss >> rows >> columns;

    // Resize the tile map to fit the number of rows and columns
    tileMap.clear();
    tileMap.resize(rows, vector<int>(columns));

    // Read the rest of the file to populate the tile map
    int row = 0;
    while (getline(file, line) && row < rows) {
        stringstream lineStream(line);
        int tileValue;
        int col = 0;

        while (lineStream >> tileValue && col < columns) {
            tileMap[row][col] = tileValue;
            col++;
        }
        row++;
    }

    file.close();

    switch (layer)
    {
    case BACKGROUND:
        m_background_map.resize(rows, std::vector<Tile>(columns));

        for (int row = 0; row < rows; row++)
        {
            for (int column = 0; column < columns; column++)
            {
                m_background_map[row][column].type = levelMap[row][column];
                m_background_map[row][column].x = (column + 5) * 31;
                m_background_map[row][column].y = (row + 5) * 31;
            }
        }
        break;


    case WALLS:
        m_wall_map.resize(rows, std::vector<Tile>(columns));

       for (int row = 0; row < rows; row++)
       {
            for (int column = 0; column < columns; column++)
            {
                m_wall_map[row][column].type = levelMap[row][column];
                m_wall_map[row][column].x = (column + 5) * 31;
                m_wall_map[row][column].y = (row + 5) * 31;
            }
       }
       break;
    }
}

void BackgroundManager::Render()
{

}

void BackgroundManager::Update(float deltaTime, SDL_Event e)
{
    m_is_moving = false;  // Assume not moving by default

    Vector2D movement(0.0f, 0.0f);  // Initialize movement vector

    if (m_can_move && !GameObject::m_rolling)
    {
        // Calculate movement vector
        if (m_move_up)
        {
            movement.y += 1;
        }
        if (m_move_left)
        {
            movement.x += 1;
        }
        if (m_move_down)
        {
            movement.y -= 1;
        }
        if (m_move_right)
        {
            movement.x -= 1;
        }

    }
    if (GameObject::m_rolling)
    {
        Rolling(movement, deltaTime);
    }



    // Normalize the movement vector to prevent faster diagonal movement
    if (movement.x != 0 || movement.y != 0)
    {
        movement = movement.Normalize();
        m_is_moving = true;

        // Apply movement
        if (!GameObject::m_rolling)
        {
            Move(movement, deltaTime);
        }

    }

    // Handle the events
    switch (e.type)
    {
    case SDL_KEYDOWN:

        switch (e.key.keysym.sym)
        {
            // Press W to move up
        case SDLK_w:
            m_move_up = true;
            break;

            // Press A to move left
        case SDLK_a:
            m_move_left = true;
            break;

            // Press S to move down
        case SDLK_s:
            m_move_down = true;
            break;

            // Press D to move right
        case SDLK_d:
            m_move_right = true;
            break;
        }
        break;
    case SDL_KEYUP:
        switch (e.key.keysym.sym)
        {
            // Check if W is up
        case SDLK_w:
            m_move_up = false;
            break;

            // Check if A is up
        case SDLK_a:
            m_move_left = false;
            break;

            // Check if S is up
        case SDLK_s:
            m_move_down = false;
            break;

            // Check if D is up
        case SDLK_d:
            m_move_right = false;
            break;
        }
    }
}

void BackgroundManager::Move(Vector2D movement, float deltaTime)
{
    // Apply movement to the tile map
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            m_background_map[row][column].x += movement.x * deltaTime * 200;
            m_background_map[row][column].y += movement.y * deltaTime * 200;

            if (m_wall_map.size() != 0)
            {
                m_wall_map[row][column].x += movement.x * deltaTime * 200;
                m_wall_map[row][column].y += movement.y * deltaTime * 200;
            }
        }
    }

    if (movement.y > 0)
    {
        ChangeFacingDirection(FACING::FACING_UP);
    }
    else if (movement.y < 0)
    {
        ChangeFacingDirection(FACING::FACING_DOWN);
    }
    else if (movement.x > 0)
    {
        ChangeFacingDirection(FACING::FACING_LEFT);
    }
    else if (movement.x < 0)
    {
        ChangeFacingDirection(FACING::FACING_RIGHT);
    }
}

void BackgroundManager::Rolling(Vector2D movement, float deltaTime)
{
    switch (m_facing_direction)
    {
    case FACING::FACING_RIGHT:
        movement.x -= 1.5;
        movement.y = 0;
        break;

    case FACING::FACING_LEFT:
        movement.x += 1.5;
        movement.y = 0;
        break;

    case FACING::FACING_DOWN:
        movement.y -= 1.5;
        movement.x = 0;
        break;

    case FACING::FACING_UP:
        movement.y += 1.5;
        movement.x = 0;
        break;
    }

    // Apply movement to the tile map
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            m_background_map[row][column].x += movement.x * deltaTime * 200;
            m_background_map[row][column].y += movement.y * deltaTime * 200;

            if (m_wall_map.size() != 0)
            {
                m_wall_map[row][column].x += movement.x * deltaTime * 200;
                m_wall_map[row][column].y += movement.y * deltaTime * 200;
            }
        }
    }
}

void BackgroundManager::SetSpawnPoints()
{
    spawnPoints.clear();

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            //Set type 0 as spawn locations
            if (m_background_map[row][column].type == 0 && IsSpawnNearPlayer(row, column))
            {
                // Add the tile's position to the list of spawn points
                Vector2D spawnPosition(m_background_map[row][column].x, m_background_map[row][column].y);
                spawnPoints.push_back(spawnPosition);
            }
        }
    }
}

bool BackgroundManager::IsSpawnNearPlayer(int row, int column)
{
    Vector2D vec = Vector2D((m_character->m_position.x - m_background_map[row][column].x), (m_character->m_position.y - m_background_map[row][column].y));

    double distance = sqrt((vec.x * vec.x) + (vec.y * vec.y));

    if (!distance < 100)
    {
        return distance < 300;
    }
}








