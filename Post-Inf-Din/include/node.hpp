#ifndef NODE_HPP
#define NODE_HPP
#include "../include/exception.hpp"


template <class T>
class Node{

    private:
        T* data;
        Node *next;
        Node *previous;

    public:
        Node();
        Node(const T&);
        ~Node();

        T* getDataPtr() const;
        T getData();
        Node* getNext();
        Node* getPrevious();

        void setDataPtr(T*);
        void setData(const T&);
        void setNext(Node*);
        void setPrevious(Node*);


};

template <class T>
Node<T>::Node():data(nullptr),next(nullptr),previous(nullptr){}

template <class T>
Node<T>::Node(const T& e):data(new T(e)),next(nullptr),previous(nullptr){

    if(data==nullptr){
        throw Exception("Not enough memory, creating node");
    }

}

template<class T>
Node<T>::~Node(){
    delete data;
}

template <class T>
T* Node<T>::getDataPtr()const{
    return data;

}

template <class T>
T Node<T>::getData(){
    if(data==nullptr){
        throw Exception("Not existing data, getData");
    }

    return *data;

}


template <class T>
Node<T>* Node<T>::getNext(){
    return next;
} 

template <class T>
Node<T>* Node<T>::getPrevious(){
    return previous;
} 

template <class T>
void Node<T>::setDataPtr(T*p){
    data=p;
}

template <class T>
void Node<T>::setData(const T & e){
    if(data==nullptr){
        if((data = new T(e))==nullptr){
            throw Exception("Not enough memory, setData");
        }
    }
    else{
        *data=e;
    }
}

template <class T>
void Node<T>::setNext(Node<T> *p){
    next=p;
}

template <class T>
void Node<T>::setPrevious(Node<T> *p){
    previous=p;
}

#endif // NODE_HPP