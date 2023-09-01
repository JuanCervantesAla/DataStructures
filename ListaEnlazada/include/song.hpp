#ifndef _SONG_HPP_
#define _SONG_HPP_

#include "../include/author.hpp"
#include "../include/interpreter.hpp"
#include "../include/mp3.hpp"
#include<string>

class Song{

    private:
    //Atributes 

    Author author;
    Interpreter interpreter;
    MP3 mp3;

    std::string title;
    int ranking;

    public:
    //Getters, retrieving the info stored at this point
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getInterpreter() const;
    Interpreter& getInterpreterO();
    std::string getFileName() const;
    int getRanking() const;
    
    //Setters, providing info to the object
    void setTitle(const std::string&);
    void setAuthor(const Author&);
    void setInterpreter(const Interpreter&);
    void setFileName(const MP3&);
    void setRanking(const int&);

    std::string toString() const;

    //Song& operator=(const Song&);
    bool operator==(const Song&) const;
    bool operator<(const Song&) const;
    bool operator<=(const Song&) const;
    bool operator>(const Song& ) const;
    bool operator>=(const Song&) const;
    bool operator!=(const Song&) const;


};

#endif // _SONG_HPP_