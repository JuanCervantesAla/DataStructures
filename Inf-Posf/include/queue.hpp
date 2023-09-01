#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

template<class T, int ArraySize=1024>
class Queue
{
private:
    T arrayY[ArraySize];
    int front,final;
    void copyAll(const Queue<T,ArraySize>&);

public:
    Queue();
    Queue(const Queue<T,ArraySize>&);

    bool isEmpty();
    bool isFull();
    void enqueue(const T&);
    void dequeue();
    T tofront();

    Queue<T,ArraySize>& operator=(const Queue<T,ArraySize>&);




};

#endif // _QUEUE_HPP_
