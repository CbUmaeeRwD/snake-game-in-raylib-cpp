#include <Snake.hpp>

void Snake::Draw(){
  for (size_t i = 0; i < body.size(); i ++){
    float x{body[i].x};
    float y{body[i].y};
    Rectangle rectangle{Rectangle{Offset + x * CellSize, Offset + y * CellSize, CellSize, CellSize}};
    DrawRectangleRounded(rectangle, 0.3, 10, (i == 0) ? HeadGreen : DarkGreen);
  }
}

void Snake::Update(){
  body.push_front(Vector2Add(body[0], direction));
  if(addSegment == true)
    addSegment = false;
  else
    body.pop_back();
}

void Snake::Reset(){
  body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
  direction = {1, 0};
}