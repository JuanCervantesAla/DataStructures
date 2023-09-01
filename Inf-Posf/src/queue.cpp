#include "../include/queue.hpp"
#include <errno.h>
#include <float.h>
#include <iostream>

template<class T, int ArraySize>
Queue<T,ArraySize>::Queue():front(0),final(ArraySize-1) {}


template<class T, int ArraySize>
bool Queue<T,ArraySize>::isEmpty()
{
    return front==final+1 or (front==0 and final==ArraySize-1);
}


template<class T, int ArraySize>
bool Queue<T,ArraySize>::isFull()
{
    if((front==final+2)||(front==0 && final==ArraySize-2)||(front==1 && final==ArraySize-1)) return true;
    return false;
}


template<class T, int ArraySize>
void Queue<T,ArraySize>::enqueue(const T& element)
{
    if(isFull())
    {
        throw errno ;
    }
    if(++final==ArraySize)
    {
        final=0;
    }
    arrayY[final]=element;
}

template<class T, int ArraySize>
void Queue<T,ArraySize>::dequeue()
{
    if(isEmpty())
    {
        throw errno ;
    }
    else
    {
        front++;
        if(front==ArraySize) front=0;
    }
}

template<class T, int ArraySize>
T Queue<T,ArraySize>::tofront()
{
    if(isEmpty())
    {
        throw errno ;
    }
    return arrayY[front];
}

template<class T, int ArraySize>
void Queue<T,ArraySize>::copyAll(const Queue<T,ArraySize> &q)
{

    if(q.front==q.final)
    {
        this->arrayY[q.front]=q.arrayY[q.front];
    }

    if(q.front<q.final)
    {
        int counter1(q.front);
        while (counter1<=q.final)
        {
            this->arrayY[counter1]=q.arrayY[counter1];
            counter1++;
        }
    }

    if(q.final<q.front)
    {
        int counter2(q.front);
        int counter3(0);

        while (counter2<=ArraySize)
        {
            this->arrayY[counter2]=q.arrayY[counter2];
            counter2++;
        }
        while (counter3<=q.final)
        {
            this->arrayY[counter3]=q.arrayY[counter3];
            counter3++;
        }

    }

    this->final=q.final;
    this->front=q.front;

}

template<class T, int ArraySize>
Queue<T,ArraySize>& Queue<T,ArraySize>::operator=(const Queue<T,ArraySize>&q)
{
    copyAll(q);
    return *this;
}
