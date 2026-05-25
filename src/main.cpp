#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>
#include <Functions.hpp>
#include <Variables.hpp>
#include <Snake.hpp>
#include <Food.hpp>
#include <Game.hpp>

int main(){
  InitWindow(2*Offset + CellSize * CellCount, 2*Offset + CellSize * CellCount, "Snake");
  SetTargetFPS(60);

  Game game{Game()};
  game.bgm.looping = true;
  PlayMusicStream(game.bgm);

  while(WindowShouldClose() == false){
    BeginDrawing();

    //BGM
    UpdateMusicStream(game.bgm);
    SetMusicVolume(game.bgm, 0.5);

    if(EventTriggered(0.2))
      game.Update();

    //User Inputs
    if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1){
      game.snake.direction = {0, -1};
      StartGame(&game);
    }
    if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1){
      game.snake.direction = {0, 1};
      StartGame(&game);
    }
    if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1){
      game.snake.direction = {-1, 0};
      StartGame(&game);
    }
    if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1){
      game.snake.direction = {1, 0};
      StartGame(&game);
    }

    //Drawing
    ClearBackground(Green);
    DrawRectangleLinesEx(Rectangle{(float)Offset - 5, (float)Offset - 5, (float)CellSize * CellCount + 10, (float)CellSize * CellCount + 10} , 5, DarkGreen);
    DrawText(TextFormat("Highest Score: %i", game.highest_score), Offset - 5, Offset + CellCount * CellSize + 10, 40, DarkGreen);
    DrawText(TextFormat("Score: %i", game.score), Offset - 5, 20, 40, DarkGreen);
    game.Draw();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}