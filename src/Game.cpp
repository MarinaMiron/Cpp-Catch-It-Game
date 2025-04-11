#include "Game.h"
#include <raymath.h>
#include <unistd.h>

Game::Game(){
    items.emplace_back(std::make_unique<Item>());
}

// Spawn new 'fruit' item
void Game::SpawnItem()
{
    if(EventTriggered(interval))
    {
        items.emplace_back(std::make_unique<Item>()); 
        if(score > 0 && score % 5 == 0) // Increase difficulty as the score increases
        {
            if(interval != 1.0)
            {
                interval -= 0.5; 
            }
        }
    } 
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
      for(auto& item : items)
    {
    item->Fall(speed);  
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
        
        }
        else
        {
            ++it;
        }
    }
}

// Update the game after 'interval' time
bool Game::EventTriggered(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

Game::~Game() {}