#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "../include/node.hpp"
#include "../include/exception.hpp"


template<class T>
class Queue{

    private:
        Node<T> * header;

        void copyAll(const Queue<T>&);
        void deleteAll();

    public:
        Queue();
        Queue(const Queue&);
        ~Queue();

        bool isEmpty();
        void enqueue(const T&);
        T dequeue();
        T getFront();
        Queue& operator=(const Queue&);

};


template<class T>
void Queue<T>::copyAll(const Queue<T>& l){
    Node<T>* auxiliar(l.header->getNext());
    Node<T>* newNode;

    while (auxiliar != l.header) {
        try{
            if((newNode = new Node<T>(auxiliar->getData()))==nullptr){
                throw Exception("Not enough memory, copyAll");
            }
        }catch(Exception ex){
            throw Exception(ex.what());
        }

        newNode->setPrevious(header->getPrevious());
        newNode->setNext(header);

        header->getPrevious()->setNext(newNode);
        header->setPrevious(newNode);

        auxiliar=auxiliar->getNext();

    }

}

template<class T>
void Queue<T>::deleteAll(){
    Node<T> * auxiliar;
    while (header->getNext() != header) {
        auxiliar = header->getNext();
        header->setNext(auxiliar->getNext());
        delete auxiliar;
    }

    header->setPrevious(header);

}

template<class T>
Queue<T>::Queue(): header(new Node<T>){
    if(header == nullptr){
        throw Exception("Not enough memory, initialize queue");
    }

    header->setNext(header);
    header->setPrevious(header);

}

template<class T>
Queue<T>::Queue(const Queue& q):Queue(){
    copyAll(q);
}

template<class T>
Queue<T>::~Queue(){
    deleteAll();
    delete header;
}

template<class T>
bool Queue<T>::isEmpty(){
    return header->getNext()==header;
}

template<class T>
void Queue<T>::enqueue(const T & e){

    Node<T> * auxiliar;

    try{
        if((auxiliar= new Node<T>(e))==nullptr){
            throw Exception("Not enough memory, enqueue");
        }
    } catch(Exception ex){
        throw Exception(ex.what());
    }

    auxiliar->setPrevious(header);
    auxiliar->setNext(header);

    //->getPrevious()->setNext(auxiliar);
    header->getPrevious()->setNext(auxiliar);
    header->setPrevious(auxiliar); 

}

template<class T>
T Queue<T>::dequeue(){
    if(isEmpty()){
        throw Exception("Not enough data,deque");
    }

    T result(header->getNext()->getData());

    Node<T>* auxiliar(header->getNext());

    auxiliar->getPrevious()->setNext(auxiliar->getNext());
    auxiliar->getNext()->setPrevious(auxiliar->getPrevious());

    delete auxiliar;
    return result;

}

template<class T>
T Queue<T>::getFront(){

    if(isEmpty()){
        throw Exception("Not enough data, getFront");
    }

    return header->getNext()->getData();

}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue& q){
    deleteAll();
    copyAll(q);
    return *this;
}

#endif // !QUEUE_HPP
