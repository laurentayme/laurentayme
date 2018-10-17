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

Abilities::Abilities(std::string const name,size_t const  degats,size_t const Class_owner){
    name_ability=name;
    degats_ability=degats;
    classOwner_ability=Class_owner;
}

Abilities::~Abilities(){
    
}


std::string const Abilities::getName(){
    return(name_ability);
}

size_t const Abilities::getDegats(){
    return(degats_ability);
}

size_t const Abilities::getClassOwner(){
    return(classOwner_ability);
}

void const Abilities::afficheStats(){
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
    
    
    
}









