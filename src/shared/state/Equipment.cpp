//
//  Equipment.cpp
//  PLT_Project
//
//  Created by Valentin Laurent on 11/10/2018.
//  Copyright © 2018 Valentin Laurent. All rights reserved.
//

#include <stdio.h>
#include "state.h"
#include <iostream>

using namespace std;
using namespace state;

Equipment::Equipment(string name, string emplacement, size_t stats){
    // Vérification de l'emplacement
    if(emplacement=="main" || emplacement=="dos" || emplacement=="pied" || emplacement=="tete"){
        emplacement_equipment=emplacement;
        name_equipment=name;
        stats_equipment=stats;
    }
    else{
        cout<<"Veuillez rentrer un emplacement valide: 'main', 'dos', 'pied' ou 'tete'."<<endl;
    }
    
    
}

string const Equipment::getName(){
    return(name_equipment);
}

string const Equipment::getEmplacement(){
    return(emplacement_equipment);
}

size_t const Equipment::getStats(){
    return(stats_equipment);
}

void Equipment::affiche_Weapon(){
    cout<<name_equipment<<" (Degats: "<<stats_equipment<<" / Emplacement: "<<emplacement_equipment<<" )"<<endl;
}

