#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Item.h"
#include "variables.h"

class Game
{
private:
    bool running = true;

public:
    Player player = Player();
    Item item = Item();

    Game();
    void Draw();
    void Update();


    ~Game();
};
#endif