#ifndef TIMEMANAGER_H_
#define TIMEMANAGER_H_

#include <SFML/System.hpp>
#include <queue>
#include <vector>
#include <functional>
#include "CommandAction.hpp"

class TimeManager
{
private:
  sf::Time currentTime;
  std::priority_queue< CommandAction, std::vector<CommandAction>, std::greater<CommandAction>> commandQueue;

public:
  static TimeManager& getInstance() {
    static TimeManager instance;
    return instance;
  }
  const sf::Time& getCurrentTime() const {
    return this->currentTime;
  }

  void increment(const sf::Time& elapsedTime);
  void addCommand(const sf::Time& runTime, const std::function<void()>& command);

  TimeManager() = default;
  TimeManager(const TimeManager& rhs) = delete;
  TimeManager& operator=(const TimeManager& rhs) = delete;
};

#endif

