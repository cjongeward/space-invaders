#include "GameManager.h"
#include "Debugger.h"
#include "InstanceManager.h"
#include "Settings.h"
#include <cstdlib>

GameManager::GameManager() :
  window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "", sf::Style::Default)
{
}

void GameManager::updateFrameTime()
{
  auto elapsedTime = frameTimeController.getFrameTime();
  InstanceManager::TimeManagerInst().increment(elapsedTime);
  InstanceManager::DebuggerInst().addFrameTime(elapsedTime);
}

void GameManager::handleEvents()
{
  sf::Event event;
  while (window.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
    {
      window.close();
    }
    if (event.type == sf::Event::KeyPressed)
    {
      InstanceManager::DebuggerInst().message("Hello");
    }
  }
}

void GameManager::update()
{
}

void GameManager::draw()
{
  this->window.clear();
  this->window.draw(InstanceManager::DebuggerInst().getStats().getDrawable());
  this->window.draw(InstanceManager::DebuggerInst().getMessages().getDrawable());
  for (int i = 0; i < 25; ++i) {
    auto & s = spriteMan.get(SpriteID::ALIEN1);
    s.setPosition(static_cast<float>(rand() % SCREEN_WIDTH), static_cast<float>(rand() % SCREEN_HEIGHT));
    this->window.draw(s);
  }
  this->window.display();
}
