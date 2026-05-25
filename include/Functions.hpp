#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <raylib.h>
#include <deque>
#include <Game.hpp>

bool EventTriggered(double interval);
bool ElementInDeque(Vector2 element, const std::deque<Vector2>& deque);
void StartGame(Game* game);

#endif