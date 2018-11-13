#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "state.h"

using namespace state;

TabEvent::TabEvent(int x,int y){
	this->x=x;
	this->y=y;
}

TabEvent::~TabEvent(){
}

EventTypeId TabEvent::getEventType() const {
	return(Tab_Event);
}
