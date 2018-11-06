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

void Observable::addObserver(Observer* pobs ) {
	this->observers.push_back(pobs);

}

void Observable::removeObserver(Observer* pobs) {
	auto beginList = this->observers.vector::begin();
	auto endList = this->observers.vector::end();
	remove(beginList,endList,pobs);
	
}

void Observable::notify(Event& e){
	auto beginList = this->observers.begin();
	auto endList = this->observers.end();
	for ( auto it = beginList; it !=endList; ++it){
	(*it)->stateChanged(e);
	}
	
}

Observable::~Observable(){


}
	
