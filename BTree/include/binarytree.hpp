#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include "../include/node.hpp"
#include "../include/exception.hpp"
#include <ostream>

template <class T>
class BinaryTree{

    public:
        typedef  Node<T>* Position;

    private:
        Position root;

        //Position& copyAll(Position);

        void insert(Position&,T);
        void remove(Position&,T);

        Position& localize(Position&, const T&);

        Position& lowest(Position&);
        Position& highest(Position&);

        void preOrder(Position);
        int* inOrder(Position,int*,int);
        void postOrder(Position);


    public:

        BinaryTree();
        BinaryTree(BinaryTree<T>&);
        ~BinaryTree();
        Position& copyAll(Position);
        void deleteAll(Position);

        void initialize();

        Position& getRoot();
        bool isEmpty() const;
        bool isLeaf(Position&) const ;
        

        void insert(T);
        void remove(const T&);

        T retrieve(Position&)const;
        Position& localize(const T&);

        Position& lowest();
        Position& highest();

        void preOrder();
        int* inOrder(int);
        void postOrder();
        

        int height();

        int height(Position&);

        BinaryTree<T>& operator =(const BinaryTree<T>& );

};


////////Basic Functions of every object////
template <class T>
BinaryTree<T>::BinaryTree():root(nullptr){}//Basic constructor

template <class T>
BinaryTree<T>::BinaryTree(BinaryTree<T>& tree){//Copy constructor using copyAll
    root = copyAll(tree.getRoot());
    std::cout<<root->getData();
}

template <class T>
BinaryTree<T>::~BinaryTree(){
    deleteAll(root);
}

template <class T>
typename BinaryTree<T>::Position& BinaryTree<T>::copyAll(Position rootP){//Copy All 

    if(rootP==nullptr){

        return rootP;
        
    }
    
    Node<T>* aux = new Node<T>(rootP->getData());

    aux->setRight( copyAll(rootP->getRight()));
    aux->setLeft( copyAll(rootP->getLeft()));

    return aux;

}

template<class T>
void BinaryTree<T>::deleteAll(Position newRoot){

    if (newRoot == nullptr) {
        return;
    }

    //We need to delete from the bottom to the top
    //Every time it get lowe and lower form both right and left side
    deleteAll(newRoot->getLeft());
    deleteAll(newRoot->getRight());
    delete newRoot;
    return;

    //WARNING, THIS DELETES ALL OF THE ROOT INCLUDING THE MAIN ROOT THAT MEANS WE NEED TO INITIALIZE AGAIN THE TREE OR THE ROOT TO NULLPTR
}

template<class T>
void BinaryTree<T>::initialize(){
    root=nullptr;
}


/////States of The tree/////////////
template <class T>
typename BinaryTree<T>::Position& BinaryTree<T>::getRoot(){//GETS THE MAIN ROOT

    return root;

}


template <class T>
bool BinaryTree<T>::isEmpty() const{//Checks if the tree is empty

    return root==nullptr;

}

/////BASIC IN AND OUT FUNCTIONS OF BINARY TREE/////
template <class T>
void BinaryTree<T>::insert(T element){//Insert element, then gets the root and calls the recursive insert function

    return insert(root,element);

}

template <class T>
void BinaryTree<T>::insert(Position& newRoot,T element){
    
    //If its the main root, insert the element
    if(newRoot == nullptr){

        /*Creates an auxiliar node, in the auxliar node into the newRoot, using recursive insertion
        if it ends on a left or right nullptr its gonna be inserted on the node */
        Node<T>* aux(new Node<T>(element));
        newRoot = aux;

        //In case of failure, throw an exception
        if(aux==nullptr){
            throw Exception("Problem on memory, insert");
        }

    //This means its not a leaf node, so we need to keep going down using binary division
    }else{

        //If its minor than the root its going to be on the left side
        if(element<newRoot->getData()){

            insert(newRoot->getLeft(),element);    

        //Else on the right side
        }else{
            insert(newRoot->getRight(),element);
        }
    }

    return;

}

template <class T>
void BinaryTree<T>::remove(const T& element){//Gets the root of the element, and calls the recursive function remove

    return remove(localize(element),element);

}

template <class T>
void BinaryTree<T>::remove(Position& newRoot,T element){//Removes the element recursively


    if(newRoot == nullptr){//Verify if the root is empty, this indicates 2 cases: tree is empty or we reached the end of a root, next of a leaf

        return;

    }

    //If the element on the ACTUAL NODE is equals to the element
    if(newRoot->getData()==element){

        //Creates an auxliary node
        Node<T>* aux(new Node<T>);
        aux=newRoot;

        
        if(isLeaf(newRoot)){//If it's a leaf just set the node(leaf) to nullptr
            newRoot = nullptr;
            return;
        }

        //If the node just have the right child
        if(newRoot->getLeft()==nullptr){
            //Set the actual node the right, just switches positions
            newRoot= newRoot->getRight();
            return;
        }

        //Same as above but the other way
        if(newRoot->getRight()==nullptr){
            newRoot= newRoot->getLeft();
            
        }

        //If the Node has BOTH CHILDREN
        if(newRoot->getRight()!=nullptr && newRoot->getLeft()!=nullptr){
            
            aux = newRoot->getRight();//The right node set on auxiliary cause its gonna be lost

            newRoot= newRoot->getLeft();//The left child takes the place of actual node

            newRoot->getRight()=aux;//Set the left child(whom now its the actual root) the right children saved in aux
            
            return;
        }

        delete aux;//Free auxiliar
        return;

    }else{

        Node<T>* replace(highest(newRoot->getLeft()));//Replace the node
        remove(replace, newRoot->getLeft()->getData());
        return;
    }

}


