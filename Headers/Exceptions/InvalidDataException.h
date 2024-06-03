#ifndef HEADERS_EXCEPTIONS_INVALIDDATAEXCEPTION_H_
#define HEADERS_EXCEPTIONS_INVALIDDATAEXCEPTION_H_

#include <exception>
#include <string>

using namespace std;

class InvalidDataException : public std::exception {
private:
    string data; // To store a description of the invalid data

public:
    InvalidDataException(string data);

    // Override what() for a descriptive error message
    const char* what() const noexcept override;
};

#endif /* HEADERS_EXCEPTIONS_INVALIDDATAEXCEPTION_H_ */