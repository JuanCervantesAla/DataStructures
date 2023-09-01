#ifndef NODE_HPP
#define NODE_HPP


template <class T>
class Node{

    private:
        T data;
        Node *next;
        Node *previous;

    public:
        Node();
        Node(const T&);

        T getData();
        Node* getNext();
        Node* getPrevious();

        void setData(const T&);
        void setNext(Node*);
        void setPrevious(Node*);


};

template <class T>
Node<T>::Node():next(nullptr),previous(nullptr){}

template <class T>
Node<T>::Node(const T& e):data(e),next(nullptr),previous(nullptr){}

template <class T>
T Node<T>::getData(){
    return data;

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
void Node<T>::setData(const T & e){
    data=e;
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