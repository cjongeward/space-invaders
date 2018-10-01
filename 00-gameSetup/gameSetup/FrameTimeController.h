#ifndef FRAMETIMECONTROLLER_H_
#define FRAMETIMECONTROLLER_H_

#include <SFML/System.hpp>

class FrameTimeController
{
private:
  sf::Clock systemClock;

public:
  FrameTimeController() {}
  sf::Time getFrameTime() {
    auto elapsedTime = this->systemClock.restart();
    return elapsedTime;
  }

  FrameTimeController(const FrameTimeController& rhs) = delete;
  FrameTimeController& operator=(const FrameTimeController& rhs) = delete;
};

#endif