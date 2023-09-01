#include "../include/menu.hpp"
#include "../include/list.hpp"
#include "../include/author.hpp"
#include "../include/interpreter.hpp"

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

//Atributes
List list;
Song song;
Menu menu;

//Print out menu & retrieve the selected option
int Menu::showMenu() const{
    int selectedOption;
    system("cls");
    cout<<list.print();
    cout<<"\n***************************\nRadio 101.1 The Beat - BigR"<<endl;
    cout<<"Please select an Option"<<endl;
    cout<<"1. Insert a new song\n2.Delete a song\n3.Search a song by position in list\n4.Edit info of one song\n5.Find by title\n6.Find by interpreter\n7.Exit\n**********************"<<endl;
    cin>>selectedOption;
    cin.ignore();
    return selectedOption;

}

//Switch-> insert,delete,edit,search,exit
bool Menu::menuOption(const int& selectedOption){

    bool exit = false;

    system("cls");
    switch (selectedOption) {
        //Everycase ALWAYS print the list
        case 1:
            cout<<list.print();
            //Insert new element(object song, position)
            list.insertNewElement(menu.captureSongDetail(),checkPosition());
            break;

        case 2:
            cout<<list.print();
            //Delete element(position)
            list.deleteElement(checkPosition());
            break;

        case 3:
            cout<<list.print();
            //Get element by position
            cout<<list.getElement(checkPosition());
            break;

        case 4:
            cout<<list.print();
            //Edit element by object song and position
            list.editElement(captureSongDetail(),checkPosition());
            break;


        case 5:
            cout<<"\n-----Linear search-----\n";
            searchOption(1,1);
            cout<<"\n---Binary search-----\n";
            searchOption(2,1);
            system("pause");
            break;
        case 6:
            cout<<"\n-----Linear search-----\n";
            searchOption(1,2);
            cout<<"\n---Binary search-----\n";
            searchOption(2,2);
            system("pause");
            break;


        case 7:
            //If exit = true, means to end the program
            exit=true;
            return exit;
            break;

        default: cout<<"Error: Not and option";

    }

    return false;
}

//Capturing songs info
Song Menu::captureSongDetail() const{
    //In a temporal object store all the info
    Song temporalSong;
    Author tempAuthor;
    Interpreter tempInterpreter;
    MP3 tempMp3;
    std::string authorFirstName;
    std::string authorLastName;
    std::string title;
    std::string interpreterFirstName;
    std::string interpreterLastName;
    std::string fileName;
    int ranking;

    //Getting the info
    cout<<"\n";
    cout<<"****Enter the Song's title\n";
    getline(cin,title);

    cout<<"\n";
    cout<<"****Enter the author's first name\n";
    getline(cin,authorFirstName);
    tempAuthor.setFirstName(authorFirstName);

    cout<<"\n";
    cout<<"****Enter the author's Last name\n";
    getline(cin,authorLastName);
    tempAuthor.setLastName(authorLastName);

    cout<<"\n";
    cout<<"****Enter the interpreter's first name\n";
    getline(cin,interpreterFirstName);
    tempInterpreter.setFirstName(interpreterFirstName);
    
    cout<<"\n";
    cout<<"****Enter the interpreter's first name\n";
    getline(cin,interpreterLastName);
    tempInterpreter.setLastName(interpreterLastName);

    cout<<"\n";
    cout<<"****Enter the file name\n";
    getline(cin,fileName);
    tempMp3.setFileName(fileName);

    cout<<"\n";
    cout<<"****Enter the ranking by global ranking\n";
    cin>>ranking;

    cin.ignore();

    //Setting the info to the object
    temporalSong.setTitle(title);
    temporalSong.setAuthor(tempAuthor);
    temporalSong.setFileName(tempMp3);
    temporalSong.setInterpreter(tempInterpreter);
    temporalSong.setRanking(ranking);

    //return the object(info)
    return temporalSong;
    
}

//Initialize the list
void Menu::initializeList() const{
    list.initialize();
}

//Get and set the selectedoption
void Menu::setOption(const int& newSelectedOption){
    selectedOption=newSelectedOption;
}

int Menu::getOption()const{
    return selectedOption;
}

//Check the position by validating it's in rule, until it's correct
int Menu::checkPosition() const{

    int setPosition;

    do{
        cout<<"Enter the position you would like to perfom the action: "<<endl;
        cin>>setPosition;
        cin.ignore();

    }while (!list.isValidPosition(setPosition));

    //Return the info when it's already validated
    return setPosition;
}

std::string Menu::dataToFind(){

    std::string returnString;
    cout<<"\nEnter the data to find\n";
    getline(cin,returnString);

    return returnString;
    
}

void Menu::searchOption(const int& search,const int& optionData){

    Song tempSong2;
    Interpreter tempInterpreter;
    int realPosition;
    string dataFound;
    string interFirst;
    string interLast;

    if(optionData==1){
        cout<<list.print();
        dataFound=menu.dataToFind();
        tempSong2.setTitle(dataFound);
    }

    if(optionData==2){
        cout<<"\n Enter the interpreter first name\n";
        getline(cin,interFirst);
        tempInterpreter.setFirstName(interFirst);

        cout<<"\n Enter the interpreter last name\n";
        getline(cin,interLast);
        tempInterpreter.setLastName(interLast);
        tempSong2.setInterpreter(tempInterpreter);
    }
    


    if(search==1){
        realPosition=list.findDataLinear(tempSong2);
    }
    if(search==2){
        realPosition=list.findDataBinary(tempSong2);
    }

    if(realPosition==-1){
        cout<<"Not found on list";
        system("pause");
    }
    else{
        cout<<"Song is in position: "+to_string(realPosition)<<endl;
        cout<<"Song's data found: "<<endl;
        cout<<list.getElement(realPosition);
    }
}
