#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include <map>
#include <SFML/Graphics.hpp>

enum class TextureID
{
  SPACE_INVADERS_SPRITE_SHEET
};

class TextureManager
{
private:
  std::map<TextureID, sf::Texture> textureMap;


public:
  TextureManager();
  ~TextureManager();

  const sf::Texture& get(TextureID id);

  TextureManager(const TextureManager& rhs) = delete;
  TextureManager& operator=(const TextureManager& rhs) = delete;
};


#endif
