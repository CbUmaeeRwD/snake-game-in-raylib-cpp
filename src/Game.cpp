#include <Game.hpp>
#include <Functions.hpp>

Game::Game(){
  InitAudioDevice();
  eatSound = LoadSound("sounds/eat.mp3");
  wallSound = LoadSound("sounds/wall.mp3");
  bgm = LoadMusicStream("sounds/bgm.mp3");
}

Game::~Game(){
  UnloadSound(eatSound);
  UnloadSound(wallSound);
  UnloadMusicStream(bgm);
  CloseAudioDevice();
}

void Game::Draw(){
  food.Draw();
  snake.Draw();
}

void Game::Update(){
  if(running){
    snake.Update();
    CheckCollisionWithFood();
    CheckCollisionWithEdges();
    CheckCollisionWithTail();
  }
}

void Game::CheckCollisionWithFood(){
  if(Vector2Equals(snake.body[0], food.pos)){
    food.pos = food.GenerateRandomPos(snake.body);
    snake.addSegment = true;
    score++;
    PlaySound(eatSound);
  }
}

void Game::CheckCollisionWithEdges(){
  if(snake.body[0].x == CellCount || snake.body[0].x == -1)
    GameOver();
  if(snake.body[0].y == CellCount || snake.body[0].y == -1)
    GameOver();
}

void Game::CheckCollisionWithTail(){
  std::deque<Vector2> headlessBody = snake.body;
  headlessBody.pop_front();
  if(ElementInDeque(snake.body[0], headlessBody))
    GameOver();
}

void Game::GameOver(){
  snake.Reset();
  food.pos = food.GenerateRandomPos(snake.body);
  running = false;
  if (highest_score < score)
    highest_score = score;
  score = 0;
  StopMusicStream(bgm);
  PlaySound(wallSound);
}