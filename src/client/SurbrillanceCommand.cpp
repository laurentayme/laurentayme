/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "state.h"
#include "engine.h"

using namespace engine;

SurbrillanceCommand::SurbrillanceCommand(int x, int y){
    x_mouse_iso=x;
    y_mouse_iso=y;
}

CommandTypeId SurbrillanceCommand::getTypeId() const{
    return(CommandTypeId::SURBRILLANCE);
}

void SurbrillanceCommand::execute(state::State& act_state){
    
    for(size_t i=0;i<5;i++){
            state::Position posRef(100,100);
            act_state.getRedMap()->setElement(posRef,i);
    }
    
    
    std::vector<state::Element*> chars=act_state.getCharacters()->getElementList();
    int character=0;
    
    int x_character=chars[character]->getPosition().getX();
    int y_character=chars[character]->getPosition().getY();
    int pa=chars[character]->getPA();
    
    int ecart_X=x_mouse_iso-x_character;
    int ecart_Y=y_mouse_iso-y_character;
    
    int distance=abs(ecart_X)+abs(ecart_Y);
    
    std::cout<<"PA actuels: "<<pa<<std::endl;
    
    
    if(distance<=pa){
        
        state::Position pos(x_mouse_iso,y_mouse_iso);
        state::Position pos_character=chars[character]->getPosition();
        //act_state.getRedMap()->setElement(pos_character,0);
        
        for(int i=1; i<abs(ecart_Y)+1;i++){
            if(ecart_Y>=0){
               std::shared_ptr<state::Position> pos(new state::Position(chars[character]->getPosition().getX(),chars[character]->getPosition().getY()+i)); 
               act_state.getRedMap()->setElement(*pos,i); 
            }
            else{
               std::shared_ptr<state::Position> pos(new state::Position(chars[character]->getPosition().getX(),chars[character]->getPosition().getY()-i));  
               act_state.getRedMap()->setElement(*pos,i); 
            }  
            
        }
        for(int j=1; j<abs(ecart_X)+1;j++){
            if(ecart_X>=0){
               std::shared_ptr<state::Position> pos(new state::Position(chars[character]->getPosition().getX()+j,chars[character]->getPosition().getY()+ecart_Y)); 
               act_state.getRedMap()->setElement(*pos,abs(ecart_Y)+j); 
            }
            else{
               std::shared_ptr<state::Position> pos(new state::Position(chars[character]->getPosition().getX()-j,chars[character]->getPosition().getY()+ecart_Y));  
               act_state.getRedMap()->setElement(*pos,abs(ecart_Y)+j); 
            }
                
        }
        
        
        
        
    }
}
    
void SurbrillanceCommand::execute(state::State& act_state, engine::Engine& engine){
    
    for(size_t i=0;i<5;i++){
            state::Position posRef(100,100);
            act_state.getRedMap()->setElement(posRef,i);
    }
    
    
    std::vector<state::Element*> chars=engine.getState()->getCharacters()->getElementList();
    int character=0;
    
    int x_character=chars[character]->getPosition().getX();
    int y_character=chars[character]->getPosition().getY();
    int pa=chars[character]->getPA();
    
    int ecart_X=x_mouse_iso-x_character;
    int ecart_Y=y_mouse_iso-y_character;
    
    int distance=abs(ecart_X)+abs(ecart_Y);
    
    std::cout<<"PA actuels: "<<pa<<std::endl;
    
    
    if(distance<=pa){
        
        state::Position pos(x_mouse_iso,y_mouse_iso);
        state::Position pos_character=chars[character]->getPosition();
        //act_state.getRedMap()->setElement(pos_character,0);
        
        for(int i=1; i<abs(ecart_Y)+1;i++){
            if(ecart_Y>=0){
               std::shared_ptr<state::Position> pos(new state::Position(chars[character]->getPosition().getX(),chars[character]->getPosition().getY()+i)); 
               act_state.getRedMap()->setElement(*pos,i); 
            }
            else{
               std::shared_ptr<state::Position> pos(new state::Position(chars[character]->getPosition().getX(),chars[character]->getPosition().getY()-i));  
               act_state.getRedMap()->setElement(*pos,i); 
            }  
            
        }
        for(int j=1; j<abs(ecart_X)+1;j++){
            if(ecart_X>=0){
               std::shared_ptr<state::Position> pos(new state::Position(chars[character]->getPosition().getX()+j,chars[character]->getPosition().getY()+ecart_Y)); 
               act_state.getRedMap()->setElement(*pos,abs(ecart_Y)+j); 
            }
            else{
               std::shared_ptr<state::Position> pos(new state::Position(chars[character]->getPosition().getX()-j,chars[character]->getPosition().getY()+ecart_Y));  
               act_state.getRedMap()->setElement(*pos,abs(ecart_Y)+j); 
            }
                
        }
        
        
        
        
    }
} 
    
    
    
    

    