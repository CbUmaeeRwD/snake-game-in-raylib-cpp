#ifndef GAME_HPP
#define GAME_HPP

#include <Snake.hpp>
#include <Food.hpp>

class Game{
  public:
    Snake snake{Snake()};
    Food food{Food(snake.body)};
    bool running{true};
    int score{0};
    int highest_score{0};
    Sound eatSound;
    Sound wallSound;
    Music bgm;

    Game();
    ~Game();

    void Draw();
    void Update();
    void CheckCollisionWithFood();
    void CheckCollisionWithEdges();
    void CheckCollisionWithTail();

    void GameOver();
}; 

#endif