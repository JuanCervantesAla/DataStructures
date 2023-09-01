#ifndef _MENU_HPP_
#define _MENU_HPP_
#include "song.hpp"

class Menu{

    private:
    int selectedOption;
    Song song;

    public:
    int showMenu() const;
    void setOption(const int&);
    int getOption() const;
    bool menuOption(const int&);
    void initializeList() const;
    int checkPosition() const;
    Song captureSongDetail() const;

};


#endif // _MENU_HPP_