#include "../include/interpreter.hpp"
#include <string>

    //Copy Constructor, just passing parameters
    Interpreter::Interpreter(const Interpreter& i){
        lastName= i.lastName;
        firstName= i.firstName;

    }

    //Getter and setter
    std::string Interpreter::getFirstName() const{
        return firstName;
    }

    std::string Interpreter::getLastName() const{
        return lastName;
    }

    void Interpreter::setFirstName(const std::string& newFirstName){
        firstName=newFirstName;
    }
    void Interpreter::setLastName(const std::string& newLastName){
        lastName=newLastName;
    }

    //Method to String
    std::string Interpreter::toString() const{
        return firstName+" "+lastName;
    }


    ///Operator overload
    Interpreter& Interpreter::operator=(const Interpreter & i){

        if(this != &i){
            firstName= i.firstName;
            lastName= i.lastName;
        }
         return *this;

    }

    bool Interpreter::operator==(const Interpreter &i){
        return this->toString() == i.toString();
    }

    bool Interpreter::operator!=(const Interpreter &i){
        return !(*this==i);
    }

    bool Interpreter::operator<(const Interpreter &i){
        return this->toString() < i.toString();
    }

    bool Interpreter::operator<=(const Interpreter &i){
        return (*this < i) || (*this == i);
    }

    bool Interpreter::operator>(const Interpreter &i){
        return !(*this <= i);
    }

    bool Interpreter::operator>=(const Interpreter &i){
        return !(*this < i);
    }

