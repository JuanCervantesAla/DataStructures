#ifndef _MENU_HPP_
#define _MENU_HPP_

#include "../include/integer.hpp"


class Menu{
    private:
    int option;

    public:
    int showMenu();
    void menuOnAction();
    void fillList();
    void copyList();

};


#endif // _MNU_HPP_