#include "Object.h"

Object::Object()
{
}

Texture2D Object::GetTexture()
{
    return texture;
}

Vector2 Object::GetPos()
{
    return position;
}

Object::~Object()
{
}