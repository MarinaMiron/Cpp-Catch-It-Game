#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Item.h"
#include "variables.h"
#include <raylib.h>
#include <vector>
#include <memory>

class Game
{
private:
    std::vector<std::unique_ptr<Item>> items;
    double lastUpdateTime = 0.0;
    double interval = 5.0;
    int speed = 3;
    bool running = true;
    int score = 0;

public:
    Player player;

    Game();
    void SpawnItem();
    void Draw();
    void Update();
    int GetScore(){return score;}; 

    void CheckCollisionWithItem();
    void CheckCollisionWithBottom();

    bool EventTriggered(double interval);
    ~Game();
};
#endif