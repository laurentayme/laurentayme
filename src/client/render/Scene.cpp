#include <stdio.h>
#include "state.h"
#include "render.h"
#include <iostream>


using namespace render;

Scene::Scene(state::State& state):state(state),stateLayer(state),
    gridLayer(*state.getMap()),charsLayer(*state.getCharacters()),
    LandscapeLayer(*state.getLandscape()),WallLayer(*state.getWall()),
    RedLayer(*state.getRedMap()), MenuLayer(*state.getMenu()){
 
    stateLayer.initSurface();
    gridLayer.initSurface();
    charsLayer.initSurface();
    LandscapeLayer.initSurface();
    WallLayer.initSurface();
    RedLayer.initSurface();
    MenuLayer.initSurface();  
}


size_t Scene::getWidth() const{
    return (this->width);
}

size_t Scene::getHeight() const{
    return(this->height);
}


void Scene::stateChanged(const state::Event& event){
    if(event.getEventType()==state::StateEventId::CharactersChanged){
        this->charsLayer.stateChanged(event);
    }
    else if (event.getEventType()==state::StateEventId::MapChanged){
        this->gridLayer.stateChanged(event);
    }
    
    else{
        this->stateLayer.stateChanged(event);
    }
}


void Scene::draw(sf::RenderWindow& window){
    window.clear();
    window.draw(*this->gridLayer.getSurface().get());
    window.draw(*this->LandscapeLayer.getSurface().get());
    window.draw(*this->WallLayer.getSurface().get());
    window.draw(*this->MenuLayer.getSurface().get());
    window.draw(*this->RedLayer.getSurface().get());
    window.draw(*this->charsLayer.getSurface().get());
    window.draw(this->stateLayer.getTextpv());
    window.draw(this->stateLayer.getTextpvSram());
    window.draw(this->stateLayer.getTextpa());
    window.draw(this->stateLayer.getTextpm());
    window.display();
}

ElementTabLayer& Scene::getCharsLayer(){
    ElementTabLayer& chars=this->charsLayer;
    return (chars);
}

ElementTabLayer& Scene::getRedLayer(){
    ElementTabLayer& red=this->RedLayer;
    return (red);
}

StateLayer& Scene::getStateLayer(){
    StateLayer& statelayer=this->stateLayer;
    return (statelayer);
}

ElementTabLayer& Scene::getMapLayer(){
    return this->gridLayer;
}

state::State& Scene::getState(){
    //state::State& stat=this->state;
    return(this->state);
}
