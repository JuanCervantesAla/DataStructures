#include <iostream>
#include "song.cpp"
#include "../include/list.hpp"
#include "menu.cpp"

using namespace std;

/*
Author: Cervantes Alatorre Juan José Emiliano
Date: 18/02/2023
Assigment: Actividad de Aprendizaje 03. La Lista, implementación estática
*/

int main()
{
    Menu menu;
    int selectedOption;
    int exit=false;
    menu.initializeList();
    do
    {
        selectedOption=menu.showMenu();
        menu.setOption(selectedOption);
        exit=menu.menuOption(menu.getOption());
    }
    while(exit==false);

    return 0;
}
