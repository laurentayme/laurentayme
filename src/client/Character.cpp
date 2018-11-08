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
<<<<<<< HEAD
    idType=1;
=======
	
>>>>>>> 24322c451e3febec2eed7127804da9dfd2fdc41a
    
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
        Abilities* coup_epee(new Abilities("Coup d'Epée",4));
        abilities_List.push_back(coup_epee);
        
        Abilities* colere(new Abilities("Colère",3));
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
        Abilities* coup_baton(new Abilities("Coup de bâton",2));
        abilities_List.push_back(coup_baton);
        
        Abilities* sortilege(new Abilities("Sortilège",4));
        abilities_List.push_back(sortilege);
    }
    
    else{
        throw "Classe Incorrecte ! (Tapez 'Iop' ou 'Sadida')";
    }
}

Character::~Character(){
    // Destruction des pointeurs vers Equipement
    for(size_t i=0;i<equipment_List.size();i++){
        delete equipment_List[i];
        equipment_List[i]=0; //Remise à 0 des pointeurs equipement.
    }
    
    // Destruction des pointeurs vers Abilite
    for(size_t i=0;i<abilities_List.size();i++){
        delete abilities_List[i];
        abilities_List[i]=0; //Remise à 0 des pointeurs equipement.
    }
    
}

void Character::addEquipment(string nom, string emplacement, size_t degats){
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
    for(size_t i=0;i<equipment_List.size();i++){
        if (equipment_List[i]->getName()==equipment->getName()){
            equipment_List.erase(equipment_List.begin()+i);
        }
    }
}

std::string const Character::getClass() const {
    return(characterClass);
}

size_t Character::getPV() const {
    return(pv);
}

size_t Character::getPA() const {
    return(pa);
}

size_t Character::getPM()  const {
    return(pm);
}

size_t const Character::getStatut(){
    return(statut);
}

size_t const Character::getDirection() const {
    return(direction);
}

vector<Equipment*> const Character::getEquipmentList(){
    return(equipment_List);
}

vector<Abilities*> Character::getAbilitiesList() const {
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
    if(life>=0){
        pv=life;
        
        if (pv==0){
            setStatut(3);
        }
        
    }
    else{
        pv=0;
        throw "PV ne peuvent être négatifs !";
    }
    
}

void Character::setPA(int action){
    if(action>=0){
        pa=action;
    }
    else{
        throw "PA ne peuvent être négatifs !";
    }
}

void Character::setPM(int move){
    if(move>=0){
        pm=move;
    }
    else{
        throw "PM ne peuvent être négatifs !";
    }
}

void Character::setDirection(size_t dir){
    if( dir >=1 && dir <=4 ){
        direction=dir;
    }
    else{
        throw "Direction Incorrecte !";
    }
    
}

void Character::affiche_Classe(){
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
        for(size_t i=0;i<equipment_List.size();i++){
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
        for(size_t i=0;i<abilities_List.size();i++){
            cout<<"  ";
            cout<<abilities_List[i]->getName()<<endl;
        }
    }
}

void Character::setStatut(int act_statut){
    if(act_statut>=1 && act_statut<=3){
        statut=act_statut;
    }
    else{
        throw "Statut incorrect !";
    }
}

void const Character::afficheStatut(){
    if(statut==1){
        cout<<"Votre personnage est en état 'normal'."<<endl;
    }
    else if(statut==2){
        cout<<"Votre personnage est en état 'empoisonné'."<<endl;
    }
    else{
        cout<<"Votre personnage est en état 'mort'."<<endl;
    }
}

bool const Character::isObstacle() const {
    return(false);
}

bool const Character::isWall() const {
    return(false);
}

size_t const Character::getSpaceType() const {
	return 0;
}

int Character::getWallType() const{
    return 0;
}

int Character::getLandscapeType() const{
    return(-1);
}



