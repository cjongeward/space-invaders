#include "TimeManager.h"

void TimeManager::increment(const sf::Time & elapsedTime)
{
  this->currentTime += elapsedTime;
  while (this->commandQueue.size() > 0 && this->commandQueue.top().runTime < this->currentTime)
  {
    auto cmd = this->commandQueue.top();
    this->commandQueue.pop();
    cmd.command();
  }
}

void TimeManager::addCommand(const sf::Time & runTime, const std::function<void()>& command)
{
  CommandAction ca;
  ca.command = command;
  ca.runTime = runTime;
  this->commandQueue.push(std::move(ca));
}
