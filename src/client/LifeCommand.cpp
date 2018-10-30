/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include "state.h"
#include "engine.h"

using namespace engine;

LifeCommand::LifeCommand(int character, int pv){
    if(pv>=0 and pv <=100){
        this->character=character;
        this->pv=pv;
    }
    else{
        throw "PV Invalides !";
    }
    
}


CommandTypeId  LifeCommand::getTypeId() const{
    return(CommandTypeId::LIFE);
}

void LifeCommand::execute(state::State& act_state){
    
    //On cast un Element en Character
    state::Character* char_ptr= dynamic_cast<state::Character*>(act_state.getCharacters()->getElementList()[character]);
    char_ptr->setPV(pv);   
}


