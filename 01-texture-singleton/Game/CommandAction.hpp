#ifndef COMMANDACTION_H_
#define COMMANDACTION_H_

#include <functional>
#include <SFML/System.hpp>
struct CommandAction
{
  sf::Time runTime;
  std::function<void()> command;
  CommandAction* next;

  CommandAction() : next(nullptr) { }
  auto operator>(const CommandAction& rhs) const
  {
    return this->runTime > rhs.runTime;
  }
};



#endif