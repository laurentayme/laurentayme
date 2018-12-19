#include <stdio.h>
#include "engine.h"

using namespace engine;

Engine_Observable::~Engine_Observable(){
}

void Engine_Observable::registerObserver(Engine_Observer* o) const{
    this->observers.push_back(o);
}

void Engine_Observable::notifyUpdated() const{
	auto beginList = this->observers.begin();
	auto endList = this->observers.end();
	for ( auto it = beginList; it !=endList; ++it){
		(*it)->engineUpdated();
	}
}

void Engine_Observable::notifyUpdating() const{
	auto beginList = this->observers.begin();
	auto endList = this->observers.end();
	for ( auto it = beginList; it !=endList; ++it){
		(*it)->engineUpdating();
	}
}


