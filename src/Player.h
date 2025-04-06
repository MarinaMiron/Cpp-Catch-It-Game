#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include "Object.h"

class Player: public Object
{
private:
    
public:
    Player();
    void Draw();
    void Move(int x){Object::position.x += x;};
    
    ~Player();
};
#endif