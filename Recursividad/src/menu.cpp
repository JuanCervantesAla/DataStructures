#include "../include/menu.hpp"
#include <istream>
#include <iostream>
#include <ostream>
#include <random>
#include <chrono>
#include "../include/integer.hpp"
#include "../include/list.hpp"
using namespace std;

List<Integer,100001> listOriginal;
List<Integer,100001> listAuxiliar;

int Menu::showMenu(){

    cout<<"\n-----Menu and sorting for dummies-----"<<endl;
    cout<<"1.Show sort time by algorithm"<<endl;
    cout<<"2.Exit"<<endl;
    cin>>option;
    return option;

}

void Menu::menuOnAction(){
    
    listOriginal.initialize();
    listAuxiliar.initialize();
    bool exit=false;
    int counter=900;
    chrono::duration<double, std::milli> quickTime;
    chrono::duration<double, std::milli> bubbleTime;
    chrono::duration<double, std::milli> selectTime;
    chrono::duration<double, std::milli> insertTime;
    chrono::duration<double, std::milli> shellTime;
    chrono::duration<double, std::milli> mergeTime;
    auto start = chrono::high_resolution_clock::now();
    auto finish = chrono::high_resolution_clock::now();

    while (exit!=true) {
        switch (showMenu()) {
            case 1:
                fillList();

                //Shell
                copyList();
                start = chrono::high_resolution_clock::now();
                listAuxiliar.shellSort();
                finish = chrono::high_resolution_clock::now();
                shellTime= finish - start;
                if(!listAuxiliar.isSorted()){
                    cout<<"No ordenado";
                    return;
                }


                //Quick
                listAuxiliar.deleteAll();
                copyList();
                start = chrono::high_resolution_clock::now();
                listAuxiliar.quickSort();
                finish = chrono::high_resolution_clock::now();
                quickTime= finish - start;
                if(!listAuxiliar.isSorted()){
                    cout<<"No ordenado";
                    return;
                }
    
                //Select
                listAuxiliar.deleteAll();
                copyList();
                start = chrono::high_resolution_clock::now();
                listAuxiliar.selectionSort();
                finish = chrono::high_resolution_clock::now();
                selectTime= finish - start;
                if(!listAuxiliar.isSorted()){
                    cout<<"No ordenado";
                    return;
                }

                //Bubble
                listAuxiliar.deleteAll();
                copyList();
                start = chrono::high_resolution_clock::now();
                listAuxiliar.bubbleSort();
                finish = chrono::high_resolution_clock::now();
                bubbleTime= finish - start;
                if(!listAuxiliar.isSorted()){
                    cout<<"No ordenado";
                    return;
                }

                //Insert
                listAuxiliar.deleteAll();
                copyList();
                start = chrono::high_resolution_clock::now();
                listAuxiliar.insertSort();
                finish = chrono::high_resolution_clock::now();
                insertTime= finish - start;
                if(!listAuxiliar.isSorted()){
                    cout<<"No ordenado";
                    return;
                }


                //Merge
                listAuxiliar.deleteAll();
                copyList();
                start = chrono::high_resolution_clock::now();
                listAuxiliar.mergeSort();
                finish = chrono::high_resolution_clock::now();
                mergeTime= finish - start;

                cout<<"\n----------------------------\n";
                cout<<"Execution time in milliseconds: "<<endl;
                cout<<"Quick sort: "<<quickTime.count()<<endl;
                cout<<"Bubble sort: "<<bubbleTime.count()<<endl;
                cout<<"Selection sort: "<<selectTime.count()<<endl;
                cout<<"Insert sort: "<<insertTime.count()<<endl;
                cout<<"Shell Sort: "<<shellTime.count()<<endl;
                cout<<"Merge: "<<mergeTime.count()<<endl;
                cout<<"\n----------------------------\n";


                break;


            case 2:
                exit=true;
                break;
        }
    }

}

void Menu::copyList(){
    int position=0;
    Integer numero;
    while (position<100001) {
        numero=listOriginal.getElementE(position);
        listAuxiliar.insertNewElement(numero, position);
        position++;
    }

}

void Menu::fillList(){
    Integer numero;
    int position=0;
    random_device randomListener;

    unsigned seed = randomListener();
    mt19937 numberGenerator(seed);
    uniform_int_distribution<long long> limitNumber (0,1000000);

    cout<<"Filling the list..."<<endl;

    while (position<100001) {

        numero=limitNumber(numberGenerator);
        listOriginal.insertNewElement(numero,position);
        position++;

    }

    cout<<"List filled"<<endl;
}