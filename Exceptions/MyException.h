#pragma once
#include <string>
using namespace std;
class MyException : public std::exception
{
private:
    string message;
public:
    MyException(string mes) :message(mes) {}
};

