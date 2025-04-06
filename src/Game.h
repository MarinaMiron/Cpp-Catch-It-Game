#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "variables.h"

class Game
{
private:
    bool running = true;

public:
    Player player;

    Game();
    void Draw();
    void Update();


    ~Game();
};
#endif