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

Surface::Surface(){
    quads.setPrimitiveType(sf::Quads);
}


void Surface::initQuads(int count){
    quads.resize(count*4);
}

void Surface::setSpriteTexture(int i, const Tile& texture){
    sf::Vertex* quad_ptr = &quads[i*4];
    quad_ptr[0].texCoords=sf::Vector2f(texture.getX(),texture.getY());
    /*quad_ptr[1].texCoords=sf::Vector2f(texture.getTilex()+texture.getTileWidth(),texture.getTiley());
    quad_ptr[2].texCoords=sf::Vector2f(texture.getTilex() +texture.getTileWidth(),texture.getTiley()+ texture.getTileHeight());
    quad_ptr[3].texCoords=sf::Vector2f(texture.getTilex(),texture.getTiley()+ texture.getTileHeight());

     */ }
