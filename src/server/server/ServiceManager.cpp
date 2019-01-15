/** 
 * @file ServicesManager.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */



#include <stdio.h>
#include <iostream>
#include "server.h"
#include <fstream>
#include "json/json.h"
#include <microhttpd.h>
#include <string.h>
#include <sstream>
#include <memory>

using namespace std;
using namespace server;

void ServiceManager::registerService (unique_ptr<AbstractService> service) {
    //throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    this->services.push_back(std::move(service));  
}

AbstractService* ServiceManager::findService (const string& url) const {
    //throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    
    for(size_t i=0; i<services.size();i++){
        if(services[i]->getPattern()=="/version" or services[i]->getPattern()=="version/suite" or services[i]->getPattern()=="version/23"){
            return(services[i].get());
        }
        else{
            return(nullptr);
        }
    }
      
}

HttpStatus ServiceManager::queryService (string& out, const string& in, const string& url, const string& method) { 
    //throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");

   
    size_t i=20;
    string contenu;
    
    
    if(url.compare(0,8,"/version")==0){
        
        AbstractService* my_service;
        my_service=findService(url);

        if(my_service!=nullptr){
            
            Json::Value json_out;
            if(method=="GET"){
                my_service->get(json_out, 0);
                out=json_out.toStyledString();
                throw ServiceException(HttpStatus::OK,out);
            }
            else{
                throw ServiceException(HttpStatus::BAD_REQUEST," Bad Method !");
            }    
        }
        else{
            throw ServiceException(HttpStatus::NOT_FOUND," Service not found !");
        }
        
    }
    
    else if(url.compare(0,5,"/user")==0){
        int id;
        if(stoi(url)){
            id=stoi(url);
        }
        else{
            id=0;
        }
        
        if(method=="GET"){
            
            AbstractService* my_service;
            my_service=findService(url);
            
            
            Json::Value object;
            throw ServiceException(my_service->get(object,id),out);
            
        }
        
        else if(method=="POST"){
            AbstractService* my_service;
            my_service=findService(url);
            
                    
            //Parsing de l'argument IN//
            bool alive = true;
            Json::Value root;   // will contains the root value after parsing.
            Json::Reader reader;
            const char* c_str = in.c_str();
            std::ifstream test(c_str, std::ifstream::binary);
            bool parsingSuccessful = reader.parse(test, root, false );
            if ( !parsingSuccessful )
                {
                // report to the user the failure and their locations in the document.
                std::cout<<reader.getFormatedErrorMessages()
                    << "\n";
            }
            //////////////////////////////
            
            my_service->post(root,id);
            Json::Value object;
            my_service->get(object,id);
            
            
            if(root.isMember("name") and !root.isMember("free")){
               if(object["name"]==root["name"]){
                   throw ServiceException(HttpStatus::OK,out);
                } 
               else{
                   throw ServiceException(HttpStatus::SERVER_ERROR,"POST query didn't work !");
               }
            }
            else if (root.isMember("free") and !root.isMember("name")){
               if(object["free"]==root["free"] ){
                   throw ServiceException(HttpStatus::OK,out);
                } 
               else{
                   throw ServiceException(HttpStatus::SERVER_ERROR,"POST query didn't work !");
               }
            }
            else if(root.isMember("free") and root.isMember("name")){
                if(object["free"]==root["free"] and object["name"]==root["name"] ){
                    throw ServiceException(HttpStatus::OK,out);
                }
                else{
                   throw ServiceException(HttpStatus::SERVER_ERROR,"POST query didn't work !");
               }
            }
            else{
                throw ServiceException(HttpStatus::BAD_REQUEST,"Invalid Post Query !");
            }
            
            
            
            
        }
        
        
        else if (method=="PUT"){
            
            AbstractService* my_service;
            my_service=findService(url);
            
            //Parsing de l'argument IN//
            bool alive = true;
            Json::Value root;   // will contains the root value after parsing.
            Json::Reader reader;
            const char* c_str = in.c_str();
            std::ifstream test(c_str, std::ifstream::binary);
            bool parsingSuccessful = reader.parse(test, root, false );
            if ( !parsingSuccessful )
                {
                // report to the user the failure and their locations in the document.
                std::cout<<reader.getFormatedErrorMessages()
                    << "\n";
            }
            //////////////////////////////
            
            Json::Value out;
            
            if(root.isMember("name")){
                my_service->put(out,root);
                throw ServiceException(HttpStatus::OK,out.toStyledString());
            }
            
            else{
                throw ServiceException(HttpStatus::BAD_REQUEST,"Invalid PUT Query !");
            }
            
            
        }
        else if(method=="DELETE"){
            AbstractService* my_service;
            my_service=findService(url);
            
            throw ServiceException(my_service->remove(id),out);
        }
        
        else{
            return(HttpStatus::BAD_REQUEST);
        }
        
        
        
        
    }
    
    else{
        throw ServiceException(HttpStatus::BAD_REQUEST,"Bad URL !");
    }
    
    
        
}

/*std::ifstream file("version.json");
        if(!file){  
            std::cout << "File opening failed\n";
            std::ofstream myfile;
            myfile.open("version.json",std::ofstream::out | std::ofstream::app);
            myfile<<"[{"<<"\n";
            myfile<<"major: "<<"1"<<", \n";
            myfile<<"minor: "<<"0"<<", \n";
            myfile<<"}]";
            file.close();  
    }*/
