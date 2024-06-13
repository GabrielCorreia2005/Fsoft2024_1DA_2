//
// Created by gvice on 13/05/2024.
//


#ifndef HEADERS_EXCEPTIONS_DUPLICATEDDATAEXCEPTION_H_
#define HEADERS_EXCEPTIONS_DUPLICATEDDATAEXCEPTION_H_

#include <exception>
#include <string>
using namespace std;

class DuplicatedDataException :public exception{
private:
    string data;
public:
    DuplicatedDataException(string data);
    //override what function
    const char* what();
};


#endif /* HEADERS_EXCEPTIONS_DUPLICATEDDATAEXCEPTION_H_ */