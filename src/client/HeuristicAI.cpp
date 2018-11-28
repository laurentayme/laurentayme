#include <stdio.h>
#include <stdlib.h>
#include "ai.h"
#include "engine.h"
#include <vector>
#include <random>
#include <iostream>
#include <math.h>
#include<algorithm>


using namespace ai;
using namespace std;

HeuristicAI::HeuristicAI(const state::State& state, int randomseed){
	mt19937 randgen(randomseed);
}

void HeuristicAI::run(engine::Engine& engine, int character, state::State& state){
	
	std::vector<engine::Command*> move_list;

    	listCommands(state,character,move_list);
	
	
	//state->getCharacters()->getElementList()[


}


void HeuristicAI::stateChanged(const state::Event& event) {

}
