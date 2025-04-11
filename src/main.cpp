#include <iostream>
#include <raylib.h>
#include "variables.h"
#include "Game.h"

int main() 
{
    InitWindow(cellSize * cellCount, cellSize * cellCount, "Catch It!");
    SetTargetFPS(60);

    Game game = Game();

    while(!WindowShouldClose())
    {
        BeginDrawing();

        game.SpawnItem();  
        
        game.Update();  
        
        if((IsKeyPressed(KEY_LEFT) || IsKeyPressedRepeat(KEY_LEFT)) && game.player.GetPos().x >= 0)
        {
            game.player.Move(-10);
        } 
        if((IsKeyPressed(KEY_RIGHT) || IsKeyPressedRepeat(KEY_RIGHT)) && (game.player.GetPos().x + game.player.GetTexture().width) <= cellCount * cellSize)
        {
            game.player.Move(10);
        }

        // Drawing
        ClearBackground(pictonBlue);
        DrawText(TextFormat("Score: %i", game.GetScore()), 10, 10, 40, night);
        game.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}