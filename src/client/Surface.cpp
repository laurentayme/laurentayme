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

void Surface::setSpriteLocation(int i, int x, int y,sf::Vector2u tileSize){
    sf::Vertex* quad_ptr = &quads[i*4];

    	quad_ptr[0].position=sf::Vector2f(x+tileSize.x/2,y);
	quad_ptr[1].position=sf::Vector2f(x,y+tileSize.y/2);
	quad_ptr[2].position=sf::Vector2f(x+tileSize.x/2,y+tileSize.y);
	quad_ptr[3].position=sf::Vector2f(x+tileSize.x,y+tileSize.y/2);
	
}

void Surface::setSpriteTexture(int i, const Tile& texture){
    sf::Vertex* quad_ptr = &quads[i*4];
    quad_ptr[0].texCoords=sf::Vector2f(texture.getX()+texture.getHeight()/2,texture.getY());
    quad_ptr[1].texCoords=sf::Vector2f(texture.getX(),texture.getY()+texture.getWidth()/2);
    quad_ptr[2].texCoords=sf::Vector2f(texture.getX()+texture.getHeight()/2,texture.getY()+ texture.getWidth());
    quad_ptr[3].texCoords=sf::Vector2f(texture.getX()+texture.getHeight(),texture.getY()+ texture.getWidth()/2);
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
