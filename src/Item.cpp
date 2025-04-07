#include "Item.h"
#include <iostream>

Item::Item(){
    Image apple_image = LoadImage("./graphics/apple.png");
    if (apple_image.data == nullptr) {
        std::cout << "Failed to load apple.png!" << std::endl;
    }
    texture = LoadTextureFromImage(apple_image);
    UnloadImage(apple_image);
    position = GenerateRandomPos();
}

void Item::Draw()
{
    DrawTexture(texture, position.x, position.y, WHITE);

}

Vector2 Item::GenerateRandomPos()
{
    float x = (float)GetRandomValue(0, (cellCount * cellSize) - texture.width);
    float y = - (float)texture.height;
    
    return {x, y};
}

void Item::Fall(int y)
{
    position.y += y;
}

Item::~Item()
{
    UnloadTexture(texture);
}