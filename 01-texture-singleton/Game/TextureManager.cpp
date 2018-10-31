#include "TextureManager.h"

TextureManager::TextureManager()
{
  loadTextures();
}

void TextureManager::loadTextures()
{
  this->textureMap[TextureID::SPACE_INVADERS_SPRITE_SHEET].loadFromFile("space.tga");
}

const sf::Texture& TextureManager::get(TextureID id)
{
  return this->textureMap[id];
}

