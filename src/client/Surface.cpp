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
        /*
        //Si Abscisse pair, alors position Tile "classique"
	if(int(x)%2==0){
    		quad_ptr[0].position=sf::Vector2f((x/2)*tileSet.getCellWidth()+tileSet.getCellWidth()/2+200,y*tileSet.getCellHeight()+50);
		quad_ptr[1].position=sf::Vector2f((x/2+1)*tileSet.getCellWidth()+200,y*tileSet.getCellHeight()+tileSet.getCellHeight()/2+50);
		quad_ptr[2].position=sf::Vector2f((x/2+1)*tileSet.getCellWidth()-tileSet.getCellWidth()/2+200,y*tileSet.getCellHeight()+tileSet.getCellHeight()+50);
		quad_ptr[3].position=sf::Vector2f((x/2)*tileSet.getCellWidth()+200,(y+1)*tileSet.getCellHeight()-tileSet.getCellHeight()/2+50);
	}
        //Sinon position du Tile décalé
	else if (y!=elmt_tab.getWidth()-1){
               
		quad_ptr[0].position = sf::Vector2f((x+1)/2 * tileSet.getCellWidth()+200, y * tileSet.getCellHeight()+tileSet.getCellHeight()/2+50);
		quad_ptr[1].position = sf::Vector2f(((x+1)/2 + 1) * tileSet.getCellWidth()-tileSet.getCellWidth()/2+200, (y+1) * tileSet.getCellHeight()+50);
		quad_ptr[2].position = sf::Vector2f((x+1)/2 * tileSet.getCellWidth()+200, (y + 1) * tileSet.getCellHeight()+tileSet.getCellHeight()/2+50);
		quad_ptr[3].position = sf::Vector2f((x+1)/2 * tileSet.getCellWidth()-tileSet.getCellWidth()/2+200, (y + 1) * tileSet.getCellHeight()+50);
			}
        
        }*/
            
        quad_ptr[0].position=sf::Vector2f(650-((x-y))*tileSet.getCellWidth()/2,((x+y))*tileSet.getCellHeight()/2+20);
	quad_ptr[1].position=sf::Vector2f(650-((x-y))*tileSet.getCellWidth()/2+tileSet.getCellWidth(),((x+y))*tileSet.getCellHeight()/2+20);
        quad_ptr[2].position=sf::Vector2f(650-((x-y))*tileSet.getCellWidth()/2+tileSet.getCellWidth(),((x+y))*tileSet.getCellHeight()/2+20+tileSet.getCellHeight());
        quad_ptr[3].position=sf::Vector2f(650-((x-y))*tileSet.getCellWidth()/2,((x+y))*tileSet.getCellHeight()/2+20+tileSet.getCellHeight());
            
        }
        
        //Affichage de Characters
        else if (elmt_list[0]->getTypeId()==1){
           
            /*
            if(y%2==0){
                y=y/2;

                quad_ptr[0].position=sf::Vector2f((149/1.25)*(y+1/2)-tileSet.getCellWidth()/2+200+149/2,(86/1.25)*(x+1/2)+50+86/2+0.1*tileSet.getCellHeight());
                quad_ptr[1].position=sf::Vector2f((149/1.25)*(y+1/2)+tileSet.getCellWidth()/2+200+149/2,(86/1.25)*(x+1/2)+50+86/2+0.1*tileSet.getCellHeight());
                quad_ptr[2].position=sf::Vector2f((149/1.25)*(y+1/2)+tileSet.getCellWidth()/2+200+149/2,(86/1.25)*(x+1/2)-tileSet.getCellHeight()+50+86/2+0.1*tileSet.getCellHeight());
                quad_ptr[3].position=sf::Vector2f((149/1.25)*(y+1/2)-tileSet.getCellWidth()/2+200+149/2,(86/1.25)*(x+1/2)-tileSet.getCellHeight()+50+86/2+0.1*tileSet.getCellHeight());
            }
            else{
                y=(y+1)/2;
                quad_ptr[0].position=sf::Vector2f((149/1.25)*(y)-tileSet.getCellWidth()/2+200,(86/1.25)*(x+1)+50+0.1*tileSet.getCellHeight());
                quad_ptr[1].position=sf::Vector2f((149/1.25)*(y+1/2)+tileSet.getCellWidth()/2+200,(86/1.25)*(x+1)+50+0.1*tileSet.getCellHeight());
                quad_ptr[2].position=sf::Vector2f((149/1.25)*(y+1/2)+tileSet.getCellWidth()/2+200,(86/1.25)*(x+1)-tileSet.getCellHeight()+50+0.1*tileSet.getCellHeight());
                quad_ptr[3].position=sf::Vector2f((149/1.25)*(y)-tileSet.getCellWidth()/2+200,(86/1.25)*(x+1)-tileSet.getCellHeight()+50+0.1*tileSet.getCellHeight());
            
                
            }
            */
            quad_ptr[0].position=sf::Vector2f((149/2.5)*(y-x)-tileSet.getCellWidth()/2+650+149/2.5,(86/2.5)*(x+y)+20+86/2.5+0.1*tileSet.getCellHeight());
            quad_ptr[1].position=sf::Vector2f((149/2.5)*(y-x)+tileSet.getCellWidth()/2+650+149/2.5,(86/2.5)*(x+y)+20+86/2.5+0.1*tileSet.getCellHeight());
            quad_ptr[2].position=sf::Vector2f((149/2.5)*(y-x)+tileSet.getCellWidth()/2+650+149/2.5,(86/2.5)*(x+y)-tileSet.getCellHeight()+20+86/2.5+0.1*tileSet.getCellHeight());
            quad_ptr[3].position=sf::Vector2f((149/2.5)*(y-x)-tileSet.getCellWidth()/2+650+149/2.5,(86/2.5)*(x+y)-tileSet.getCellHeight()+20+86/2.5+0.1*tileSet.getCellHeight());
            
        }
        
        //Affichage du menu d'état
        else if(elmt_list[0]->getTypeId()==2){
            quad_ptr[0].position=sf::Vector2f(0,0);
            quad_ptr[1].position=sf::Vector2f(0+tileSet.getCellWidth()-300,0);
            quad_ptr[2].position=sf::Vector2f(0+tileSet.getCellWidth()-300,y+tileSet.getCellHeight()-280);
            quad_ptr[3].position=sf::Vector2f(0,y+tileSet.getCellHeight()-280);
            
        }
	
}

void Surface::setSpriteTexture(int i, const Tile& texture,const state::ElementTab& elmt_tab){
    sf::Vertex* quad_ptr = &quads[i*4];
    
    std::vector<state::Element*> elmt_list;
    elmt_list=elmt_tab.getElementList();
    
    //Affichage d'objets de Map
    if(elmt_list[0]->getTypeId()==0){
   /*
    quad_ptr[0].texCoords=sf::Vector2f(texture.getX()+texture.getWidth()/2,texture.getY());
    quad_ptr[1].texCoords=sf::Vector2f(texture.getX()+texture.getWidth(),texture.getY()+ texture.getHeight()/2);
    quad_ptr[2].texCoords=sf::Vector2f(texture.getX()+texture.getWidth()-texture.getWidth()/2,texture.getY()+texture.getHeight());
    quad_ptr[3].texCoords=sf::Vector2f(texture.getX(),texture.getY()+texture.getHeight()-texture.getHeight()/2);
    */
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
