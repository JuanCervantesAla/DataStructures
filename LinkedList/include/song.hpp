#ifndef _SONG_HPP_
#define _SONG_HPP_

#include<string>

class Song{

    private:
    //Atributes 
    std::string title;
    std::string author;
    std::string interpreter;
    int ranking;

    public:
    //Getters, retrieving the info stored at this point
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getInterpreter() const;
    int getRanking() const;
    
    //Setters, providing info to the object
    void setTitle(const std::string&);
    void setAuthor(const std::string&);
    void setInterpreter(const std::string&);
    void setRanking(const int&);


};

#endif // _SONG_HPP_