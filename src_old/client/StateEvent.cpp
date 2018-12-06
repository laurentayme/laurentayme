#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "state.h"

using namespace state;

StateEvent::StateEvent(StateEventId s){
	stateEvent=s;


}

EventTypeId StateEvent::getEventType() const {
	return(State_Event);

}
