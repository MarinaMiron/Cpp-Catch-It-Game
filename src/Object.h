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
    virtual void Draw() = 0;
    virtual Texture2D GetTexture();
    virtual Vector2 GetPos();
    virtual ~Object();
};
#endif