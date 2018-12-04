/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include "ai.h"
#include "state/State.h"
#include <math.h>
#include <iostream>

using namespace ai;


int PathMap::getWeight(const Point& p)const{
    return(p.getWeight());
}

void PathMap::setWeight(Point& p){
    int w=p.getWeight();
    weights.push_back(w);
}

const int* PathMap::getWeights()const {
    const int* w_ptr(&weights[0]);
    return (w_ptr);
}

void PathMap::init(const state::State& act_state,int character){
    
    state::ElementTab* Chars=act_state.getCharacters();
    state::ElementTab* Map=act_state.getMap();
    state::ElementTab* Landscape=act_state.getLandscape();
    
    std::vector<state::Element*> elmt_list=Map->getElementList();
    std::vector<state::Element*> Obstacle_list=Landscape->getElementList();
    std::vector<state::Element*> Character_list=Chars->getElementList();

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
    int distance_cible;
    //On met tous les points dans la queue
    for(size_t i=0; i<elmt_list.size();i++){
        int x=elmt_list[i]->getPosition().getX();
        int y=elmt_list[i]->getPosition().getY();
        for(size_t j=0; j<Character_list.size();j++){
		if(Character_list[character]->getTeam()!=Character_list[j]->getTeam()){
        		int diff_x=x-Character_list[j]->getPosition().getX();
        		int diff_y=y-Character_list[j]->getPosition().getY();
        
        		//distance_cible=sqrt((float)(pow(diff_x,2.0) + pow(diff_y,2.0))); //Cible
			distance_cible=abs(diff_x) + abs(diff_y);
		}
	}
        
        Point p(x,y,distance_cible);
        
        //On vérifie qu'il n'y a pas d'obstacle à cette position et sur ce déplacement
        for(int j=0;j<Obstacle_list.size();j++){
            
            if(Obstacle_list[j]->getPosition().getX()==p.getX() and Obstacle_list[j]->getPosition().getY()==p.getY()){
                p.setWeight(pow(10.0,8.0));
            }
        }
        
        queue.push(p);
       
    }  
}


void PathMap::update(const state::State& act_state,int character){
    state::ElementTab* Chars=act_state.getCharacters();
    state::ElementTab* Map=act_state.getMap();
    state::ElementTab* Landscape=act_state.getLandscape();
    
    std::vector<state::Element*> elmt_list=Map->getElementList();
    std::vector<state::Element*> Character_list=Chars->getElementList();
    std::vector<state::Element*> Obstacle_list=Landscape->getElementList();
    
    //Queue Tampon
    std::priority_queue<Point,std::vector<Point>,PointCompareWeight> queue_tampon;
    /////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //On met tous les points dans la queue tampon
    while(!queue.empty()){
	int distance_cible;
        Point p=queue.top();
        queue.pop();
        for(size_t j=0; j<Character_list.size();j++){
		if(Character_list[character]->getTeam()!=Character_list[j]->getTeam()){
        		int diff_x=p.getX()-Character_list[j]->getPosition().getX();
        		int diff_y=p.getY()-Character_list[j]->getPosition().getY();
        
        		//distance_cible=sqrt((float)(pow(diff_x,2.0) + pow(diff_y,2.0))); //Cible
			distance_cible=abs(diff_x) + abs(diff_y);
		}
	}
        /*int diff_x=p.getX()-Character_list[target]->getPosition().getX();
        int diff_y=p.getY()-Character_list[target]->getPosition().getY();
        //Mise a jour de la distance a la cible
        int distance_cible=sqrt((float)(pow(diff_x,2.0) + pow(diff_y,2.0))); //Cible*/
        //Mise a jour du poids de chaque Point
        p.setWeight(distance_cible);  
        
        //On vérifie qu'il n'y a pas d'obstacle à cette position
        for(int j=0;j<Obstacle_list.size();j++){
            if(Obstacle_list[j]->getPosition().getX()==p.getX() and Obstacle_list[j]->getPosition().getY()==p.getY()){
                p.setWeight(pow(10.0,8.0));
            }
        }
        
        queue_tampon.push(p);
       
    }
    //recopie du contenu de la queue tampon
    queue=queue_tampon;
}

std::priority_queue<Point,std::vector<Point>,PointCompareWeight> PathMap::getQueue() const{
    return(queue);
}
