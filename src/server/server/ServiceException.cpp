/** 
 * @file ServiceException.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */
#include <stdio.h>
#include "server.h"

using namespace std;
using namespace server;

ServiceException::ServiceException (HttpStatus status, string msg) 
    : status(status),msg(msg) {    
}

HttpStatus ServiceException::getStatus () const {
    return status;
}

const char* ServiceException::what () const {
    return msg.c_str();
}