#ifndef INSTANCEMANAGER_H_
#define INSTANCEMANAGER_H_
#include "GameManager.h"
#include "TextureManager.h"

class InstanceManager {
private:
//  inline static GameManager GameManagerInstance{};
//  inline static TextureManager TextureManagerInstance{};

public:
  static GameManager& GameManagerInst() {
    static GameManager GameManagerInstance;
    return GameManagerInstance;
  }
  static TextureManager& TextureManagerInst() {
    static TextureManager TextureManagerInstance;
    return TextureManagerInstance;
  }
};

#endif
