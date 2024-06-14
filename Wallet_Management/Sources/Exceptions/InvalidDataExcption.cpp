//
// Created by gvice on 13/05/2024.
//

#include "InvalidDataException.h"


InvalidDataException::InvalidDataException(string data){
    this->data = data;
}

const char* InvalidDataException::what(){
    string msg = "Error: ["+ data + "] is not valid!!";
    return msg.c_str();


}
