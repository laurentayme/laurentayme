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

Json::Value TurnCommand::serialize(){
		Json::Value cmd;
		cmd[" Type "]=this->getTypeId();
		return cmd;

}

void TurnCommand::deserialize(Json::Value cmd){
}
	
