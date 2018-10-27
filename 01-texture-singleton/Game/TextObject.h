#ifndef TEXTOBJECT_H_
#define TEXTOBJECT_H_

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class TextObject : public GameObject
{
private:
  sf::Text text;
  sf::Font font;

public:
  void setFont(const sf::Font& newFont);
  void setText(const std::string& str);
  void setCharacterSize(const unsigned int size);

  const sf::Drawable& getDrawable() const override {
    return this->text;
  }
  void update(const sf::Time& elapsedTime) override {}
  const sf::Vector2f& getPosition() const override {
    return this->text.getPosition();
  }
  void setPosition(const sf::Vector2f& newPos) override {
    this->text.setPosition(newPos);
  }
};


#endif

