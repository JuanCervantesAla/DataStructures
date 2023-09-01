#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <iostream>
#include <random>
#include <chrono>
#include "../include/binarytree.hpp"

using namespace std;

class Manager{

    private:
        int size;
    public:
        int show();
        void onAction();

};

int Manager::show(){

    int size=0;
    cout<<"Welcome to the demostration of BinaryTree"<<endl;
    do{
        cout<<"Enter the size of the tree, no less than 1:"<<endl;
        cin>>size;
    } while(size<=0);
    

    return size;
}

void Manager::onAction(){

    //Creating the object/atributes
    BinaryTreeAvl<int> groot;
    size = show();
    
    //Semilla generadora, trackea movimientos de la computadora
    /*
    static random_device randomListener;
    static unsigned seed = randomListener();*/
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    //Algoritmo de generacion mersenne twister, genera mejor que default
    static mt19937 numberGenerator(seed);

    //Inserting the elements into the binary tree
    cout<<"//////////Inserting the elements...////////"<<endl<<endl;

    for(int counter=0;counter<size;counter++){ 

        //Distribucion de reales entre los limites x y y
        uniform_int_distribution<int> limitNumber (0, 100000);

        int number = limitNumber(numberGenerator);


        cout<<number<<" ";
        groot.insert(number);

    }

    cout<<endl<<endl;

    //PreOrder;
    cout<<"////////////////////////////////////////////////"<<endl;
    cout<<"**********PRE-ORDER*************"<<endl<<endl;
    groot.preOrder();

    cout<<endl<<endl;

    cout<<"////////////////////////////////////////////////"<<endl;
    cout<<"**********In-ORDER*************"<<endl<<endl;
    groot.inOrder(size);

    cout<<endl<<endl;
    
    cout<<"////////////////////////////////////////////////"<<endl;
    cout<<"**********Post-ORDER*************"<<endl<<endl;
    groot.postOrder();

    cout<<endl<<endl;

    cout<<"////////////////////////////////////////////////"<<endl;
    cout<<"**********GET LOWEST AND HIGHEST*************"<<endl<<endl;
    cout<<groot.retrieve(groot.lowest())<<endl;
    cout<<groot.retrieve(groot.highest())<<endl;

    cout<<"////////////////////////////////////////////////"<<endl;
    cout<<"**********Height of the right and left subtrees*************"<<endl<<endl;
    cout<<groot.height(groot.localize(groot.getRoot()->getLeft()->getData()))<<endl;
    cout<<groot.height(groot.localize(groot.getRoot()->getRight()->getData()))<<endl;

}


#endif // MANAGER_HPP