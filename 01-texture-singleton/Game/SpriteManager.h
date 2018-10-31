#ifndef SPRITEMANAGER_H_
#define SPRITEMANAGER_H_

#include <map>
#include <SFML/Graphics.hpp>

enum class SpriteID
{
  SPACE_INVADERS_SPRITE_SHEET,
  ALIEN1
};

class SpriteManager {
private:
  std::map<SpriteID, sf::Sprite> spriteMap;

public:
  SpriteManager();
  ~SpriteManager();

  sf::Sprite& get(SpriteID id);

  SpriteManager(const SpriteManager& rhs) = delete;
  SpriteManager& operator=(const SpriteManager& rhs) = delete;
};

#endif
