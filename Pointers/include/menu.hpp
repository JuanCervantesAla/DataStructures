#ifndef _MENU_HPP_
#define _MENU_HPP_
#include "song.hpp"

class Menu{

    private:
    int selectedOption;
    Song song;

    public:
    //Basic menu method
    int showMenu() const;
    int getOption() const;
    bool menuOption(const int&);
    void initializeList() const;

    //Getting x data
    void setOption(const int&);
    std::string dataToFind();
    int checkPosition() const;
    Song captureSongDetail() const;

    //For sorting
    void sortMenu(const int&);


    void searchOption(const int,const int&);

};


#endif // _MENU_HPP_