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

int Tile::getX() const {
    return (this->x);
}

void Tile::setX(int xi) {
    if(xi>=0){
        this->x=xi;
    }
    else{
        throw "Position Invalide !";
    }
    
}

int Tile::getY() const{
    return(this->y);
}

void Tile::setY(int yi) {
    if(yi>=0){
        this->y=yi;
    }
    else{
        throw "Position Invalide !";
    }
    
}

int Tile::getWidth() const{
    return(width);
}

void Tile::setWidth(int w) {
    if(w>=0){
        this->width=w;
    }
    else{
        throw "Largeur Invalide !";
    }
    
}

int Tile::getHeight() const{
    return(height);
}

void Tile::setHeight(int h) {
    if(h>=0){
        this->height=h;
    }
    else{
        throw "Longueur Invalide !";
    }
    
}