template <class T>
T BinaryTree<T>::retrieve(Position& position) const{//Retrieve the element based on a position

    //If the root is empty, no tree
    //Or position has nothing on it, exception
    if( root==nullptr || position==nullptr ){
        throw Exception("Invalid position or it does not exist, retrieve");
    }

    //Return the element
    return position->getData();

}


template <class T>
typename BinaryTree<T>::Position& BinaryTree<T>::localize(const T & element){//Localize an element based on the main root

    return localize(root,element);

}

template <class T>
typename BinaryTree<T>::Position& BinaryTree<T>::localize(Position& newRoot,const T& element){//Recursive localize

    //Indicates that the root is void
    if(newRoot==nullptr){
        return newRoot;
    }

    //If the element is equal to the actual root return the position
    if(element==newRoot->getData()){

        return newRoot;

    }

    //if the element is minor than the actual root recursively get on the left side
    if(element<newRoot->getData()){

        return localize(newRoot->getLeft(),element);

    //Else go deep into the right side
    }else{

        return localize( newRoot->getRight(),element);

    }

}


/////EXCLUSIVE FUNCTIONS OF BINARY TREE/////////////////
template <class T>
typename BinaryTree<T>::Position&  BinaryTree<T>::lowest(){//Call the lowest function wich calls the recursive lowest function

    return lowest(root);

}

template <class T>
typename BinaryTree<T>::Position&  BinaryTree<T>::lowest(Position& newRoot){

    //If the tree is empty means we ended on the leaf
    if(newRoot==nullptr){
        return newRoot;
    }

    //Always go to the left that is the lowest on the node
    if(newRoot->getLeft()==nullptr){

        return newRoot;

    }

    //Recursive lowest function to find the lowest based on the left child of the actual node
    return lowest(newRoot->getLeft());

}

//Sames as the lowest but in highest and the right nodes
template <class T>
typename BinaryTree<T>::Position&  BinaryTree<T>::highest(){

    return highest(root);

}

template <class T>
typename BinaryTree<T>::Position&  BinaryTree<T>::highest(Position& newRoot){

    if(newRoot==nullptr){
        return newRoot;
    }

    if(newRoot->getRight()==nullptr){

        return newRoot;

    }
    
    return highest(newRoot->getRight());

}


template <class T>
bool BinaryTree<T>::isLeaf(Position& newRoot) const {//Based on a position return if it's a leaf

    //If the newRoot is a null ptr means that its false
    if(newRoot==nullptr){
        return false;
    }

    //if the node has children, 1 or 2 means its not a leaf 
    if(newRoot->getLeft()==nullptr && newRoot->getRight()==nullptr){
        return true;
    }

    //This means that the node has no children and its a root
    return false;

}

//Recursive traversal
template <class T>
void BinaryTree<T>::preOrder(){

    return preOrder(root);

}

template <class T>
void BinaryTree<T>::preOrder(Position newRoot){

    if(newRoot  == nullptr){
        return;
    }

    std::cout<<newRoot->getData()<<" ";
    preOrder(newRoot->getLeft());
    preOrder(newRoot->getRight());


}

//Recursive traversal
template <class T>
int* BinaryTree<T>::inOrder(int size){
    int *newArray = new int[size];
    int counter=0;

    int *nextArray = inOrder(root,newArray,counter);


    return nextArray;

}

//Recursive traversal
template <class T>
int* BinaryTree<T>::inOrder(Position newRoot, int*array,int counter){


    if(newRoot  == nullptr){
        return array;
    }


    inOrder(newRoot->getLeft(),array,counter);

    array[counter]=newRoot->getData();
    counter++;
    std::cout<<newRoot->getData()<<" ";
    inOrder(newRoot->getRight(),array,counter);

    return array;
    
}


//Recursive traversal
template <class T>
void BinaryTree<T>::postOrder(){

    return postOrder(root);

}

template <class T>
void BinaryTree<T>::postOrder(Position newRoot){

    if(newRoot  == nullptr){
        return;
    }

    postOrder(newRoot->getLeft());
    postOrder(newRoot->getRight());
    std::cout<<newRoot->getData()<<" ";
    

}


template <class T>
int BinaryTree<T>::height(){//Gest the height of the tree based on a root, could be used with the main root or an assigned root
    return height(root);
}

template <class T>
int BinaryTree<T>::height(Position& newRoot){//Return the height of the tree

    //If the root is empty means that theres no tree or we ended on the end of a root
    if(newRoot == nullptr){
        //return 0 so it does not add + 1 to the root
        return 0;
    }

    //Get the height of the every side of the height
    int leftHeight=height(newRoot->getLeft());
    int rightHeight=height(newRoot->getRight());

    //If left is bigger than right
    if(leftHeight>rightHeight){
        return leftHeight+1;
    }

    //Otherwise
    return rightHeight+1;

}

template <class T>
BinaryTree<T>& BinaryTree<T>::operator =(const BinaryTree<T>& tree){

    deleteAll(root);
    this->initialize();
    copyAll(root);

    return *this;

}


#endif // BINARYTREE_HPP