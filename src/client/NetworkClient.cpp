#include <stdio.h>
#include "state.h"
#include "engine.h"
#include "client.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

using namespace client;

NetworkClient::NetworkClient(std::string url, int port, int character) : url(url),port(port),character(character){


}

std::string NetworkClient::getGameStatus() const {


}

bool NetworkClient::getServerCommands(Json::Value& out) const {
	
}

void NetworkClient::putServerCommand(engine::Command* command){

}

void NetworkClient::run() {

}

