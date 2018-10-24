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
    texture.loadFromFile(image_file);
}

void Surface::setSpriteLocation(int i, int x, int y,TileSet& tileSet){
    	sf::Vertex* quad_ptr = &quads[i*4];
	if(x%2==0){
    		quad_ptr[0].position=sf::Vector2f(x*tileSet.getCellWidth()+tileSet.getCellWidth()/2,y*tileSet.getCellHeight());
		quad_ptr[1].position=sf::Vector2f(x*tileSet.getCellWidth(),y*tileSet.getCellHeight()+tileSet.getCellHeight()/2);
		quad_ptr[2].position=sf::Vector2f(x*tileSet.getCellWidth()+tileSet.getCellWidth()/2,y*tileSet.getCellHeight()+tileSet.getCellHeight());
		quad_ptr[3].position=sf::Vector2f(x*tileSet.getCellWidth()+tileSet.getCellWidth(),y*tileSet.getCellHeight()+tileSet.getCellHeight()/2);
	}

	else{
               
		quad_ptr[0].position = sf::Vector2f((x+1)/2 * tileSet.getCellWidth(), y * tileSet.getCellHeight()+tileSet.getCellHeight()/2);
		quad_ptr[1].position = sf::Vector2f(((x+1)/2 + 1) * tileSet.getCellWidth()-tileSet.getCellWidth()/2, (y+1) * tileSet.getCellHeight());
		quad_ptr[2].position = sf::Vector2f((x+1)/2 * tileSet.getCellWidth(), (y + 1) * tileSet.getCellHeight()+tileSet.getCellHeight()/2);
		quad_ptr[3].position = sf::Vector2f((x+1)/2 * tileSet.getCellWidth()-tileSet.getCellWidth()/2, (y + 1) * tileSet.getCellHeight());
		
     
                        
                    
			}
	
}

void Surface::setSpriteTexture(int i, const Tile& texture){
    sf::Vertex* quad_ptr = &quads[i*4];
    quad_ptr[0].texCoords=sf::Vector2f(texture.getX()+texture.getWidth()/2,texture.getY());
    quad_ptr[1].texCoords=sf::Vector2f(texture.getX()+texture.getWidth(),texture.getY()+ texture.getHeight()/2);
    quad_ptr[2].texCoords=sf::Vector2f(texture.getX()+texture.getWidth()-texture.getWidth()/2,texture.getY()+texture.getHeight());
    quad_ptr[3].texCoords=sf::Vector2f(texture.getX(),texture.getY()+texture.getHeight()-texture.getHeight()/2);
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
