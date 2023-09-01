#include <iostream>
#include <ratio>
#include <string>
#include <system_error>
#include "../include/list.hpp"
#include "../include/integer.hpp"
#include "../src/integer.cpp"
#include "menu.cpp"
using namespace std;

int main(){
    Menu menu;
    menu.menuOnAction();
        
    return 0;
}
