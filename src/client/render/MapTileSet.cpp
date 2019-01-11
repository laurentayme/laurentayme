/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "state.h"
#include "render.h"
#include <SFML/Graphics.hpp>
#include <random>

using namespace render;

MapTileSet::MapTileSet(){
    
    //Instanciation Tiles Space
    for(int i=0;i<6;i++){
        for(int j=0;j<5;j++){
            Tile t(149*j,86*i,149,86);
            space.push_back(t);
        }
    }
    
    //Instanciation Tiles Landscape
    Tile t(149*4+(149-86)/2,86*6,86,86); //Stone Block1
    Tile t_block(149*3+(149-86)/2,86*6,97,91); //Stone Block 2
    Tile t_ground(149*2+(149-86)/2,86*6,86,86); //Ground
    Tile t_block2(149*1+(149-86)/2,86*6,85,90); //Stone Big Bock
    landscape.push_back(t);
    landscape.push_back(t_block);
    landscape.push_back(t_ground);
    landscape.push_back(t_block2);
    
    //Instanciation Tiles Wall
    Tile t1(149*4+(149-61)/2,(86*7),61,146); // Normal Wall
    Tile t2(149*4+(149-61)/2,(86*7)+146,61,146); // Erased Wall
    Tile t3(149*2+(149-64)/2,(86*7),64,143); // Pic Wall
    Tile t4(149*3+(149-64)/2,(86*6)+91,64,146); // Other Normal Wall
    wall.push_back(t1);
    wall.push_back(t2);
    wall.push_back(t3);
    wall.push_back(t4);
    
    //Instanciation Tile Space Red
    Tile t_red(0,86*3,149,86);
    Tile t_white((149-66)/2,6*86,66,62);
    Tile turn_tile(0,86*7+8,300,150);
    Tile t_blue(3*149,86*5,149,86);
    red.push_back(t_red);
    red.push_back(t_white);
    red.push_back(turn_tile);
    red.push_back(t_blue);
}

MapTileSet::~MapTileSet(){
}

std::string const MapTileSet::getImageFile(){
    return("res/Map_Tileset.png");
}


const Tile& MapTileSet::getTile(const state::Element& e){  
    //Cas d'un StaticElement
    if (e.getTypeId()==0){ 
        // Cas d'un Obstacle
        if (e.isObstacle()==true){
            // Cas d'un Mur
            if(e.isWall()==true){
                //Cas d'un Mur Plein
                if(e.getWallType()==1){
                    Tile& s=wall[2];
                    return(s);
                }
                //Cas d'un Mur Transparent
                else{
                    Tile& s=wall[1];
                    return(s);
                }
                
            }
            // Cas d'un Landscape
            else{
                
                if(e.getLandscapeType()==0){
                    std::random_device rd;
                    std::mt19937 gen(rd());
                    std::uniform_real_distribution<double> dis(0.0,1.0);
                    double x=dis(gen);
                    
                    if(x>=0.3 and x<=0.6){
                        Tile& s=landscape[0];
                        return(s);
                    }
                    else if (x>0.6){
                        Tile& s=landscape[1];
                        return(s);
                    }
                
                    else{
                        Tile& s=landscape[2];
                        return(s);
                    }
                }
                
                else{
                    Tile& s=landscape[3];
                    return(s);
                }
                
                
            }
        }
        // Cas d'un Space
        else if(e.getSpaceType()==0){
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<double> dis(0,1);
            double x=dis(gen);
            if(x<=0.2){
                Tile& s=space[25];
                return(s);
            }
            else if(x>0.2 and x<=0.4){
                Tile& s=space[21];
                return(s);
            }
            else if(x>0.4 and x<0.6){
                Tile& s=space[16];
                return(s);
            }
            else if(x>0.6 and x<0.8){
                Tile& s=space[17];
                return(s);
            }
            
            else{
                Tile& s=space[26];
                return(s);
            }
		
            
        }
        // Cas d'un red Space
        else if(e.getSpaceType()==1){	
		Tile& s=space[0];
            return(s);
        }
	else if(e.getSpaceType()==2){
		Tile& s=space[9];
	return(s);
	}
        
        else if(e.getSpaceType()==4){
            Tile& s=red[0];
            return(s);
        }
        
        else if(e.getSpaceType()==5){
            Tile& s=red[1];
            return(s);
        }
        else if(e.getSpaceType()==6){
            Tile& s=red[2];
            return(s);
        }
        else if(e.getSpaceType()==7){
            Tile& s=red[3];
            return(s);
        }
   }
    // Cas d'un Character
    else{
        throw "This is not a StaticElement !"; 
    }
}

int const MapTileSet::getCellWidth(state::Element& elmt) const{
    if (elmt.isObstacle()==true){
        if(elmt.isWall()==true){
            //return(61);
            return(55);
        }
        else{//Landscape
            
            //Cad d'un Stone Block
            if(elmt.getLandscapeType()==0){
                return(60/1.26);
            }
            
            else{
                return(86/1.26);
            }
            
        }
        
    }
    else{//Space
        if(elmt.getSpaceType()==5){
            return(40);
        }
        else if(elmt.getSpaceType()==6){
            return(400);
        }
        else{
          return(120/1.25);  
        }
        
    }
                
}


int const MapTileSet::getCellHeight(state::Element& elmt) const{
    if (elmt.isObstacle()==true){
        if(elmt.isWall()==true){
            //return(146);
            return(136);
        }
        else{//Landscape
            //Cad d'un Stone Block
            if(elmt.getLandscapeType()==0){
                return(55/1.26);
            }
            
            else{
                return(120/1.26);
            }
        }
    }
    else{//Space
        if(elmt.getSpaceType()==5){
            return(18);
        }
        else if(elmt.getSpaceType()==6){
            return(100);
        }
        else{
            return(60/1.25);
        }
    }
}


       
