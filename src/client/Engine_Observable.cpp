#include <stdio.h>
#include "engine.h"

using namespace engine;

Engine_Observable::~Engine_Observable(){
}

void Engine_Observable::registerObserver(Engine_Observer* o) const{
    this->observers.push_back(o);
}

void Engine_Observable::notifyUpdated() const{
}

void Engine_Observable::notifyUpdating() const{
}



