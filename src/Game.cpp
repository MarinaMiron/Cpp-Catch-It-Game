#include "Game.h"

Game::Game(){}

void Game::Draw()
{
    player.Draw();
    item.Draw();
}

// Update the game
void Game::Update()
{
    if(running)
    {
        item.Fall(20);
    }
}

Game::~Game(){}