#include "Player.h"
#include "variables.cpp"

Player::Player()
{
    Image image = LoadImage("./graphics/basket.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    position = {offset + (screenWidth - image.width) / 2.0f, (float)offset + screenHeight - image.height};
}

void Player::Draw()
{
    DrawTexture(texture, position.x, position.y, WHITE);
}

bool Player::CheckCollisionWithEdge()
{
    bool i = [](){};
    return i;
}

Player::~Player()
{
    UnloadTexture(texture);
}