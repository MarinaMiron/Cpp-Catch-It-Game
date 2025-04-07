#ifndef ITEM_H
#define ITEM_H

#include <raylib.h>
#include "Object.h"
#include "variables.h"

class Item: public Object
{
private:
    
public:
    Item();
    void Draw() override;
    
    Vector2 GenerateRandomPos();

    void Fall(int y);

    ~Item();
};
#endif