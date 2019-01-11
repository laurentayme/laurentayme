#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "state.h"
#include "engine.h"

using namespace engine;

TurnCommand::TurnCommand(state::State& state){
}



CommandTypeId TurnCommand::getTypeId() const {
	return(CommandTypeId::TURN);
}

void TurnCommand::execute(state::State& state){
    
    int iop_pa=state.getCharacters()->getElementList()[0]->getMaxStat(2);
    int iop_pm=state.getCharacters()->getElementList()[0]->getMaxStat(1);
    
    int sram_pa=state.getCharacters()->getElementList()[1]->getMaxStat(2);
    int sram_pm=state.getCharacters()->getElementList()[1]->getMaxStat(1);
    
    
    if(state.getTour()%2==1){
        state.getCharacters()->setCharacterPA(0,iop_pa);
        state.getCharacters()->setCharacterPM(0,iop_pm);
    }
    else if (state.getTour()%2==0){
        state.getCharacters()->setCharacterPA(1,sram_pa);
        state.getCharacters()->setCharacterPM(1,sram_pm);
    }
    
    state.setTour(state.getTour()+1);
}

Json::Value TurnCommand::serialize(){
		Json::Value cmd;
		cmd[" Type "]=this->getTypeId();
		return cmd;

}

void TurnCommand::deserialize(Json::Value cmd){
}
	
