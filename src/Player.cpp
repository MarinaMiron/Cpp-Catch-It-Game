#include "Player.h"


Player::Player()
{
    Image image = LoadImage("./graphics/basket.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    position = {(cellSize * cellCount - image.width) / 2.0f, (float)cellSize * cellCount - image.height};
}

void Player::Draw()
{
    DrawTexture(texture, position.x, position.y, WHITE);
}

void Player::Move(int x)
{
    position.x += x;
}

Player::~Player()
{
    UnloadTexture(texture);
}