#include <stdio.h>
#include "state.h"
#include "engine.h"
#include <iostream>
#include "math.h"

using namespace engine;


MouseMovedCommand::MouseMovedCommand(int x, int y) {
    this->x_mouse=x;
    this->y_mouse=y;
}

CommandTypeId MouseMovedCommand::getTypeId() const{
    return CommandTypeId::MOUSEMOVED;
}

void MouseMovedCommand::execute(state::State& state){
}

void MouseMovedCommand::execute(state::State& state, engine::Engine& engine){
    float Tile_height=60.0/1.30;
    float Tile_Width=120.0/1.28;
    
    float x_mouse_iso=(this->y_mouse-30)/Tile_height-(this->x_mouse-650-Tile_Width/2)/Tile_Width;
    float y_mouse_iso=(this->y_mouse-30)/Tile_height+(this->x_mouse-650-Tile_Width/2)/Tile_Width;

    state::Position position(100,100);
    
    
    if(y_mouse>=590 and  x_mouse>=362 and x_mouse<=1000 ){
        //On masque les autres surbrillances
        state.getRedMap()->setElement(position,0);
        state.getRedMap()->setLocation(-100,-100,2); //TurnSurbrillance

        WhiteSurbrillanceCommand* case_blanche=new WhiteSurbrillanceCommand(x_mouse,y_mouse);
        engine.addCommand(2,case_blanche);
        //engine.update();
    }

    //Bouton Fin du Tour
    else if(x_mouse>=1030  and y_mouse>=470 and y_mouse<=540){
        //On masque les autres surbrillances
        state.getRedMap()->setElement(position,0);//Case Rouge
        state.getRedMap()->setLocation(-100,-100,1);//WhiteSurbrillance

        TurnSurbrillanceCommand* turn_blanche=new TurnSurbrillanceCommand;
        engine.addCommand(2,turn_blanche);
        //engine.update();
    }



    else if(int(x_mouse_iso)>0 and int(x_mouse_iso)<16 and int(y_mouse_iso)>0 and int(y_mouse_iso)<11 and ((x_mouse_iso+y_mouse_iso)<22) and y_mouse<=615) {

        state.getRedMap()->setLocation(-100,-100,1);//WhiteSurbrillance
        state.getRedMap()->setLocation(-100,-100,2);//TurnSurbrillance

        SurbrillanceCommand* case_rouge=new SurbrillanceCommand(int(x_mouse_iso),int(y_mouse_iso));
        engine.addCommand(2, case_rouge);
        //engine.update();
    }

    else{
        //Masque toutes les surbrillances
        state.getRedMap()->setLocation(-100,-100,2);
        state.getRedMap()->setLocation(-100,-100,1);
        state.getRedMap()->setElement(position,0);
    }
}


