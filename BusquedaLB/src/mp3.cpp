#include "../include/mp3.hpp"
#include <string>

//Copy Constructor, just passing parameters
    MP3::MP3(const MP3& m){
        fileName = m.fileName;

    }

    //Getter and setter
    std::string MP3::getFileName() const{
        return fileName;
    }


    void MP3::setFileName(const std::string& newFileName){
        fileName=newFileName;
    }

    //Method to String
    std::string MP3::toString() const{
        return fileName;
    }


    ///Operator overload
    MP3& MP3::operator=(const MP3 & m){

        if(this != &m){
            fileName=m.fileName;
        }
         return *this;
        

    }

    bool MP3::operator==(const MP3 &m){
        return this->toString() == m.toString();
    }

    bool MP3::operator!=(const MP3 &m){
        return !(*this==m);
    }

    bool MP3::operator<(const MP3 &m){
        return this->toString() < m.toString();
    }

    bool MP3::operator<=(const MP3 &m){
        return (*this < m) || (*this == m);
    }

    bool MP3::operator>(const MP3 &a){
        return !(*this <= a);
    }

    bool MP3::operator>=(const MP3 &m){
        return !(*this < m);
    }