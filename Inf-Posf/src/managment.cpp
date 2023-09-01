#include "../include/managment.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;


Queue<char,50>& Managment::fromInf()
{
    cout<<"Ingrese caracter por caracter:"<<endl<<"Use el caracter | para finalizar"<<"\n";
    cin>>inChar;
    cin.ignore();
    while (inChar!='|' && !recievingQueue.isFull())
    {
        recievingQueue.enqueue(inChar);
        cin>>inChar;
        cin.ignore();
    }
    return recievingQueue;
}


void Managment::toPos()
{
    int compare1,compare2;
    char tempInChar;
    do
    {
        if(characterValidation(recievingQueue.tofront())==true)
        {

            if(stack.isEmpty())
            {

                stack.push(recievingQueue.tofront());
                recievingQueue.dequeue();


            }
            else
            {

                compare1=setHierarchy(stack.topeek());

                if(compare1==5)
                {

                    stack.pop();

                    do
                    {

                        sendingQueue.enqueue(stack.pop());

                    }
                    while (stack.topeek()!='(');

                    stack.pop();
                    recievingQueue.dequeue();
                }

                else
                {

                    tempInChar=recievingQueue.tofront();
                    compare2=setHierarchy(recievingQueue.tofront());

                    if(compare1==compare2)
                    {
                        sendingQueue.enqueue(stack.pop());
                        stack.push(recievingQueue.tofront());
                        recievingQueue.dequeue();

                    }

                    if(compare1<compare2)
                    {
                        stack.push(tempInChar);
                        recievingQueue.dequeue();

                    }
                    if(compare1>compare2 && compare1!=4)
                    {
                        sendingQueue.enqueue(stack.pop());
                        compare1=setHierarchy(stack.topeek());
                        if(compare2>compare1)
                        {
                            stack.push(recievingQueue.tofront());
                            recievingQueue.dequeue();
                        }
                        if(compare1==compare2)
                        {
                            sendingQueue.enqueue(stack.pop());
                            stack.push(recievingQueue.tofront());
                            recievingQueue.dequeue();

                        }


                    }
                    if(compare1>compare2 && compare1==4)
                    {
                        stack.push(tempInChar);
                        recievingQueue.dequeue();
                    }


                }
            }

        }
        else
        {

            sendingQueue.enqueue(recievingQueue.tofront());
            recievingQueue.dequeue();

        }



    }
    while(!recievingQueue.isEmpty());


    while (!stack.isEmpty())
    {
        sendingQueue.enqueue(stack.pop());
    }
    printQueue();

    return;
}


void Managment::printQueue()
{
    while (!sendingQueue.isEmpty())
    {
        cout<<sendingQueue.tofront();
        sendingQueue.dequeue();
    }
}

bool Managment::characterValidation(const char& inChar)
{
    if(inChar=='*'||inChar=='+'||inChar=='/'||inChar=='-'||inChar=='^'||inChar=='('||inChar==')')
    {
        return true;
    }
    return false;
}

int Managment::setHierarchy(const char& newInChar)
{

    int greater;
    switch (newInChar)
    {
    case '+':
        greater=1;
        break;
    case '-':
        greater=1;
        break;
    case '*':
        greater=2;
        break;
    case '/':
        greater=2;
        break;
    case '^':
        greater=3;
        break;
    case '(':
        greater=4;
        break;
    case ')':
        greater=5;
        break;

    }
    return greater;

}
