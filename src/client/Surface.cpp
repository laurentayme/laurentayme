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
    texture.setSmooth(true);
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
        if(elmt_list[i]->getTypeId()==0){
 
            if (elmt_list[i]->isObstacle()==true){ //Affichage Obstacle

                if(elmt_list[i]->isWall()==true){
                    quad_ptr[3].position=sf::Vector2f((120/2.5)*(y-x)-tileSet.getCellWidth(*elmt_list[i])/2+650+120/2.5,(60/2.5)*(x+y)+40+60/2.5+0.1*tileSet.getCellHeight(*elmt_list[i]));
                    quad_ptr[2].position=sf::Vector2f((120/2.5)*(y-x)+tileSet.getCellWidth(*elmt_list[i])/2+650+120/2.5,(60/2.5)*(x+y)+40+60/2.5+0.1*tileSet.getCellHeight(*elmt_list[i]));
                    quad_ptr[1].position=sf::Vector2f((120/2.5)*(y-x)+tileSet.getCellWidth(*elmt_list[i])/2+650+120/2.5,(60/2.5)*(x+y)-tileSet.getCellHeight(*elmt_list[i])+40+60/2.5+0.1*tileSet.getCellHeight(*elmt_list[i]));
                    quad_ptr[0].position=sf::Vector2f((120/2.5)*(y-x)-tileSet.getCellWidth(*elmt_list[i])/2+650+120/2.5,(60/2.5)*(x+y)-tileSet.getCellHeight(*elmt_list[i])+40+60/2.5+0.1*tileSet.getCellHeight(*elmt_list[i]));
                }  
                else{
                    quad_ptr[3].position=sf::Vector2f((120/2.5)*(y-x)-tileSet.getCellWidth(*elmt_list[i])/2+650+149/2.5-0.25*tileSet.getCellWidth(*elmt_list[i]),(60/2.5)*(x+y)+40+60/2.5+0.20*tileSet.getCellHeight(*elmt_list[i]));
                    quad_ptr[2].position=sf::Vector2f((120/2.5)*(y-x)+tileSet.getCellWidth(*elmt_list[i])/2+650+149/2.5-0.25*tileSet.getCellWidth(*elmt_list[i]),(60/2.5)*(x+y)+40+60/2.5+0.20*tileSet.getCellHeight(*elmt_list[i]));
                    quad_ptr[1].position=sf::Vector2f((120/2.5)*(y-x)+tileSet.getCellWidth(*elmt_list[i])/2+650+149/2.5-0.25*tileSet.getCellWidth(*elmt_list[i]),(60/2.5)*(x+y)-tileSet.getCellHeight(*elmt_list[i])+40+60/2.5+0.20*tileSet.getCellHeight(*elmt_list[i]));
                    quad_ptr[0].position=sf::Vector2f((120/2.5)*(y-x)-tileSet.getCellWidth(*elmt_list[i])/2+650+149/2.5-0.25*tileSet.getCellWidth(*elmt_list[i]),(60/2.5)*(x+y)-tileSet.getCellHeight(*elmt_list[i])+40+60/2.5+0.20*tileSet.getCellHeight(*elmt_list[i]));

                }

            }    
            else{//Affichage Space

                //Surbrillance blanche
                if(elmt_list[i]->getTypeId()==0 and elmt_list[i]->getSpaceType()==5){
                    quad_ptr[0].position=sf::Vector2f(elmt_list[i]->getLoc_x(),elmt_list[i]->getLoc_y()-17);
                    quad_ptr[1].position=sf::Vector2f(elmt_list[i]->getLoc_x()+67,elmt_list[i]->getLoc_y()-17);
                    quad_ptr[2].position=sf::Vector2f(elmt_list[i]->getLoc_x()+67,elmt_list[i]->getLoc_y()+55-17);
                    quad_ptr[3].position=sf::Vector2f(elmt_list[i]->getLoc_x(),elmt_list[i]->getLoc_y()+55-17);


                }
                else if(elmt_list[i]->getTypeId()==0 and elmt_list[i]->getSpaceType()==6){
                    quad_ptr[0].position=sf::Vector2f(elmt_list[i]->getLoc_x(),elmt_list[i]->getLoc_y());
                    quad_ptr[1].position=sf::Vector2f(elmt_list[i]->getLoc_x()+232,elmt_list[i]->getLoc_y());
                    quad_ptr[2].position=sf::Vector2f(elmt_list[i]->getLoc_x()+232,elmt_list[i]->getLoc_y()+100);
                    quad_ptr[3].position=sf::Vector2f(elmt_list[i]->getLoc_x(),elmt_list[i]->getLoc_y()+100);


                }
                //Space "normaux"
                else{
                    quad_ptr[0].position=sf::Vector2f(650-((x-y))*tileSet.getCellWidth(*elmt_list[i])/2,((x+y))*tileSet.getCellHeight(*elmt_list[i])/2+40);
                    quad_ptr[1].position=sf::Vector2f(650-((x-y))*tileSet.getCellWidth(*elmt_list[i])/2+tileSet.getCellWidth(*elmt_list[i]),((x+y))*tileSet.getCellHeight(*elmt_list[i])/2+40);
                    quad_ptr[2].position=sf::Vector2f(650-((x-y))*tileSet.getCellWidth(*elmt_list[i])/2+tileSet.getCellWidth(*elmt_list[i]),((x+y))*tileSet.getCellHeight(*elmt_list[i])/2+40+tileSet.getCellHeight(*elmt_list[i]));
                    quad_ptr[3].position=sf::Vector2f(650-((x-y))*tileSet.getCellWidth(*elmt_list[i])/2,((x+y))*tileSet.getCellHeight(*elmt_list[i])/2+40+tileSet.getCellHeight(*elmt_list[i]));

                }
            }  
        }
        
        //Affichage de Characters
        else if (elmt_list[i]->getTypeId()==1){
           
            quad_ptr[0].position=sf::Vector2f((120/2.5)*(y-x)-tileSet.getCellWidth(*elmt_list[i])/2+650+120/2.5,(60/2.5)*(x+y)+40+60/2.5+0.1*tileSet.getCellHeight(*elmt_list[i]));
            quad_ptr[1].position=sf::Vector2f((120/2.5)*(y-x)+tileSet.getCellWidth(*elmt_list[i])/2+650+120/2.5,(60/2.5)*(x+y)+40+60/2.5+0.1*tileSet.getCellHeight(*elmt_list[i]));
            quad_ptr[2].position=sf::Vector2f((120/2.5)*(y-x)+tileSet.getCellWidth(*elmt_list[i])/2+650+120/2.5,(60/2.5)*(x+y)-tileSet.getCellHeight(*elmt_list[i])+40+60/2.5+0.1*tileSet.getCellHeight(*elmt_list[i]));
            quad_ptr[3].position=sf::Vector2f((120/2.5)*(y-x)-tileSet.getCellWidth(*elmt_list[i])/2+650+120/2.5,(60/2.5)*(x+y)-tileSet.getCellHeight(*elmt_list[i])+40+60/2.5+0.1*tileSet.getCellHeight(*elmt_list[i]));
            
        }
        
        //Affichage d'un Menu (Battle/Main)
        else if(elmt_list[i]->getTypeId()>=2){
            quad_ptr[0].position=sf::Vector2f(0,0);
            quad_ptr[1].position=sf::Vector2f(0+tileSet.getCellWidth(*elmt_list[i])-300,0);
            quad_ptr[2].position=sf::Vector2f(0+tileSet.getCellWidth(*elmt_list[i])-300,y+tileSet.getCellHeight(*elmt_list[i])-305);
            quad_ptr[3].position=sf::Vector2f(0,y+tileSet.getCellHeight(*elmt_list[i])-305);
            
        }
        /*else if(elmt_list[i]->getTypeId()==3){
            quad_ptr[0].position=sf::Vector2f(0,0);
            quad_ptr[1].position=sf::Vector2f(tileSet.getCellWidth(*elmt_list[i]),0);
            quad_ptr[2].position=sf::Vector2f(tileSet.getCellWidth(*elmt_list[i]),tileSet.getCellHeight(*elmt_list[i]));
            quad_ptr[3].position=sf::Vector2f(0,tileSet.getCellHeight(*elmt_list[i]));
        }*/
	
}

