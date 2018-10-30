/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include "state.h"
#include "engine.h"

using namespace engine;

Command::Command(){
}

Command::~Command(){
}

CommandTypeId Command::getTypeId() const{
}

void Command::execute(state::State& state){
}
