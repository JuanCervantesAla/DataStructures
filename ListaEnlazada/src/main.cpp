#include <iostream>
#include <string>
#include "../include/list.hpp"
#include "../include/manager.hpp"

using namespace std;

int main(){
    Manager manager;
    List<Song> list;

    manager.menuOnAction(list);
    
    return 0;
}
