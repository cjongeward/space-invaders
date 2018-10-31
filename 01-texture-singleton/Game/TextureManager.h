#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include <map>
#include <SFML/Graphics.hpp>

enum class TextureID
{
  SPACE_INVADERS_SPRITE_SHEET
};


class TextureManager {
  friend class InstanceManager;
private:
  std::map<TextureID, sf::Texture> textureMap;

  TextureManager();
  void loadTextures();

public:
  const sf::Texture& get(TextureID id);

  TextureManager(const TextureManager& rhs) = delete;
  TextureManager& operator=(const TextureManager& rhs) = delete;
};

#endif
