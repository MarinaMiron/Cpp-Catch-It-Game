#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <raylib.h>
#include "Object.h"
#include "variables.h"

class Player: public Object
{
private:
    
public:
    Player();
    void Draw() override;

    void Move(int x);
    
    ~Player();
};
#endif