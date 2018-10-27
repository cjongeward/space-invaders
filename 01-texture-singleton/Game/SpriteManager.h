#ifndef SPRITEMANAGER_H_
#define SPRITEMANAGER_H_

#include <map>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

enum class SpriteID
{
  SPACE_INVADERS_SPRITE_SHEET,
  ALIEN1
};

class SpriteManager {
private:
  TextureManager texMan;
  std::map<SpriteID, sf::Sprite> spriteMap;

public:
  SpriteManager();
  ~SpriteManager();

  const sf::Sprite& get(SpriteID id);

  SpriteManager(const SpriteManager& rhs) = delete;
  SpriteManager& operator=(const SpriteManager& rhs) = delete;
};

#endif
