#ifndef _LIST_HPP_
#define _LIST_HPP_

#include <exception>
#include <iostream>
#include <string>
#include "song.hpp"


class ListException : public std::exception{

    private:
    std::string msg;

    public:
    ListException() noexcept: msg("Undefined error"){}
    ListException( const ListException & ex) noexcept: msg(ex.msg){}
    ListException(const std::string& m) : msg(m){}
    ListException& operator=( const ListException& ex) noexcept{
        msg=ex.msg;
    return *this;
    }
    virtual ~ListException(){}
     
    virtual const char* what() const noexcept{
        return msg.c_str();
    }

};


 class List{

    private:
    Song song[3000];
    int last;

    public:
//Definition
    //Check memory on list;
    void initialize();
    bool isEmpty() const;
    bool isFull() const;
    bool isValidPosition(const int&) const;

    //MainFunctions on list
    void insertNewElement(const Song&, const int&);
    void deleteElement(const int&);
    void editElement(const Song&, const int&);

    //Positions on list
    int getFirstPosition() const;
    int getLastPosition() const;
    int getNextPosition(const int&) const;
    int getPreviousPosition(const int&) const;

    //Localize elements
    int localizePosition(const int&);
    std::string getElement(const int&);
    int findDataLinear(const Song&);
    int findDataBinary(const Song&);
    

    //Printing methods
    std::string print() const;
    std::string print(const int& position)const;
    std::string printMp3(const int& position) const;

    //Sorting methods
    void swapData(const int&, const int& );
    void bubbleSort();
    void shellSort();
    void insertSort();
    void selectionSort();

    void deleteAll();

    List& operator= (const List&);

};

#endif // _LST_HPP_