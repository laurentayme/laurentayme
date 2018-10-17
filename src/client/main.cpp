#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include<exception>
#include "state.h"

using namespace std;
using namespace state;

void TestsUnitaires(){

	try{
		Character* io=new Character("Io");
	}
	catch(const char* e){
		cout<<"Exception rencontree : "<<e<<endl;
	}



	Character* iop=new Character("Iop");

	try{
		iop->setPV(-3);
	}
	catch(const char* e){
		cout<<"Exception rencontree : "<<e<<endl;
	}
	
	cout<<"PV actuels : "<<iop->getPV()<<endl;

	try{
		iop->setPA(-1);
	}
	catch(const char* e){
		cout<<"Exception rencontree : "<<e<<endl;
	}
	cout<<"PA actuels : "<<iop->getPA()<<endl;
	try{
		iop->setPM(-2);
	}
	catch(const char* e){
		cout<<"Exception rencontree : "<<e<<endl;
	}
	cout<<"PM actuels : "<<iop->getPM()<<endl;

	try{
		iop->setDirection(6);
	}
	catch(const char* e){
		cout<<"Exception rencontree : "<<e<<endl;
	}
	Position pos;
	try{
		pos.setX(-1);
	}
	catch(const char* e){
		cout<<"Exception rencontree : "<<e<<endl;
	}
	
	try{
		pos.setY(-3);
	}
	catch(const char* e){
		cout<<"Exception rencontree : "<<e<<endl;
	}

	Position* pos1=new Position(-1,-3);

	try{
		iop->setPosition(*pos1);
	}
	catch(const char* e){
		cout<<"Exception rencontree : "<<e<<endl;
	}

	delete iop;
	delete pos1;



}



int main(int argc,char* argv[])
{
    string etat_jeu="Menu";
    string commande_user;
    
    /*cout << "It works !" << endl;*/
    if (argc>1){                 // vérifie s'il y a un argument
        if  (strcmp(argv[1],"hello")==0) {   // vérification que l'argument est le bon
            cout << "Bonjour le monde!" << endl;
        }
        else if (strcmp(argv[1],"state")==0){
            cout<<"Phase de Tests unitaires"<<endl;
   
            
           
        }
    }
    
 /*   Character* iop_ptr=new Character("Iop");
    vector<Element*> elementList;
    elementList.push_back(iop_ptr);
    
    
    ElementTab carte(1,2,elementList);

cout<<"largeur: "<<carte.getWidth()<<" longueur :"<<carte.getHeight()<<endl;
 	carte.resize(4,5);

cout<<"largeur: "<<carte.getWidth()<<" longueur :"<<carte.getHeight()<<endl;*/
    
    //iop.affiche_AbilitiesList();
  
    TestsUnitaires();
	

    return 0;
}




