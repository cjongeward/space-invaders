#include "GameManager.h"
#include "InstanceManager.h"

int main()
{
  GameManager& gameManager = InstanceManager::GameManagerInst();

  while (gameManager.getWindow().isOpen())
  {
    gameManager.updateFrameTime();
    gameManager.handleEvents();
    gameManager.update();
    gameManager.draw();
  }

  return 0;
}