//
//  Abilities.cpp
//  PLT_Project
//
//  Created by Valentin Laurent on 14/10/2018.
//  Copyright © 2018 Valentin Laurent. All rights reserved.
//

#include <stdio.h>
#include "state.h"
#include <iostream>

using namespace std;
using namespace state;

Abilities::Abilities(std::string const name,int const  degats, int nb_pa){
    
    if(degats>=0){
        name_ability=name;
        degats_ability=degats;
        this->nb_pa=nb_pa;
    }
    else{
        throw "Degats Abilité Incorrects !";
    }
    
    
}

Abilities::~Abilities(){
    
}


std::string Abilities::getName() const{
    return(name_ability);
}

size_t Abilities::getDegats() const {
    return(degats_ability);
}

size_t Abilities::getnb_pa() const{
    return(nb_pa);
}

/*void Abilities::afficheStats() const{
    cout<<"Nom de compétence: "<<name_ability<<endl;
    cout<<"Dégats: "<<degats_ability<<endl;
    
    switch (classOwner_ability){
    
        case(1):cout<<"Classe propriétaire: Iop"<<endl;
            break;
        case(2):cout<<"Classe propriétaire: Sadida"<<endl;
            break;
        case(3):cout<<"Classe propriétaire: Sram"<<endl;
            break;
    }
    
    
    
}*/









