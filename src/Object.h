#ifndef OBJECT_H
#define OBJECT_H
 
#include <raylib.h>

class Object
{
protected:
    Vector2 position;
    Texture2D texture;
    
public:
    Object();

    ~Object();
};
#endif