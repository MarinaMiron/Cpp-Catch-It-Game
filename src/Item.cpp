#include "Item.h"
#include <iostream>
#include <filesystem>

Item::Item(){
    namespace fs = std::filesystem;

    for (const auto& entry : fs::directory_iterator("./graphics/fruits")) 
    {
        if (entry.path().extension() == ".png") 
        {
            Image img = LoadImage(entry.path().string().c_str());
            fruitTextures.push_back(img);
        }
    }

    int randomIndex = GetRandomValue(0, (int)fruitTextures.size() - 1); // select fruit

    texture = LoadTextureFromImage(fruitTextures[randomIndex]);

    for(auto tex : fruitTextures)
    {
        UnloadImage(tex);
    }

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