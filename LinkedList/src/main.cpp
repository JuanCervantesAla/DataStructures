#include <iostream>
#include "song.cpp"
#include "list.cpp"
#include "menu.cpp"

using namespace std;

/*
Author: Cervantes Alatorre Juan José Emiliano
Date: 05/02/2023
Assigment: Actividad de Aprendizaje 03. La Lista, implementación estática

Descripcion:
El programa es capaz de implementar una lista para canciones
No esta necesariamente ordenada solo por la posicion de ingreso
Se pueden ingresar canciones
Se pueden eliminar canciones
Se pueden editar canciones
Puedes buscar una cancion en especifico
No puedes hacer operaciones sobre espacios que no tengan ya una cancion
Estructura del programa:
1°Se abstrae la clase Song con sus atributos y metodos(definicion e implementacion)
2°Se abstrae la clase Lis con sus atributos y metodos, implica el uso de un arreglo de objetos
3° Menu es el que utiliza las funciones tanto de lista como de cancion, primero obtiene informa
cion de la cancion para ingresar en una lista
4° Main solo se encarga de que este proceso se repita hasta que salga

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
