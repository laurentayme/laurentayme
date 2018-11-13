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

WhiteSurbrillanceCommand::WhiteSurbrillanceCommand(float x, float y){
    this->x=x;
    this->y=y;
}

CommandTypeId WhiteSurbrillanceCommand::getTypeId() const{
    return(CommandTypeId::WHITESURBRILLANCE);
}

void WhiteSurbrillanceCommand::execute(state::State& act_state){
    
    int case_x=(x-362)/67;
    int case_y=(y-615)/62;
    
    if(case_x==0){
        float loc_x=(362);
        float loc_y=(615)+case_y*(61-5);
    
        act_state.getRedMap()->setLocation(loc_x,loc_y,1);
    }
    else{
        float loc_x=(362)+abs((case_x-1))*67+64;
        float loc_y=(615)+case_y*(61-5);
    
        act_state.getRedMap()->setLocation(loc_x,loc_y,1);
    }
    
    
}
