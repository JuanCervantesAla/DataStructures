#include "../include/author.hpp"
#include <string>

    //Copy Constructor, just passing parameters
    Author::Author(const Author& a){
        lastName= a.lastName;
        firstName= a.firstName;

    }

    //Getter and setter
    std::string Author::getFirstName() const{
        return firstName;
    }

    std::string Author::getLastName() const{
        return lastName;
    }

    void Author::setFirstName(const std::string& newFirstName){
        firstName=newFirstName;
    }
    void Author::setLastName(const std::string& newLastName){
        lastName=newLastName;
    }

    //Method to String
    std::string Author::toString() const{
        return firstName+" "+lastName;
    }


    ///Operator overload
    Author& Author::operator=(const Author & a){

        if(this != &a){
            firstName= a.firstName;
            lastName= a.lastName;
        }
         return *this;

    }

    bool Author::operator==(const Author &a){
        return this->toString() == a.toString();
    }

    bool Author::operator!=(const Author &a){
        return !(*this==a);
    }

    bool Author::operator<(const Author &a){
        return this->toString() < a.toString();
    }

    bool Author::operator<=(const Author &a){
        return (*this < a) || (*this == a);
    }

    bool Author::operator>(const Author &a){
        return !(*this <= a);
    }

    bool Author::operator>=(const Author &a){
        return !(*this < a);
    }