#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "state.h"
#include "engine.h"

using namespace engine;

CommandTypeId TurnCommand::getTypeId() const {
	return(CommandTypeId::TURN);
}

void TurnCommand::execute(state::State& state){
	state.setTour(state.getTour()+1);
}
