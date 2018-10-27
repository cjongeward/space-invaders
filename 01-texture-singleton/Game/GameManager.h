#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include <functional>
#include <memory>
#include <SFML/Graphics.hpp>
#include "FrameTimeController.h"
#include "SpriteManager.h"

class GameManager
{
private:
  sf::RenderWindow window;
  sf::Time elapsedTime;
  FrameTimeController frameTimeController;
  SpriteManager spriteMan;

public:
  GameManager();
  const sf::RenderWindow& getWindow() const {
      return this->window;
  }

  void updateFrameTime();
  void handleEvents();
  void update();
  void draw();

  GameManager(const GameManager& rhs) = delete;
  GameManager& operator=(const GameManager& rhs) = delete;
};

#endif