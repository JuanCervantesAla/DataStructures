#ifndef _STACK_HPP_
#define _STACK_HPP_
#include <iostream>

template<class T, int ArraySize=1024>
class Stack
{
private:
    int top;
    T arrayX[1024];
    void copyAll(const Stack<T,ArraySize>&);
public:
    Stack();
    Stack(const Stack<T,ArraySize>&);

    bool isEmpty();
    bool isFull();
    void push(const  T&);
    T pop();
    T topeek();
    Stack<T,ArraySize>& operator=(const Stack<T,ArraySize>&);



};


#endif // _STACK_HPP_
