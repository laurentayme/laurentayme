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
    
    float x_mouse_iso=(this->y_mouse-40)/Tile_height-(this->x_mouse-650-Tile_Width/2)/Tile_Width;
    float y_mouse_iso=(this->y_mouse-40)/Tile_height+(this->x_mouse-650-Tile_Width/2)/Tile_Width;

    state::Position position(100,100);
    
    if(state.getEtat()==1){
        //Menu d'attaques
        if(y_mouse>=590 and  x_mouse>=362 and x_mouse<=760 ){
        //On masque les autres surbrillances
        for(size_t i=0;i<5;i++){
        state::Position posRef(100,100);
        state.getRedMap()->setElement(posRef,i);
        }
        state.getRedMap()->setLocation(-100,-100,6); //TurnSurbrillance
        for(int i=3; i<state.getRedMap()->getElementList().size();i++){
            state.getRedMap()->setElement(position,i);//Cases Bleues
        }
        WhiteSurbrillanceCommand* case_blanche=new WhiteSurbrillanceCommand(x_mouse,y_mouse);
        engine.addCommand(2,case_blanche);
        //engine.update();
    }

    //Bouton Fin du Tour
    else if(x_mouse>=1030  and y_mouse>=470 and y_mouse<=540){
        //On masque les autres surbrillances
        //Cases Rouges
        for(size_t i=0;i<5;i++){
        state::Position posRef(100,100);
        state.getRedMap()->setElement(posRef,i);
        }
        state.getRedMap()->setLocation(-100,-100,5);//WhiteSurbrillance
        for(int i=8; i<state.getRedMap()->getElementList().size();i++){
            state.getRedMap()->setElement(position,i);//Cases Bleues
        }
        

        TurnSurbrillanceCommand* turn_blanche=new TurnSurbrillanceCommand;
        engine.addCommand(2,turn_blanche);
        //engine.update();
    }


    //Plateau de jeu
    else if(int(x_mouse_iso)>0 and int(x_mouse_iso)<16 and int(y_mouse_iso)>0 and int(y_mouse_iso)<11 and ((x_mouse_iso+y_mouse_iso)<22) and y_mouse<=615) {

        state.getRedMap()->setLocation(-100,-100,5);//WhiteSurbrillance
        state.getRedMap()->setLocation(-100,-100,6);//TurnSurbrillance
       
        for(int i=8; i<state.getRedMap()->getElementList().size();i++){
            state.getRedMap()->setElement(position,i);//Cases Bleues
        }
        

        SurbrillanceCommand* case_rouge=new SurbrillanceCommand(int(x_mouse_iso),int(y_mouse_iso));
        engine.addCommand(2, case_rouge);
        //engine.update();
    }

    else{
        //Masque toutes les surbrillances
        state.getRedMap()->setLocation(-100,-100,6);
        state.getRedMap()->setLocation(-100,-100,5);
        //Cases Rouges
        for(size_t i=0;i<5;i++){
            state::Position posRef(100,100);
            state.getRedMap()->setElement(posRef,i);
        }
        
        
        for(int i=8; i<state.getRedMap()->getElementList().size();i++){
            state.getRedMap()->setElement(position,i);//Cases Bleues
        }
    }
    }
    else if(state.getEtat()==0){
        if(x_mouse>=320 and x_mouse<=850 and y_mouse>=350 and y_mouse<=420){
            //std::cout<<"I should display New Game in White"<<std::endl;
            state.getMenu()->setElementType(0,4);
        }
        
        else if( x_mouse>=400 and x_mouse<=820 and y_mouse>=480 and y_mouse<=550 ){
            //std::cout<<"I should display Exit in White"<<std::endl;
            state.getMenu()->setElementType(0,5);
        }
        else{
            state.getMenu()->setElementType(0,3);
        }
        
        
    }
    
}

Json::Value MouseMovedCommand::serialize(){
	Json::Value cmd;
	cmd[" Type "]=this->getTypeId();
	cmd[" X Mouse "]=this->x_mouse;
	cmd[" Y Mouse"]=this->y_mouse;
	return cmd;

}

void MouseMovedCommand::deserialize(Json::Value cmd){
	this->x_mouse=cmd[" X Mouse "].asInt();
	this->y_mouse=cmd[" Y Mouse "].asInt();
}



