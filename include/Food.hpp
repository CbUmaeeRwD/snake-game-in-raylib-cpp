#ifndef FOOD_HPP
#define FOOD_HPP

#include <deque>
#include <raylib.h>
#include <raymath.h>
#include <Variables.hpp>

class Food{
  public:
    Vector2 pos;
    Texture2D texture;

    Food(const std::deque<Vector2>& snakeBody);
    ~Food();
    void Draw();

    Vector2 GenerateRandomCell();
    Vector2 GenerateRandomPos(const std::deque<Vector2>& snakeBody);
};

#endif