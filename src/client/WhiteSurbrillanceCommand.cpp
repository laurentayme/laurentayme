/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WhiteSurbrillanceCommand.c
 * Author: valentin
 */


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "state.h"
#include "engine.h"
#include "ai.h"
#include <math.h>
#include <algorithm>

using namespace engine;

WhiteSurbrillanceCommand::WhiteSurbrillanceCommand(float x, float y){
    this->x=x;
    this->y=y;
}

CommandTypeId WhiteSurbrillanceCommand::getTypeId() const{
    return(CommandTypeId::WHITESURBRILLANCE);
}

void WhiteSurbrillanceCommand::execute(state::State& act_state){
    
    float Tile_height=60.0/1.30;
    float Tile_Width=120.0/1.28;
    
    
    int case_x=(x-362)/67;
    int case_y=(y-595)/62;
    
    if(case_x==0){
        float loc_x=(360+3);
        float loc_y=(615-2)+case_y*(61-5);
    
        act_state.getRedMap()->setLocation(loc_x,loc_y,1);
    }
    else{
        float loc_x=(362+3)+abs((case_x-1))*67+64;
        float loc_y=(615-2)+case_y*(61-5);
    
        act_state.getRedMap()->setLocation(loc_x,loc_y,1);
    }
    
    float x_mouse_iso=(this->y-30)/Tile_height-(this->x-650-Tile_Width/2)/Tile_Width;
    float y_mouse_iso=(this->y-30)/Tile_height+(this->x-650-Tile_Width/2)/Tile_Width;
    
    //On récupère la position du personnage joueur
    if (case_y==0){
        if(case_x<=act_state.getCharacters()->getElementList()[0]->getAbilitiesList().size()-1){
            int portee=act_state.getCharacters()->getElementList()[0]->getAbilitiesList()[case_x]->getUseDistance();
            int character=1;
            std::vector<std::shared_ptr<state::Position>> move_list;

            ai::PathMap characterMap;
            characterMap.init(act_state,character);
            std::priority_queue<ai::Point,std::vector<ai::Point>,ai::PointCompareWeight> queue=characterMap.getQueue();

            int Poids_min=0;
            int Poids_max=portee;

            while(!queue.empty()){
                ai::Point pt=queue.top();
                queue.pop();
                //On filtre les cases correspondantes ) la portée de chaque attaque
                if((pt.getWeight()>=Poids_min) and (pt.getWeight()<=Poids_max)){
                    std::shared_ptr<state::Position> pos(new state::Position(pt.getX(),pt.getY()));
                    move_list.push_back(pos);   
                }
            }

            for(int i=0; i<move_list.size();i++){
                act_state.getRedMap()->setElement(*move_list[i],3+i) ; 
                move_list[i]=nullptr;
            }
        }
    
    }
}
