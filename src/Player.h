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
    void Draw();
    void Move(int x){Object::position.x += x;};
    Texture2D GetTexture(){return Object::texture;};
    Vector2 GetPos(){return Object::position;};
    
    ~Player();
};
#endif