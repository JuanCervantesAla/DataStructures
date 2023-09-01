#include "../include/menu.hpp"
#include "../include/list.hpp"

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
    cout<<"Radio 101.1 The Beat - BigR"<<endl;
    cout<<"Please select an Option"<<endl;
    cout<<"1. Insert a new song\n2.Delete a song\n3.Search a song by position in list\n4.Edit info of one song\n5.Exit"<<endl;
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
    std::string author;
    std::string title;
    std::string interpreter;
    int ranking;

    //Getting the info
    cout<<"Enter the Song's title\n";
    getline(cin,title);

    cout<<"Enter the author\n";
    getline(cin,author);

    cout<<"Enter the interpreter\n";
    getline(cin,interpreter);

    cout<<"Enter the ranking by global ranking\n";
    cin>>ranking;

    cin.ignore();

    //Setting the info to the object
    temporalSong.setTitle(title);
    temporalSong.setAuthor(author);
    temporalSong.setInterpreter(interpreter);
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
        cout<<"Enter the position you would like to get the song in: "<<endl;
        cin>>setPosition;
        cin.ignore();
    }while (!list.isValidPosition(setPosition));
    //Return the info when it's already validated
    return setPosition;
}
