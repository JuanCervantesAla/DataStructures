#ifndef MANAGER_HPP
#define MANAGER_HPP
#include "../include/queue.hpp"
#include "../include/stack.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Manager{

    private:
        int option;

        string line;
        Queue<char> recievingQueue;
        Queue<char> sendingQueue;
        Stack<char> stack;

    public:
        void fromInf();
        Queue<char>&  toPos();
        void printQueue(Queue<char>&);
        bool characterValidation(const char&);
        int setHierarchy(const char&);


};


void Manager::fromInf(){

    cout<<"****Infix to posfix****"<<endl<<"///Enter an operation///"<<endl;
    cin>>line;
    int counter=0;

    while(counter<line.size()){

        sendingQueue.enqueue(line.at(counter));
        counter++;
    }
    
    cout<<endl;

}

Queue<char>&  Manager::toPos(){
    fromInf();
    do{

        if(!characterValidation(sendingQueue.getFront())){

            recievingQueue.enqueue(sendingQueue.getFront());
            sendingQueue.dequeue();

        }else{

            if(stack.isEmpty()){

                stack.push(sendingQueue.getFront());
                sendingQueue.dequeue();

            }
            else{

                switch (setHierarchy(sendingQueue.getFront())) {

                    case 3:
                        //REVISA QUE EL STACK NO ESTE VACIO PARA HACERLE POP, CHECAR POR FUTURAS REFERENCIAS
                        while(!(stack.isEmpty())  &&  setHierarchy(stack.getTop())>=setHierarchy(sendingQueue.getFront()) ){
                            recievingQueue.enqueue(stack.pop());
                        }

                        stack.push(sendingQueue.getFront());
                        sendingQueue.dequeue();

                        break;

                    case 4:
                    //REVISA QUE EL STACK NO ESTE VACIO PARA HACERLE POP, CHECAR POR FUTURAS REFERENCIAS
                        while(!(stack.isEmpty()) && setHierarchy(stack.getTop())>=setHierarchy(sendingQueue.getFront())){
                            recievingQueue.enqueue(stack.pop());
                        }

                        stack.push(sendingQueue.getFront());
                        sendingQueue.dequeue();

                        break;

                    case 5:
                    //REVISA QUE EL STACK NO ESTE VACIO PARA HACERLE POP, CHECAR POR FUTURAS REFERENCIAS
                        while(!(stack.isEmpty()) && setHierarchy(stack.getTop())>=setHierarchy(sendingQueue.getFront())){
                            recievingQueue.enqueue(stack.pop());
                        }

                        stack.push(sendingQueue.getFront());
                        sendingQueue.dequeue();

                        break;

                    case 1:
                        stack.push(sendingQueue.getFront());
                        sendingQueue.dequeue();

                        break;

                    case 2:

                        sendingQueue.dequeue();

                        while (stack.getTop()!='(') {
                            recievingQueue.enqueue(stack.pop());
                        }

                        stack.pop();

                        break;    
                }

            }

        }
        //sendingQueue.dequeue();

    }while(!sendingQueue.isEmpty());

    cout<<"To posfix:"<<endl;
    
    while (!stack.isEmpty()) {
        recievingQueue.enqueue(stack.pop());
    }

    return recievingQueue;

}


void Manager::printQueue(Queue<char>&q){

    while (!q.isEmpty()){
        cout<<q.dequeue();
    }
}

bool Manager::characterValidation(const char& inChar){

    if(inChar=='*'||inChar=='+'||inChar=='/'||inChar=='-'||inChar=='^'||inChar=='('||inChar==')'){
        return true;
    }
    return false;
}


int Manager::setHierarchy(const char& newInChar){

    int greater;
    switch (newInChar)
    {
    case '^':
        greater=5;
        break;
    case '*':
        greater=4;
        break;
    case '/':
        greater=4;
        break;
    case '+':
        greater=3;
        break;
    case '-':
        greater=3;
        break;
    case '(':
        greater=1;
        break;
    case ')':
        greater=2;
        break;
    }

    return greater;

}

#endif // !MANAGER_HPP