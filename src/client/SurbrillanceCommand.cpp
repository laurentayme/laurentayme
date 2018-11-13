/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "state.h"
#include "engine.h"

using namespace engine;

SurbrillanceCommand::SurbrillanceCommand(int x, int y){
    x_mouse_iso=x;
    y_mouse_iso=y;
}

CommandTypeId SurbrillanceCommand::getTypeId() const{
    return(CommandTypeId::SURBRILLANCE);
}

void SurbrillanceCommand::execute(state::State& act_state){
    state::Position pos(x_mouse_iso,y_mouse_iso);
    state::Position& posRef=pos;
    act_state.getRedMap()->setElement(posRef,0);
}