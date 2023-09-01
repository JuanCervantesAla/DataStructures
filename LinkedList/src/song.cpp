#include "../include/song.hpp"

//GETTER
std::string Song::getTitle() const{
    return title;
}

std::string Song::getAuthor() const{
    return author;
}

std::string Song::getInterpreter() const{
    return interpreter;
}

int Song::getRanking() const{
    return ranking;
}


//SETTER
void Song::setTitle(const std::string & newTitle){
    title=newTitle;
}

void Song::setAuthor(const std::string & newAuthor){
    author=newAuthor;
}

void Song::setInterpreter(const std::string & newInterpreter){
    interpreter=newInterpreter;
}

void Song::setRanking(const int &newRanking){
    ranking=newRanking;
}