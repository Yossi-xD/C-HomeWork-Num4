#ifndef MAGICALEXCEPTION_HPP
#define MAGICALEXCEPTION_HPP
using namespace std;
#include <exception>
#include <string>

class MagicalException : public exception {
private:
    string message;

public:
    explicit MagicalException(const string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif 

