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
    return !(*this <= s);
}

bool Song::operator>=(const Song &s) const{
    return !(*this < s);
}