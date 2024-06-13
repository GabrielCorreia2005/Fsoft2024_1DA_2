//
// Created by gvice on 13/05/2024.
//

#include "DuplicatedDataException.h"


DuplicatedDataException::DuplicatedDataException(string data){
    this->data = "Error: ["+ data + "] duplicated!!";
}

const char* DuplicatedDataException::what(){
    return this->data.c_str();
}
