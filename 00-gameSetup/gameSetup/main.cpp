#include "GameManager.h"

int main()
{
  GameManager gameManager;

  while (gameManager.getWindow().isOpen())
  {
    gameManager.updateFrameTime();
    gameManager.handleEvents();
    gameManager.update();
    gameManager.draw();
  }

  return 0;
}