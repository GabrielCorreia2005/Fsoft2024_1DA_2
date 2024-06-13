/*
 * DataConsistencyException.cpp
 *
 *  Created on: 13/05/2024
 *      Author: gvice
 */

#include "DataConsistencyException.h"


DataConsistencyException::DataConsistencyException(string data){
    this->data = "Error: ["+ data + "] consistency!!";
}

const char* DataConsistencyException::what(){
    return this->data.c_str();
}