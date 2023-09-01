#ifndef LIST_HPP
#define LIST_HPP
#include "../include/node.hpp"
#include "../include/exception.hpp"
#include <stdlib.h>
#include <string>

template<class T>
class List{

    private:
    Node<T>* anchor;

    void copyAll(const List<T>&);
    bool isValidPos(Node<T>*) const;

    public:
    typedef Node<T>* Position;

    List();
    List(const List<T>&);

    ~List();

    bool isEmpty() const;

    void insertData(Node<T>* , const T&);
    void deleteData(Node<T>*);

    Node<T>* getFirstPos() const;
    Node<T>* getLastPos() const;
    Node<T>* getPreviousPos(Node<T>*) const ;
    Node<T>* getNextPos(Node<T>*) const;

    Node<T>* findData(const T&) const;

    T retrieve(Node<T>*) const;

    std::string toString() const;

    void deleteAll();

    List<T>& operator= (const List<T>&);

};


////////////////////////
//Implementation
template<class T>
void List<T>::copyAll(const List<T>& l){

    Node<T>* aux(l.anchor);
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
bool List<T>::isValidPos(Node<T> * p) const {

    Node<T>* aux(anchor);
    while (aux!=nullptr) {
        if(aux==p){
            return true;
        }

        aux=aux->getNext();

    }

    return false;

}

//Initialize the list
template<class T>
List<T>::List(): anchor(nullptr){}


//Initialize the list with copy all
template<class T>
List<T>::List(const List<T>&l):anchor(nullptr){
    copyAll(l);
}


//Delete(free memory)
template<class T>
List<T>::~List(){
    deleteAll();
}

template<class T>
bool List<T>::isEmpty() const{
    return anchor==nullptr;
}

template<class T>
void List<T>::insertData(Node<T>*p, const T& e ){

    

    if(p!= nullptr and !isValidPos(p)){
        throw Exception("Invalid Pos, insertData");
    }

    Node<T>* aux(new Node<T>(e));

    if(aux==nullptr){
        throw Exception("No memory available, insertDara");
    }

    if(p==nullptr){

        //aux->setPrevious(nullptr);
        aux->setNext(anchor);

        if(anchor!=nullptr){
            anchor->setPrevious(aux);
        }

        anchor=aux;


    }

    else{

        aux->setPrevious(p);
        aux->setNext(p->getNext());

        if(p->getNext()!=nullptr){
            p->getNext()->setPrevious(aux);
        }

        p->setNext(aux);

    }

}

template<class T>
void List<T>::deleteData(Node<T> *p){

    if(!isValidPos(p)){
        throw Exception("Invalid pos, deleteData");
    }

    if(isEmpty() or p==nullptr){
        throw Exception("Not possible to delete, deleteData");
    }

    if(p->getPrevious()!=nullptr){
        p->getPrevious()->setNext(p->getNext());
    }

    if(p->getNext() != nullptr){
        p->getNext()->setPrevious(p->getPrevious());
    }

    if(p==anchor){
        anchor= anchor->getNext();
    }

    delete p;

}


//Returns first, so basically anchor is always first
template<class T>
Node<T>* List<T>::getFirstPos() const{
    return anchor;
}

template<class T>
Node<T>* List<T>::getLastPos() const{
    //If it is empty no last pos
    if(isEmpty()){
        return nullptr;
    }

    Node<T>* aux(anchor);

    //Getting the position till is equal to the requiered
    while (aux->getNext() !=nullptr) {
        //Getting the next 
        aux=aux->getNext();
    }

    return aux;

}

template<class T>
Node<T>* List<T>::getPreviousPos(Node<T>* p) const {

    //If p = nullptr means there no prev pos
    if(p==nullptr){
        return nullptr;
    }

    return p->getPrevious();

}


template<class T>
Node<T>* List<T>::getNextPos(Node<T> *p) const{

    if(!isValidPos(p)){
        return nullptr;
    }

    return p->getNext();

}


template<class T>
Node<T>* List<T>::findData(const T & e) const{
    Node<T>* aux(anchor);

    while (aux!=nullptr and aux->getData()!=e) {
        aux = aux->getNext();
    }

    return aux;

}

template<class T>
T List<T>::retrieve(Node<T> *p) const{

    if (!isValidPos(p)) {
        throw Exception("Invalid pos, retrieve");
    }

    return p->getData();

}

template<class T>
std::string List<T>::toString() const{
    Node<T>* aux(anchor);
    std::string result;


    while (aux!= nullptr) {
        result+=aux->getData().toString()+"| \n";
        aux=aux->getNext();
    }
    return result;

}

template<class T>
void List<T>::deleteAll(){
    Node<T>* aux;

    while (anchor != nullptr) {
        aux= anchor;
        anchor=anchor->getNext();

        delete aux;
    }
}

template<class T>
List<T>& List<T>::operator=(const List<T> &l){
    deleteAll();
    copyAll(l);
    return *this;
}


#endif // LIST_HPP