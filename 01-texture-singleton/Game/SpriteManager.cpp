#include "SpriteManager.h"
#include <SFML/Graphics.hpp>
#include "InstanceManager.h"

SpriteManager::SpriteManager()
{
  sf::Sprite spritesheet{ InstanceManager::TextureManagerInst().get(TextureID::SPACE_INVADERS_SPRITE_SHEET) };
  this->spriteMap[SpriteID::SPACE_INVADERS_SPRITE_SHEET] = std::move(spritesheet);
  sf::Sprite alien1{ InstanceManager::TextureManagerInst().get(TextureID::SPACE_INVADERS_SPRITE_SHEET), sf::IntRect{136, 65, 85, 61 } };
  this->spriteMap[SpriteID::ALIEN1] = std::move(alien1);
}

SpriteManager::~SpriteManager()
{
}

sf::Sprite& SpriteManager::get(SpriteID id)
{
  return this->spriteMap[id];
}


