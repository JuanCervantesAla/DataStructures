#ifndef NODE_HPP
#define NODE_HPP


template <class T>
class Node{

    public:
        typedef  Node<T>* Position;

    private:
        T data;
        Node *left;
        Node *right;

    public:
        Node();
        Node(const T&);

        T getData();
        Node*& getLeft();
        Node*& getRight();

        void setData(const T&);
        void setLeft(Node*);
        void setRight(Node*);


};

template <class T>
Node<T>::Node():left(nullptr),right(nullptr){}

template <class T>
Node<T>::Node(const T& e):data(e),left(nullptr),right(nullptr){}

template <class T>
T Node<T>::getData(){
    return data;

}

template <class T>
typename Node<T>::Position& Node<T>::getLeft(){
    return left;
} 

template <class T>
typename Node<T>::Position& Node<T>::getRight(){
    return right;
} 

template <class T>
void Node<T>::setData(const T & e){
    data=e;
}

template <class T>
void Node<T>::setLeft(Node<T> *p){
    left=p;
}

template <class T>
void Node<T>::setRight(Node<T> *p){
    right=p;
}

#endif // NODE_HPP