void Surface::setSpriteTexture(int i, const Tile& texture,const state::ElementTab& elmt_tab){
    sf::Vertex* quad_ptr = &quads[i*4];
    
    std::vector<state::Element*> elmt_list;
    elmt_list=elmt_tab.getElementList();
    
    //Affichage d'objets de Map
    if(elmt_list[i]->getTypeId()==0){
        
        quad_ptr[0].texCoords=sf::Vector2f(texture.getX(),texture.getY());
        quad_ptr[1].texCoords=sf::Vector2f(texture.getX()+texture.getWidth(),texture.getY());
        quad_ptr[2].texCoords=sf::Vector2f(texture.getX()+texture.getWidth(),texture.getY()+texture.getHeight());
        quad_ptr[3].texCoords=sf::Vector2f(texture.getX(),texture.getY()+texture.getHeight());

    }  
    
    //Découpage Character
    else if(elmt_list[i]->getTypeId()==1){
   
        quad_ptr[3].texCoords=sf::Vector2f(texture.getX(),texture.getY());
        quad_ptr[2].texCoords=sf::Vector2f(texture.getX()+texture.getWidth(),texture.getY());
        quad_ptr[1].texCoords=sf::Vector2f(texture.getX()+texture.getWidth(),texture.getY()+texture.getHeight());
        quad_ptr[0].texCoords=sf::Vector2f(texture.getX(),texture.getY()+texture.getHeight());

    } 
    
    //Affichage d'un Menu (Battle/Main)
    else if(elmt_list[i]->getTypeId()>=2){
        quad_ptr[0].texCoords=sf::Vector2f(texture.getX(),texture.getY());
        quad_ptr[1].texCoords=sf::Vector2f(texture.getX()+texture.getWidth(),texture.getY());
        quad_ptr[2].texCoords=sf::Vector2f(texture.getX()+texture.getWidth(),texture.getY()+texture.getHeight());
        quad_ptr[3].texCoords=sf::Vector2f(texture.getX(),texture.getHeight()+texture.getY());
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
