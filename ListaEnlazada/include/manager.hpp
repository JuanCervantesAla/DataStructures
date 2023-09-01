#ifndef MANAGER_HPP
#define MANAGER_HPP
#include "../include/list.hpp"
#include "../src/song.cpp"
#include "../include/author.hpp"
#include "../include/interpreter.hpp"
#include <ostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Manager{

    private:
        int option;
        bool exit=false;
        Song auxiliarSong;

    public:

        void menuOnAction(List<Song>&);
        int showMenu();
        Song captureInfoDetail() const;

};

void Manager::menuOnAction(List<Song> &list){

    List<Song>::Position pos;
    std::string example;

    while (exit==false) {
        system("cls");
        cout<<"***************Current list***************"<<endl;
        cout<<list.toString();
        cout<<endl;
        switch (showMenu()) {
            
            case 1:
                auxiliarSong=captureInfoDetail();
                list.insertData(list.getLastPos(), auxiliarSong);
                break;
            case 2:
                cout<<"Type the song's title to delete:"<<endl;
                getline(cin,example);
                auxiliarSong.setTitle(example);

                pos=list.findData(auxiliarSong);
                if(pos==nullptr){
                    cout<<"Not found on list";
                }
                else{
                    cout<<"Element: "<<list.retrieve(pos).toString()<<endl;
                    list.deleteData(pos);
                    cout<<"Element deleted"<<endl;;
                    system("pause");
                }
                break;

            case 3:
                cout<<"Type the song's title to insert next of:"<<endl;
                getline(cin,example);
                auxiliarSong.setTitle(example);

                pos=list.findData(auxiliarSong);
                if(pos==nullptr){
                    cout<<"Not found on list";
                }
                else{
                    cout<<"Inserting next of: "<<"Element: "<<list.retrieve(pos).toString()<<endl;
                    list.insertData(list.getNextPos(pos), captureInfoDetail());
                    cout<<"Element inserted"<<endl;;
                    system("pause");
                }
                break;

            case 4:
                cout<<"Type the song's title to find:"<<endl;
                getline(cin,example);
                auxiliarSong.setTitle(example);

                pos=list.findData(auxiliarSong);
                if(pos==nullptr){
                    cout<<"Not found on list";
                }
                else{
                    cout<<"Element: "<<list.retrieve(pos).toString()<<endl;
                    cout<<"Element found"<<endl;;
                    system("pause");
                }
                break;

            case 5:
                cout<<"Type the song's title to edit"<<endl;
                getline(cin,example);
                auxiliarSong.setTitle(example);

                pos=list.findData(auxiliarSong);
                if(pos==nullptr){
                    cout<<"Not found on list";
                }
                else{
                    Node<Song>* aux(pos);
                    aux->setData(captureInfoDetail());
                    list.insertData(aux, aux->getData());
                    list.deleteData(pos);
                    cout<<"Element inserted"<<endl;;
                    system("pause");
                }
                break;

        }
    }

}


int Manager::showMenu(){

    cout<<"-----------RADIO 89.4FM-------------"<<endl;
    cout<<"1.Add a song"<<endl<<"2.Delete a song"<<endl<<"3.Insert depending on a song"<<endl<<"4.Find a song"<<endl<<"5.Edit song"<<endl;
    cin>>option;
    cin.ignore();
    return option;

}

//Capturing songs info
Song Manager::captureInfoDetail() const{
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
    cout<<"****Enter the interpreter's Last name\n";
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


#endif // MANAGER_HPP