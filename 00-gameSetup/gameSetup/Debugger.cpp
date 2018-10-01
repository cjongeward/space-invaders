#include "Debugger.h"
#include "TimeManager.h"

Debugger::Debugger()
{
  sf::Font font;
  if (font.loadFromFile("../../resources/OpenSans-Regular.ttf"))
  {
    this->statText.setFont(font);
    this->statText.setCharacterSize(15);
    this->statText.setPosition(sf::Vector2f(1024.f - 200.f, 0.f));
    this->debugText.setFont(font);
    this->debugText.setCharacterSize(15);
  }
  this->command = [&]() {
    updateStats();
    TimeManager::getInstance().addCommand(TimeManager::getInstance().getCurrentTime() + sf::seconds(1), command);
  };
  TimeManager::getInstance().addCommand(TimeManager::getInstance().getCurrentTime(), command);
}

void Debugger::updateDebugText()
{
  std::string msg;
  for (auto str : this->msgList)
  {
    msg.append(str);
    msg.append("\n");
  }
  this->debugText.setText(msg);

}

void Debugger::addFrameTime(const sf::Time& time)
{
  this->frameTime = time;
  if (time > this->peakFrameTime)
  {
    this->peakFrameTime = time;
  }
}

void Debugger::updateStats()
{
  this->stats.assign("frame time: ");
  this->stats.append(std::to_string(this->frameTime.asSeconds()));
  this->stats.append(" s\n");
  this->stats.append("frame rate: ");
  this->stats.append(std::to_string(1000000 / (this->frameTime.asMicroseconds() + 1)));
  this->stats.append(" fps\n");
  this->stats.append("peak frame time: ");
  this->stats.append(std::to_string(this->peakFrameTime.asSeconds()));
  this->stats.append(" s\n");
  this->statText.setText(this->stats);
}

void Debugger::message(const std::string & str)
{
  this->msgList.push_back(str);
  TimeManager::getInstance().addCommand(TimeManager::getInstance().getCurrentTime() + sf::seconds(5), [&]() {
    msgList.pop_front();
    updateDebugText();
  });
  this->updateDebugText();
}
