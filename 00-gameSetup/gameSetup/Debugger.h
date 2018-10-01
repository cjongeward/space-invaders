#ifndef DEBUGGER_H_
#define DEBUGGER_H_

#include <string>
#include <list>
#include <functional>
#include <SFML/System.hpp>
#include "TextObject.h"

class Debugger
{
private:
  sf::Time frameTime;
  sf::Time peakFrameTime;
  std::string stats;
  std::list<std::string> msgList;
  TextObject debugText;
  TextObject statText;
  std::function<void()> command;


public:
  static Debugger& getInstance() {
    static Debugger instance;
    return instance;
  }
  const GameObject& getMessages() const {
    return this->debugText;
  }
  const GameObject& getStats() const {
    return this->statText;
  }

  void addFrameTime(const sf::Time& time);
  void updateStats();
  void message(const std::string& str);

private:
  Debugger();
  void updateDebugText();

public:
  Debugger(const Debugger& rhs) = delete;
  Debugger& operator=(const Debugger& rhs) = delete;

};

#endif
