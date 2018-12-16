#include <stdio.h>
#include "render.h"
#include "state.h"

using namespace render;

/*Scene::Scene(const state::State& state_v):state(state_v),debugLayer(DebugLayer(state_v)){
    
    state::ElementTab map(state_v.getMap()->getWidth(),state_v.getMap()->getHeight(),state_v.getMap()->getElementList());
    gridLayer=ElementTabLayer(map);
    charsLayer=ElementTabLayer(*state_v.getCharacters()); 
    stateLayer=StateLayer(state_v);
}*/


size_t Scene::getWidth() const{
    return (this->width);
}

size_t Scene::getHeight() const{
    return( this->height);
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
    //window.draw(this->gridLayer.getSurface());
    //window.draw(*elmtTabLayerLandscape_ptr->getSurface());
    //window.draw(*elmtTabLayerWall_ptr->getSurface());
    //window.draw(this->stateLayer.getSurface());
    //window.draw(*elmtTabLayerRed_ptr->getSurface());
    //window.draw(this->charsLayer.getSurface());
    window.draw(this->stateLayer.getTextpv());
    window.draw(this->stateLayer.getTextpvSram());
    window.draw(this->stateLayer.getTextpa());
    window.draw(this->stateLayer.getTextpm());
    window.display();

    

}

DebugLayer& Scene::getDebugLayer(){
    return(this->debugLayer);
}