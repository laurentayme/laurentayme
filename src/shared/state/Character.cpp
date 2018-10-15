//
//  Character.cpp
//  PLT_Project
//
//  Created by Valentin Laurent on 10/10/2018.
//  Copyright © 2018 Valentin Laurent. All rights reserved.
//

#include <stdio.h>
#include "state.h"
#include <iostream>

using namespace std;
using namespace state;

Character::Character (std::string Classname){
    characterClass=Classname;
    player= true;
    statut=1;
    direction=1;
    
//Attribution des stats en fonction de la classe choisie//
    
    //Classe Iop
    if (characterClass=="Iop"){
        pv=100;
        pa=3;
        pm=3;
        
        //Création de l'equipement initial
        Equipment* epee(new Equipment("Epée","main",5));
        equipment_List.push_back(epee);
        
        //Création des abilités adéquates
        Abilities* coup_epee(new Abilities("Coup d'Epée",4,1));
        abilities_List.push_back(coup_epee);
        
        Abilities* colere(new Abilities("Colère",3,1));
        abilities_List.push_back(colere);
        
        
        
    }
    else if (characterClass=="Sadida"){
        pv=110;
        pa=2;
        pm=4;
        
        //Création de l'equipement initial
        Equipment* baton(new Equipment("Bâton","main",4));
        equipment_List.push_back(baton);
                         
        //Création des abilités adéquates
        Abilities* coup_baton(new Abilities("Coup de bâton",2,2));
        abilities_List.push_back(coup_baton);
        
        Abilities* sortilege(new Abilities("Sortilège",4,2));
        abilities_List.push_back(sortilege);
    }
}

Character::~Character(){
    // Destruction des pointeurs vers Equipement
    for(int i=0;i<equipment_List.size();i++){
        delete equipment_List[i];
        equipment_List[i]=0; //Remise à 0 des pointeurs equipement.
    }
    
    // Destruction des pointeurs vers Abilite
    for(int i=0;i<abilities_List.size();i++){
        delete abilities_List[i];
        abilities_List[i]=0; //Remise à 0 des pointeurs equipement.
    }
    
}

void Character::addEquipment(string nom, string emplacement, int degats){
    Equipment *equipment(0);// Initialisation pointeur arme nulle.
    equipment = new Equipment(nom,emplacement,degats);
    equipment_List.push_back(equipment); // Ajout d'un equipement dans notre liste d'équipements
}

void Character::addEquipment(Equipment *equipement){
    if (equipement->getName()!=""){
        equipment_List.push_back(equipement);
    }
    else{
        cout<<"Aucun equipement ajouté."<<endl;
        //Destruction du pointeur vers equipement non valide
        delete equipement;
        equipement=0;
    }
}

void Character::removeEquipment(Equipment *equipment){
    for(int i=0;i<equipment_List.size();i++){
        if (equipment_List[i]->getName()==equipment->getName()){
            equipment_List.erase(equipment_List.begin()+i);
        }
    }
}

std::string const Character::getClass(){
    return(characterClass);
}

int const Character::getPV(){
    return(pv);
}

int const Character::getPA(){
    return(pa);
}

int const Character::getPM(){
    return(pm);
}

int const Character::getStatut(){
    return(statut);
}

int const Character::getDirection(){
    return(direction);
}

vector<Equipment*> const Character::getEquipmentList(){
    return(equipment_List);
}

vector<Abilities*> const Character::getAbilitiesList(){
    return(abilities_List);
}

bool const Character::isPlayer(){
    return(player);
}


//Inutile
/*void Character::setClass(string classe){
    characterClass=classe;
}*/

void Character::setPV(int life){
    pv=life;
}

void Character::setPA(int action){
    pa=action;
}

void Character::setPM(int move){
    pm=move;
}

void Character::setDirection(int dir){
    direction=dir;
}

void const Character::affiche_Classe(){
    cout<<"Je suis un "<<characterClass<<"."<<endl;
}

void const Character::affiche_Stats(){
    cout<<"Stats actuelles:"<<endl;
    cout<<"  "<<pv<<" PV"<<endl;
    cout<<"  "<<pm<<" PM"<<endl;
    cout<<"  "<<pa<<" PA"<<endl;
}

void const Character::affiche_EquipmentList(){
    cout<<"Equipement actuel:"<<endl;
    if (equipment_List.size()==0){
        cout<<"Aucun objet n'est équipé."<<endl;
    }
    else{
        for(int i=0;i<equipment_List.size();i++){
            cout<<"  ";
            equipment_List[i]->affiche_Weapon();
        }
    }
}

void const Character::affiche_AbilitiesList(){
    cout<<"Abilités actuelles:"<<endl;
    if (abilities_List.size()==0){
        cout<<"Aucune Abilité."<<endl;
    }
    else{
        for(int i=0;i<abilities_List.size();i++){
            cout<<"  ";
            cout<<abilities_List[i]->getName()<<endl;
        }
    }
}






