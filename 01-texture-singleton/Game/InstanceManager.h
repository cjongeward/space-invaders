#ifndef INSTANCEMANAGER_H_
#define INSTANCEMANAGER_H_
#include "GameManager.h"
#include "TextureManager.h"
#include "TimeManager.h"
#include "Debugger.h"

class InstanceManager {
public:
  static auto& GameManagerInst() {
    static GameManager inst;
    return inst;
  }
  static auto& TextureManagerInst() {
    static TextureManager inst;
    return inst;
  }
  static auto& TimeManagerInst() {
    static TimeManager inst;
    return inst;
  }
  static auto& DebuggerInst() {
    static Debugger inst;
    return inst;
  }
};

#endif
