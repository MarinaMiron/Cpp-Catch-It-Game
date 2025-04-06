#include <raylib.h>
#include "variables.cpp"
#include "Player.h"

int main() 
{
    InitWindow(screenWidth, screenHeight, "Catch It!");
    SetTargetFPS(60);

    Player player = Player();
    
    while(!WindowShouldClose())
    {
        if(IsKeyPressed(KEY_LEFT) || IsKeyPressedRepeat(KEY_LEFT))
        {
            player.Move(-10);
        } 
        if(IsKeyPressed(KEY_RIGHT) || IsKeyPressedRepeat(KEY_RIGHT))
        {
            player.Move(10);
        } 
        
        BeginDrawing();
        ClearBackground(pictonBlue);
        
        player.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}