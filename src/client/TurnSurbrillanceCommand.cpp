/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WhiteSurbrillanceCommand.c
 * Author: valentin
 */


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "state.h"
#include "engine.h"
#include <math.h>

using namespace engine;

CommandTypeId TurnSurbrillanceCommand::getTypeId() const{
    return(CommandTypeId::TURNSURBRILLANCE);
}

void TurnSurbrillanceCommand::execute(state::State& act_state){
    act_state.getRedMap()->setLocation(1035,495,6); 
}


Json::Value TurnSurbrillanceCommand::serialize(){
	Json::Value cmd;
	cmd[" Type "]=this->getTypeId();
	return cmd;

}

void TurnSurbrillanceCommand::deserialize(Json::Value cmd){
}
