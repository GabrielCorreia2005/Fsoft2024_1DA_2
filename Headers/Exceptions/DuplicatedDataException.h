#ifndef HEADERS_EXCEPTIONS_DUPLICATEDDATAEXCEPTION_H_
#define HEADERS_EXCEPTIONS_DUPLICATEDDATAEXCEPTION_H_

#include <exception>
#include <string>

using namespace std;

class DuplicatedDataException : public std::exception {
private:
    string data; // Stores information about the duplicated data

public:
    DuplicatedDataException(string data);

    // Override what() for a descriptive error message
    const char* what() const noexcept override;
};

#endif /* HEADERS_EXCEPTIONS_DUPLICATEDDATAEXCEPTION_H_ */ 