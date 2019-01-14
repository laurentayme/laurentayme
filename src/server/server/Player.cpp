/** 
 * @file User.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "server.h"

using namespace server;

Player::Player (std::string name, bool free){
    this->name=name;
    this->free=free;
}
