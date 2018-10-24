//
//  Position.cpp
//  PLT_Project
//
//  Created by Valentin Laurent on 10/10/2018.
//  Copyright © 2018 Valentin Laurent. All rights reserved.
//

#include <stdio.h>
#include "state.h"

using namespace state;

//Constructeur
Position::Position(int abs, int ord){
    if(abs>=0 && ord>=0){
        x=abs;
        y=ord;
    }
    else{
        throw "Coordonnées Incorrectes !";
    }
    
}

//Affectation position X
void Position::setX(int abs){
	if(abs>=0){
		x=abs;
	}
	else{
		throw "Abscisse negative !";
	}
}

//Affectation position Y
void Position::setY(int ord){
	if(ord>=0){
		y=ord;
	}
	else{
		throw "Ordonnee negative !";
	}
}

size_t const Position::getX() const {
    return(x);
}

size_t const Position::getY() const {
    return(y);
}




