#include "../include/song.hpp"
#include "author.cpp"
#include "interpreter.cpp"
#include "mp3.cpp"
#include <string>

//GETTER
std::string Song::getTitle() const{
    return title;
}

std::string Song::getAuthor() const{
    return author.toString();
}

std::string Song::getInterpreter() const{
    return interpreter.toString();
}

Interpreter& Song::getInterpreterO(){
    return interpreter;
}


std::string Song::getFileName() const{
    return mp3.toString();
}

int Song::getRanking() const{
    return ranking;
}


//SETTER
void Song::setTitle(const std::string & newTitle){
    title=newTitle;
}

void Song::setAuthor(const Author& newAuthor){
    author=newAuthor;
}

void Song::setInterpreter(const Interpreter& newInterpreter){
    interpreter=newInterpreter;
}


void Song::setFileName(const MP3 & newFileName){
    mp3=newFileName;
}

void Song::setRanking(const int &newRanking){
    ranking=newRanking;
}

std::string Song::toString() const{
    return author.getFirstName()+author.getLastName()+interpreter.getFirstName()+interpreter.getLastName()+title+std::to_string(ranking);
}

//Operator overload
/*
Song& Song::operator=(const Song& s){

    if(this != &s){
        this->toString()=s.toString();
    }
    return *this;

}*/

bool Song::operator==(const Song &s) const{
    return (this->title==s.title)or(this->interpreter.toString()==s.interpreter.toString());
}

bool Song::operator!=(const Song &s) const{
    return !(*this==s);
}

bool Song::operator<(const Song &s) const{
    return this->toString() < s.toString();
}

bool Song::operator<=(const Song &s) const{
    return (*this < s) || (*this == s);
}

bool Song::operator>(const Song &s) const{

    int otherTitle,thisTitle,stringPosition(0);
    int thisInterpreter,otherInterpreter;

    /**Casting to ascii
    Gets the first char of tittle(0), then cast to int
    **/
    otherTitle = (int)s.getTitle().at(stringPosition);
    thisTitle = (int)this->getTitle().at(stringPosition);

    while(thisTitle==otherTitle){

        stringPosition++;
        otherTitle = (int)s.getTitle().at(stringPosition);
        thisTitle = (int)this->getTitle().at(stringPosition);

    }

    stringPosition=0;
    thisInterpreter = (int)this->getInterpreter().at(stringPosition);
    otherInterpreter = (int)s.getInterpreter().at(stringPosition);

    while (thisInterpreter==otherInterpreter) {

        stringPosition++;
        thisInterpreter = (int)this->getInterpreter().at(stringPosition);
        otherInterpreter = (int)s.getInterpreter().at(stringPosition);

    }

    return thisTitle>otherTitle or thisInterpreter>otherInterpreter;

}

bool Song::operator>=(const Song &s) const{
    return !(*this < s);
}