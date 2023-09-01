#ifndef _LIST_HPP_
#define _LIST_HPP_

#include <exception>
#include <iostream>
#include <string>
#include "song.hpp"

 class List{

    private:
    Song song[50];
    int last;

    public:
//Definition
    //Check memory on list;
    void initialize();
    bool isEmpty() const;
    bool isFull() const;
    bool isValidPosition(const int&) const;

    void insertNewElement(const Song&, const int&);
    void deleteElement(const int&);
    void editElement(const Song&, const int&);

    int getFirstPosition() const;
    int getLastPosition() const;
    int getNextPosition(const int&) const;
    int getPreviousPosition(const int&) const;

    int localizePosition(const int&);
    std::string getElement(const int&);

    std::string print() const;
    std::string print(const int& position)const;
    void deleteAll();

    List& operator= (const List&);

};

#endif // _LST_HPP_