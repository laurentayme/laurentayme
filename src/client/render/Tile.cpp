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

Tile::Tile(int abs, int ord, int width, int height){
    x=abs;
    y=ord;
    this->width=width;
    this->height=height;
}

int Tile::getX(){
    return (this->x);
}

int Tile::getY() const{
    return(this->y);
}