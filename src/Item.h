#ifndef ITEM_H
#define ITEM_H

#include <raylib.h>
#include <vector>

#include "Object.h"
#include "variables.h"

class Item: public Object
{
private:
    std::vector<Image> fruitTextures;

public:
    Item();
    void Draw() override;
    
    Vector2 GenerateRandomPos();

    void Fall(int y);

    ~Item();
};
#endif