#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "state.h"
#include <vector>
#include <iterator>
#include <list>
#include <algorithm>



using namespace std;
using namespace state;




void Observable::addObserver(Observer* obs ) {
	observers.push_back(obs);
}

void Observable::addObserver(Observer& obs ) {
	observers.push_back(&obs);
}

void Observable::removeObserver(Observer* obs) {
	auto beginList = this->observers.vector::begin();
	auto endList = this->observers.vector::end();
	remove(beginList,endList,obs);
	
}

void Observable::notifyObservers(Event& e){
        //observers[1]->stateChanged(e);
        //cout<<"Entrer"<<endl;
        //cout<<"Nbre observers dans cet observable :"<<observers.size()<<endl;
	auto beginList = this->observers.begin();
	auto endList = this->observers.end();
	for ( auto it = beginList; it !=endList; ++it){
            //cout<<"Etat Changé 1 (e)"<<endl;
            (*it)->stateChanged(e);
            //cout<<"Etat Changé 2 (e)"<<endl;
        }
	
}

Observable::~Observable(){
}
	
