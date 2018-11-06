#include <stdio.h>
#include "state.h"
#include "render.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace render;

StateLayer::StateLayer (const state::State& state) : state(state) {

}

void StateLayer::initSurface (){
	//surface.initQuads(count);
	//surface.loadTexture("");

	
	
	
	
}

void StateLayer::stateChanged(const state::Event& event){
	std::cout<<"Un evenement a eu lieu et la couche StateLayer est au courant"<<std::endl;
}
