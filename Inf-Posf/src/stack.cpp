#include "../include/stack.hpp"
#include <iostream>


template<class T, int ArraySize>
Stack<T,ArraySize>::Stack():top(-1) {}


template<class T, int ArraySize>
Stack<T,ArraySize>::Stack(const Stack<T,ArraySize>&s)
{
    copyAll(s);
}


template<class T, int ArraySize>
bool Stack<T,ArraySize>::isEmpty()
{
    if(top==-1) return true;
    return false;
}


template<class T, int ArraySize>
bool Stack<T,ArraySize>::isFull()
{
    if(top==sizeof(arrayX)-1) return true;
    return false;
}


template<class T, int ArraySize>
void Stack<T,ArraySize>::push( const T& element)
{
    if(isFull())
    {
        throw errno ;
    }
    else
    {
        arrayX[++top]=element;
    }
}


template<class T, int ArraySize>
T Stack<T,ArraySize>::pop()
{
    if(isEmpty())
    {
        throw errno ;
    }
    else
    {
        return arrayX[top--];
    }
}


template<class T, int ArraySize>
T Stack<T,ArraySize>::topeek()
{
    if(isEmpty()) return 0;
    else
    {
        return arrayX[top];
    }
}


template<class T, int ArraySize>
void Stack<T,ArraySize>::copyAll(const Stack<T,ArraySize>& s)
{
    int counter(0);
    while (counter<=s.top)
    {
        this->arrayX[counter]=s.arrayX[counter];
        counter++;
    }

    this->top=s.top;
}

template<class T, int ArraySize>
Stack<T,ArraySize>& Stack<T,ArraySize>::operator=(const Stack<T, ArraySize> &s)
{
    copyAll(s);
    return *this;
}
