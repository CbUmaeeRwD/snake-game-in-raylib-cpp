#include <Functions.hpp>
#include <Variables.hpp>
#include <raymath.h>
#include <Game.hpp>

double LastUpdateTime = 0;

bool EventTriggered(double interval){
  double currentTime = GetTime();

  if(currentTime - LastUpdateTime >= interval){
    LastUpdateTime = currentTime;
    return true;
  }

  return false;
}

bool ElementInDeque(Vector2 element, const std::deque<Vector2>& deque){
  for (size_t i = 0; i < deque.size(); i++)
    if(Vector2Equals(deque[i], element))
      return true;

  return false;
}

void StartGame(Game* game){
  if (!game->running){
    PlayMusicStream(game->bgm);
    game->running = true;
  }
}