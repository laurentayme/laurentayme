#include <iostream>
#include <stdio.h>
#include <string.h>

#include "state.h"

using namespace std;
using namespace state;

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
    
    Character iop("Iop");
    
    iop.affiche_Classe();
    
    iop.affiche_AbilitiesList();
  
    
    return 0;
}


