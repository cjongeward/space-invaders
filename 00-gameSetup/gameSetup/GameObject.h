#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <SFML/Graphics.hpp>

class GameObject
{
public:
  virtual ~GameObject() {};
  virtual const sf::Drawable& getDrawable() const = 0;
  virtual void update(const sf::Time& elapsedTime) = 0;
  virtual const sf::Vector2f& getPosition() const = 0;
  virtual void setPosition(const sf::Vector2f& newPos) = 0;
};

#endif
