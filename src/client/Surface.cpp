/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include "state.h"
#include "render.h"
#include <SFML/Graphics.hpp>

using namespace render;

void Surface::initQuads(int count){
    quads.setPrimitiveType(sf::Quads);
    quads.resize(count*4);
}

void Surface::loadTexture(const std::string& image_file){
    if(!texture.loadFromFile(image_file)){
        throw "Loading File Error !";
    };
}

void Surface::setSpriteLocation(int i, int x, int y,TileSet& tileSet,  const state::ElementTab& elmt_tab) {
    	sf::Vertex* quad_ptr = &quads[i*4];
        
        std::vector<state::Element*> elmt_list;
        elmt_list=elmt_tab.getElementList();
        
        
        //Affichage d'objets de Map
        if(elmt_list[0]->getTypeId()==0){
 
        if (elmt_list[i]->isObstacle()==true){ //Affichage Obstacle
            
            if(elmt_list[i]->isWall()==true){
                quad_ptr[3].position=sf::Vector2f((149/2.5)*(y-x)-tileSet.getCellWidth(*elmt_list[i])/2+650+149/2.5,(75/2.5)*(x+y)+40+75/2.5+0.1*tileSet.getCellHeight(*elmt_list[i]));
                quad_ptr[2].position=sf::Vector2f((149/2.5)*(y-x)+tileSet.getCellWidth(*elmt_list[i])/2+650+149/2.5,(75/2.5)*(x+y)+40+75/2.5+0.1*tileSet.getCellHeight(*elmt_list[i]));
                quad_ptr[1].position=sf::Vector2f((149/2.5)*(y-x)+tileSet.getCellWidth(*elmt_list[i])/2+650+149/2.5,(75/2.5)*(x+y)-tileSet.getCellHeight(*elmt_list[i])+40+75/2.5+0.1*tileSet.getCellHeight(*elmt_list[i]));
                quad_ptr[0].position=sf::Vector2f((149/2.5)*(y-x)-tileSet.getCellWidth(*elmt_list[i])/2+650+149/2.5,(75/2.5)*(x+y)-tileSet.getCellHeight(*elmt_list[i])+40+75/2.5+0.1*tileSet.getCellHeight(*elmt_list[i]));
            }  
            else{
                quad_ptr[3].position=sf::Vector2f((149/2.5)*(y-x)-tileSet.getCellWidth(*elmt_list[i])/2+650+149/2.5,(75/2.5)*(x+y)+40+75/2.5+0.25*tileSet.getCellHeight(*elmt_list[i]));
                quad_ptr[2].position=sf::Vector2f((149/2.5)*(y-x)+tileSet.getCellWidth(*elmt_list[i])/2+650+149/2.5,(75/2.5)*(x+y)+40+75/2.5+0.25*tileSet.getCellHeight(*elmt_list[i]));
                quad_ptr[1].position=sf::Vector2f((149/2.5)*(y-x)+tileSet.getCellWidth(*elmt_list[i])/2+650+149/2.5,(75/2.5)*(x+y)-tileSet.getCellHeight(*elmt_list[i])+40+75/2.5+0.25*tileSet.getCellHeight(*elmt_list[i]));
                quad_ptr[0].position=sf::Vector2f((149/2.5)*(y-x)-tileSet.getCellWidth(*elmt_list[i])/2+650+149/2.5,(75/2.5)*(x+y)-tileSet.getCellHeight(*elmt_list[i])+40+75/2.5+0.25*tileSet.getCellHeight(*elmt_list[i]));
            
            
            }
            
        }    
        else{ //Affichage Space
        quad_ptr[0].position=sf::Vector2f(650-((x-y))*tileSet.getCellWidth(*elmt_list[i])/2,((x+y))*tileSet.getCellHeight(*elmt_list[i])/2+40);
	quad_ptr[1].position=sf::Vector2f(650-((x-y))*tileSet.getCellWidth(*elmt_list[i])/2+tileSet.getCellWidth(*elmt_list[i]),((x+y))*tileSet.getCellHeight(*elmt_list[i])/2+40);
        quad_ptr[2].position=sf::Vector2f(650-((x-y))*tileSet.getCellWidth(*elmt_list[i])/2+tileSet.getCellWidth(*elmt_list[i]),((x+y))*tileSet.getCellHeight(*elmt_list[i])/2+40+tileSet.getCellHeight(*elmt_list[i]));
        quad_ptr[3].position=sf::Vector2f(650-((x-y))*tileSet.getCellWidth(*elmt_list[i])/2,((x+y))*tileSet.getCellHeight(*elmt_list[i])/2+40+tileSet.getCellHeight(*elmt_list[i]));
        }  
        }
        
        //Affichage de Characters
        else if (elmt_list[0]->getTypeId()==1){
           
            quad_ptr[0].position=sf::Vector2f((149/2.5)*(y-x)-tileSet.getCellWidth(*elmt_list[i])/2+650+149/2.5,(75/2.5)*(x+y)+40+75/2.5+0.1*tileSet.getCellHeight(*elmt_list[i]));
            quad_ptr[1].position=sf::Vector2f((149/2.5)*(y-x)+tileSet.getCellWidth(*elmt_list[i])/2+650+149/2.5,(75/2.5)*(x+y)+40+75/2.5+0.1*tileSet.getCellHeight(*elmt_list[i]));
            quad_ptr[2].position=sf::Vector2f((149/2.5)*(y-x)+tileSet.getCellWidth(*elmt_list[i])/2+650+149/2.5,(75/2.5)*(x+y)-tileSet.getCellHeight(*elmt_list[i])+40+75/2.5+0.1*tileSet.getCellHeight(*elmt_list[i]));
            quad_ptr[3].position=sf::Vector2f((149/2.5)*(y-x)-tileSet.getCellWidth(*elmt_list[i])/2+650+149/2.5,(75/2.5)*(x+y)-tileSet.getCellHeight(*elmt_list[i])+40+75/2.5+0.1*tileSet.getCellHeight(*elmt_list[i]));
            
        }
        
        //Affichage du menu d'état
        else if(elmt_list[0]->getTypeId()==2){
            quad_ptr[0].position=sf::Vector2f(0,0);
            quad_ptr[1].position=sf::Vector2f(0+tileSet.getCellWidth(*elmt_list[i])-300,0);
            quad_ptr[2].position=sf::Vector2f(0+tileSet.getCellWidth(*elmt_list[i])-300,y+tileSet.getCellHeight(*elmt_list[i])-280);
            quad_ptr[3].position=sf::Vector2f(0,y+tileSet.getCellHeight(*elmt_list[i])-280);
            
        }
	
}

