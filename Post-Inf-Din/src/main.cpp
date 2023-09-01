#include <iostream>
#include <iterator>
#include <ostream>
#include "../include/manager.hpp"
#include "../include/queue.hpp"

using namespace std;

int main(){

    Manager man;
    man.printQueue(man.toPos());

}
