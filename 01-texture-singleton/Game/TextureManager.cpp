#include "TextureManager.h"

TextureManager::TextureManager()
{
  sf::Texture tex;
  tex.loadFromFile("space.tga");
  this->textureMap[TextureID::SPACE_INVADERS_SPRITE_SHEET] = std::move(tex);
}

TextureManager::~TextureManager()
{
}

const sf::Texture& TextureManager::get(TextureID id)
{
  return this->textureMap[id];
}

