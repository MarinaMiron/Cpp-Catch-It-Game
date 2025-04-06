#include <raylib.h>
#include "variables.cpp"
#include "Player.h"

int main() 
{
    InitWindow(2 * offset + screenWidth, 2 * offset + screenHeight, "Catch It!");
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
        DrawText("Catch It!", offset, 10, 40, night);
        DrawRectangleLinesEx(Rectangle{(float)offset, (float)offset, (float)screenWidth, (float)screenHeight}, 5, night);
        player.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}