void Surface::setSpriteTexture(int i, const Tile& texture,const state::ElementTab& elmt_tab){
    sf::Vertex* quad_ptr = &quads[i*4];
    
    std::vector<state::Element*> elmt_list;
    elmt_list=elmt_tab.getElementList();
    
    //Affichage d'objets de Map
    if(elmt_list[0]->getTypeId()==0){
        
    quad_ptr[0].texCoords=sf::Vector2f(texture.getX(),texture.getY());
    quad_ptr[1].texCoords=sf::Vector2f(texture.getX()+texture.getWidth(),texture.getY());
    quad_ptr[2].texCoords=sf::Vector2f(texture.getX()+texture.getWidth(),texture.getY()+texture.getHeight());
    quad_ptr[3].texCoords=sf::Vector2f(texture.getX(),texture.getY()+texture.getHeight());
    
    }  
    
    //Découpage Character
    else if(elmt_list[0]->getTypeId()==1){
   
    quad_ptr[3].texCoords=sf::Vector2f(texture.getX(),texture.getY());
    quad_ptr[2].texCoords=sf::Vector2f(texture.getX()+texture.getWidth(),texture.getY());
    quad_ptr[1].texCoords=sf::Vector2f(texture.getX()+texture.getWidth(),texture.getY()+texture.getHeight());
    quad_ptr[0].texCoords=sf::Vector2f(texture.getX(),texture.getY()+texture.getHeight());
    } 
    
    //Affichage du menu d'état
    else if(elmt_list[0]->getTypeId()==2){
    quad_ptr[0].texCoords=sf::Vector2f(0,0);
    quad_ptr[1].texCoords=sf::Vector2f(texture.getWidth(),0);
    quad_ptr[2].texCoords=sf::Vector2f(texture.getWidth(),texture.getHeight());
    quad_ptr[3].texCoords=sf::Vector2f(0,texture.getHeight());
    } 

}

void Surface::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    
    // On applique la transformation
    states.transform *= getTransform();

    // On applique la texture du tileset
    states.texture = &texture;

    // Et on dessine enfin le tableau de vertex
    target.draw(quads, states);
}

const sf::Texture Surface::getTexture() const{
   // const sf::Texture& t=texture;
    return(texture);
}

const sf::VertexArray Surface::getQuads() const{
    const sf::VertexArray& s=quads;
    return(s);
}
