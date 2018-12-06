#include <stdio.h>
#include "state.h"
#include "engine.h"
#include <iostream>
#include "math.h"

using namespace engine;

ClickCommand::ClickCommand(int x, int y) {
    this->x_mouse=x;
    this->y_mouse=y;
}

CommandTypeId ClickCommand::getTypeId() const{
    return CommandTypeId::CLICK;
}

void ClickCommand::execute(state::State& state){
 
}

void ClickCommand::execute(state::State& state, engine::Engine& engine){
    float Tile_height=60.0/1.30;
    float Tile_Width=120.0/1.28;
    
    float x_mouse_iso=(this->y_mouse-30)/Tile_height-(this->x_mouse-650-Tile_Width/2)/Tile_Width;
    float y_mouse_iso=(this->y_mouse-30)/Tile_height+(this->x_mouse-650-Tile_Width/2)/Tile_Width;

    if(state.getEtat()==1){
        if(this->y_mouse>=590 and  this->x_mouse>=362 and this->x_mouse<=1000 ){
            std::cout<<"I verify conditions to create an AttackCommand"<<std::endl;
            AttackCommand* attaque= new AttackCommand(0,1,this->x_mouse,this->y_mouse);
            engine.addCommand(2,attaque);
        }

        //Bouton Fin du Tour
        else if(this->x_mouse>=1030  and this->y_mouse>=470 and this->y_mouse<=540){
            //Changement de Tour
            std::cout<<state.getTour()<<std::endl;
            int tour=state.getTour()+1;
            state.setTour(tour);
        }

        else if(int(x_mouse_iso)>0 and int(x_mouse_iso)<16 and int(y_mouse_iso)>0 and int(y_mouse_iso)<11 and ((x_mouse_iso+y_mouse_iso)<22) and y_mouse<=600) {
            //Gestion Déplacement//
            int vectX=int(x_mouse_iso)-state.getCharacters()->getElementList()[0]->getPosition().getX();
            int vectY=int(y_mouse_iso)-state.getCharacters()->getElementList()[0]->getPosition().getY();
            MoveCharacterCommand* deplacement=new MoveCharacterCommand(0,vectX,vectY);
            engine.addCommand(2,deplacement);

        } 
    }
    else if (state.getEtat()==0){
        if(x_mouse>=320 and x_mouse<=850 and y_mouse>=350 and y_mouse<=420){
            state.getMenu()->setElementType(0,2);
            state.setEtat(1);
        }
        else if( x_mouse>=400 and x_mouse<=820 and y_mouse>=480 and y_mouse<=550 ){
            state.setEtat(3);
        }
    }
    
}

