#include <iostream>
#include <raylib.h>
#include "variables.h"
#include "Game.h"

// Update the game after 'interval' time
bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main() 
{
    InitWindow(cellSize * cellCount, cellSize * cellCount, "Catch It!");
    SetTargetFPS(60);

    Game game = Game();

    while(!WindowShouldClose())
    {
        BeginDrawing();

        if(EventTriggered(0.2))
        {
            game.Update();  
        }
        
        if((IsKeyPressed(KEY_LEFT) || IsKeyPressedRepeat(KEY_LEFT)) && game.player.GetPos().x >= 0)
        {
            game.player.Move(-10);
        } 
        if((IsKeyPressed(KEY_RIGHT) || IsKeyPressedRepeat(KEY_RIGHT)) && (game.player.GetPos().x + game.player.GetTexture().width) <= cellCount * cellSize)
        {
            game.player.Move(10);
        }

        ClearBackground(pictonBlue);
        
        game.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}