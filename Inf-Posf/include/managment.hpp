#ifndef _MANAGMENT_HPP_
#define _MANAGMENT_HPP_

#include "../include/queue.hpp"
#include "../include/stack.hpp"

class Managment
{
private:
    char inChar;
    Queue<char,50>recievingQueue;
    Queue<char,50> sendingQueue;
    Stack<char,50> stack;

public:
    void toPos();
    Queue<char,50>& fromInf();
    bool characterValidation(const char&);
    int setHierarchy(const char&);
    void printQueue();

};

#endif // _MANAGMENT_HPP_
