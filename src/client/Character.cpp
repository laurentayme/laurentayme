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
    if(Classname=="Iop" or Classname=="Sram"){
        this->characterClass=Classname;
        this->player= true;
        this->statut=1;
        this->direction=1;
        this->idType=1;
    

    //Attribution des stats en fonction de la classe choisie//

        //Classe Iop
        if (characterClass=="Iop"){
            pv=100;
            pa=4;
            pm=30;

            //Création de l'equipement initial
            Equipment* epee(new Equipment("Epée","main",5));
            equipment_List.push_back(epee);

            //Création des abilités adéquates
            Abilities* coup_epee(new Abilities("Coup d'Epée",20,2,3));
            AbilitiesList.push_back(coup_epee);

            Abilities* colere(new Abilities("Colère",3,1,5));
            AbilitiesList.push_back(colere);



        }
        else if (characterClass=="Sram"){
            pv=40;
<<<<<<< HEAD
            pa=2;
            pm=2;
||||||| merged common ancestors
            pa=2;
            pm=4;
=======
            pa=4;
            pm=4;
>>>>>>> 330fe8f9d28ecb1a90a2a1445243b9cac34a7a12

            //Création de l'equipement initial
            Equipment* baton(new Equipment("Bâton","main",4));
            equipment_List.push_back(baton);

            //Création des abilités adéquates
            Abilities* coup_baton(new Abilities("Coup de bâton",2,2,15));
            AbilitiesList.push_back(coup_baton);

            Abilities* sortilege(new Abilities("Sortilège",4,3,20));
            AbilitiesList.push_back(sortilege);
        }

    else{
        throw "Classe Incorrecte ! (Tapez 'Iop' ou 'Sram')";
    }
}
}

Character::~Character(){
    // Destruction des pointeurs vers Equipement
    delete[] &equipment_List;
    delete[] &AbilitiesList;
    
    
    // Destruction des pointeurs vers Abilite
    /*for(size_t i=0;i<AbilitiesList.size();i++){
        delete AbilitiesList[i];
        AbilitiesList[i]=0; //Remise à 0 des pointeurs equipement.
    }*/
    
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

std::string Character::getClass() const {
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

int Character::getStatut() const{
    return(statut);
}

size_t Character::getDirection() const {
    return(direction);
}

vector<Equipment*> const Character::getEquipmentList(){
    return(equipment_List);
}

vector<Abilities*> Character::getAbilitiesList() {
    return(AbilitiesList);
}

bool Character::isPlayer() const{
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

void Character::affiche_Stats() const{
    cout<<"Stats actuelles:"<<endl;
    cout<<"  "<<pv<<" PV"<<endl;
    cout<<"  "<<pm<<" PM"<<endl;
    cout<<"  "<<pa<<" PA"<<endl;
}

void Character::affiche_EquipmentList() const{
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

void Character::affiche_AbilitiesList() const{
    cout<<"Abilités actuelles:"<<endl;
    if (AbilitiesList.size()==0){
        cout<<"Aucune Abilité."<<endl;
    }
    else{
        for(size_t i=0;i<AbilitiesList.size();i++){
            cout<<"  ";
            cout<<AbilitiesList[i]->getName()<<endl;
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

void Character::afficheStatut() const{
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

bool Character::isObstacle() const {
    return(false);
}

bool Character::isWall() const {
    return(false);
}

size_t Character::getSpaceType() const {
	return 0;
}

int Character::getWallType() const{
    return 0;
}

int Character::getLandscapeType() const{
    return(-1);
}

size_t Character::getTypeId() const{
    return(idType);
}





