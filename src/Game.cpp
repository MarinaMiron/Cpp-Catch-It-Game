#include "Game.h"
#include <raymath.h>

Game::Game(){}

// Spawn new 'fruit' item
void Game::SpawnItem()
{
    items.emplace_back(std::make_unique<Item>());
}

void Game::Draw()
{
    player.Draw();
    for (auto& item : items)
    {
      item->Draw();  
    }
    
}

// Update the game
void Game::Update()
{
    if(running)
    {
        for (auto& item : items)
        {
          item->Fall(20);  
        }
        
        CheckCollisionWithItem();
        CheckCollisionWithBottom();
    }
}

// Checking if item touched bottom
void Game::CheckCollisionWithBottom()
{
    for(auto it = items.begin(); it != items.end();)
    {
       if((*it)->GetPos().y + (*it)->GetTexture().height >= cellSize * cellCount)
        {
            it = items.erase(it); // delete object
            SpawnItem(); // spawn new object
        } 
        else
        {
            ++it;
        }
    }
    
}

// Checking if item was caugth
void Game::CheckCollisionWithItem()
{
    // Make rectangle for player object
    Rectangle playerRect = {
        player.GetPos().x,
        player.GetPos().y,
        (float)player.GetTexture().width,
        (float)player.GetTexture().height
    };
    
    for(auto it = items.begin(); it != items.end();)
    {
        // Make rectangle for item object
        Rectangle itemRect = {
        (*it)->GetPos().x,
        (*it)->GetPos().y,
        (float)(*it)->GetTexture().width,
        (float)(*it)->GetTexture().height
        };

        // Check for collision between rectangles
        if(CheckCollisionRecs(playerRect, itemRect))
        {
            score++;
            it = items.erase(it); // delete object
            SpawnItem(); // spawn new object
        
        }
        else
        {
            ++it;
        }
    }
}

Game::~Game() {}