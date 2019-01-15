/** 
 * @file UserDB.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */
#include <stdio.h>
#include "server.h"

using namespace server;

Game::Game(){ 
}

server::Player Game::getPlayer (int id) const {
    for(size_t i=0; i<players.size(); i++){
        if(i==id){
            return(players[i]);
        }
    }
    throw (HttpStatus::NOT_FOUND,"Incorrect Player id !");

}

void Game::addPlayer (Player player) {
    players.push_back(player);
}

void Game::setPlayer (int id, Player player) {
    for(size_t i=id; i<players.size()+1;i++){
        players[i+1]=players[i];
    }
    players[id] = player;
}

void Game::removePlayer (int id) {
    for(size_t i=0; i<players.size();i++){
        if(id-1==i){
            players.erase(players.begin()+i);
        }
    }
}

std::vector<Player> Game::getPlayers()const {
    return players;
}

