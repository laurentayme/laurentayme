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
#include <cstdlib>

using namespace std;
using namespace server;

void ServiceManager::registerService (unique_ptr<AbstractService> service) {
    //throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    this->services.push_back(std::move(service));  
}

AbstractService* ServiceManager::findService (const string& url) const {
    for (auto& service : services) {
        const string& pattern(service->getPattern());
        if (url.find(pattern) != 0)
            continue;
        if (url.size() > pattern.size() && url[pattern.size()] != '/')
            continue;
        return service.get();
    }
    return nullptr;
}

HttpStatus ServiceManager::queryService (string& out, const string& in, const string& url, const string& method) { 
    //throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    AbstractService* service = findService(url);
    if (!service)
        throw ServiceException(HttpStatus::NOT_FOUND,"Service "+url+" non trouvé");
    // Recherche un éventuel id (ex: /mon/service/<id>)
    const string& pattern(service->getPattern());
    int id = 0;
    if (url.size() > pattern.size()) {
        string end = url.substr(pattern.size());
        if (end[0] != '/')
            throw ServiceException(HttpStatus::BAD_REQUEST,"Url malformée (forme attendue: <service>/<nombre>)");
        end = end.substr(1);
        if (end.empty())
            throw ServiceException(HttpStatus::BAD_REQUEST,"Url malformée (forme attendue: <service>/<nombre>)");
        try {
            size_t pos = 0;
            id = stoi(end,&pos);
            if (pos != end.size())
                throw ServiceException(HttpStatus::BAD_REQUEST,"Url malformée: '"+end+"' n'est pas un nombre");
        }
        catch(...) {
            throw ServiceException(HttpStatus::BAD_REQUEST,"Url malformée: '"+end+"' n'est pas un nombre");
        }
    }
    // Traite les différentes méthodes
    if (method == "GET") {
        cerr << "Requête GET " << pattern << " avec id=" << id << endl;
        Json::Value jsonOut;
        HttpStatus status = service->get(jsonOut,id);
        out = jsonOut.toStyledString();
        return status;
    }
    else if (method == "POST") {
        cerr << "Requête POST " << pattern << " avec contenu: " << in << endl;
        Json::Reader jsonReader;
        Json::Value jsonIn;
        if (!jsonReader.parse(in,jsonIn))
            throw ServiceException(HttpStatus::BAD_REQUEST,"Données invalides: "+jsonReader.getFormattedErrorMessages());
        return service->post(jsonIn,id);
    }
    else if (method == "PUT") {
        cerr << "Requête PUT " << pattern << " avec contenu: " << in << endl;
        Json::Reader jsonReader;
        Json::Value jsonIn;
        if (!jsonReader.parse(in,jsonIn))
            throw ServiceException(HttpStatus::BAD_REQUEST,"Données invalides: "+jsonReader.getFormattedErrorMessages());
        Json::Value jsonOut;
        HttpStatus status = service->put(jsonOut,jsonIn);
        out = jsonOut.toStyledString();
        return status;
    }
    else if (method == "DELETE") {
        cerr << "Requête DELETE" << endl;
	Json::Value jsonOut;
        HttpStatus status = service->remove(jsonOut,id);
	out = jsonOut.toStyledString();
	return status;
    }
    throw ServiceException(HttpStatus::BAD_REQUEST,"Méthode "+method+" invalide");
}
/*   
    size_t i=20;
    string contenu;
    
    
    if(url.compare(0,10,"/version\0")==0){
        
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
    
    else if(url.compare(0,6,"/user/")==0){
        
        int id=-1;
        const char* char_url=url.c_str();
        for(size_t i=0;i<url.size();i++){
            if(isdigit((int)url[i])){
                id=atoi(char_url+i);
            }
        }
        
        if(method=="GET"){
            AbstractService* my_service;
            my_service=findService(url);
	    Json::Value json_out;
            HttpStatus status =my_service->get(json_out,id);
	    out=json_out.toStyledString();
            
            Json::Value object;
            my_service->get(object,id);
            out=object.toStyledString();

            throw ServiceException(HttpStatus::OK,out);
            
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
	    out=object.toStyledString();
            
            
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
            throw ServiceException(HttpStatus::OK,out);
        }
        
        
        
        
    }
    
    else{
        throw ServiceException(HttpStatus::BAD_REQUEST,"Bad URL !");
    }
    
    
        
}*/

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
