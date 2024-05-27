/*
 * DataConsistencyException.cpp
 *
 *  Created on: 13/05/2024
 *      Author: gvice
 */

#include "DataConsistencyException.h"

DataConsistencyException::DataConsistencyException(const string &data) : data(data) {}

const char *DataConsistencyException::what() {
    return data.c_str();
}