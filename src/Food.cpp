#include <Food.hpp>
#include <Functions.hpp>

Food::Food(const std::deque<Vector2>& snakeBody){
  Image image{LoadImage("graphics/food.png")};
  texture = LoadTextureFromImage(image);
  UnloadImage(image);
  pos = GenerateRandomPos(snakeBody);
}

Food::~Food(){
  UnloadTexture(texture);
}

void Food::Draw(){
  DrawTexture(texture, Offset + pos.x * CellSize, Offset + pos.y * CellSize, WHITE);
}

Vector2 Food::GenerateRandomCell(){
  float x = GetRandomValue(0, CellCount - 1);
  float y = GetRandomValue(0, CellCount - 1);
  return Vector2{x, y};
}

Vector2 Food::GenerateRandomPos(const std::deque<Vector2>& snakeBody){
  Vector2 pos{GenerateRandomCell()};
  while(ElementInDeque(pos, snakeBody))
    pos = GenerateRandomCell();
  return pos;
}