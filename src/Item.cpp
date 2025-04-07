#include "Item.h"
#include <iostream>

Item::Item(){
    Image image = LoadImage("./graphics/apple.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    position = GenerateRandomPos();
}

void Item::Draw()
{
    DrawTexture(texture, position.x, position.y, WHITE);
}

Vector2 Item::GenerateRandomPos()
{
    float x = GetRandomValue(0, (cellCount * cellSize) - 1);
    float y = 0 - texture.height;
    std::cout << x << std::endl;
    return {x, y};
}

Item::~Item(){
    UnloadTexture(texture);
}