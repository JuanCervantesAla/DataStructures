#ifndef STACK_HPP
#define STACK_HPP
#include "../include/node.hpp"
#include "../include/exception.hpp"

template<class T>
class Stack{

    private:
        Node<T> *anchor;
        void copyAll(const Stack&);
        void deleteAll();

    public:
        Stack();
        Stack(const Stack&);
        ~Stack();
        bool isEmpty() const;
        void push(const T&);
        T pop();
        T getTop()const;

        Stack& operator=(const Stack&);

};

template<class T>
void Stack<T>::copyAll(const Stack& s){
    Node<T>* aux(s.anchor);
    Node<T>* last(nullptr);
    Node<T>* newNode;


    while (aux!=nullptr) {
        newNode = new Node<T>(aux->getData());

        if(last==nullptr){
            anchor=newNode;
        }
        else {
            newNode->setPrevious(last);
            last->setNext(newNode);
        }

        last=newNode;
        aux=aux->getNext();
    }
}

template<class T>
Stack<T>::Stack():anchor(nullptr){}

template<class T>
Stack<T>::Stack(const Stack& s):anchor(nullptr){
    copyAll(s);
}

template<class T>
Stack<T>::~Stack(){
    deleteAll();
}

template<class T>
bool Stack<T>::isEmpty() const {
    return anchor==nullptr;
}

template<class T>
void Stack<T>::push(const T &e){
    Node<T>* aux(new Node<T>(e));

    if(aux==nullptr){
        throw Exception("Not enough memory, push");
    }

    aux->setNext(anchor);
    anchor=aux;

}

template<class T>
void Stack<T>::deleteAll(){
    Node<T>* aux;

    while (anchor != nullptr) {
        aux= anchor;
        anchor=anchor->getNext();

        delete aux;
    }
}

template<class T>
T Stack<T>::pop(){

    if(anchor==nullptr){
        throw Exception("Not enough data, pop");
    }

    T result(anchor->getData());
    Node<T>* aux(anchor);

    anchor = anchor->getNext();
    delete aux;
    return result;

}



template<class T>
T Stack<T>::getTop() const{
    if(anchor==nullptr){
        throw Exception("Not enough data, getTop");
    }

    return anchor->getData();

}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack& s){
    deleteAll();
    copyAll(s);
    return *this;
}


#endif // !STACK_HPP

