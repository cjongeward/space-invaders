#include "GameManager.h"
#include "Debugger.h"
#include "TimeManager.h"

GameManager::GameManager() :
  window(sf::VideoMode(1080, 800), "", sf::Style::Default)
{
}

void GameManager::updateFrameTime()
{
  this->elapsedTime = frameTimeController.getFrameTime();
  TimeManager::getInstance().increment(this->elapsedTime);
  Debugger::getInstance().addFrameTime(this->elapsedTime);
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
      Debugger::getInstance().message("Hello");
    }
  }
}

void GameManager::update()
{
}

void GameManager::draw()
{
  this->window.clear();
  this->window.draw(Debugger::getInstance().getStats().getDrawable());
  this->window.draw(Debugger::getInstance().getMessages().getDrawable());
  this->window.draw(spriteMan.get(SpriteID::ALIEN1));
  this->window.display();
}
