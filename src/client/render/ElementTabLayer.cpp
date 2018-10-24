#include <stdio.h>
#include "state.h"
#include "render.h"
#include <SFML/Graphics.hpp>

using namespace render;

ElementTabLayer::ElementTabLayer (const state::ElementTab& tab) : tab(tab) {

}

void initSurface(int count){
	surface.initQuads(count);
	surface.loadTexture("");

	
	
	
	
}

ElementTabLayer::~ElementTabLayer(){

}
