#include "../include/list.hpp"
#include <iterator>
#include <stdlib.h>
#include <string>

//Implementation 

//Initialize
    void List::initialize(){
        last=-1;
    }

//If checking by last if -1 means theres nothing on list
    bool List::isEmpty() const{
        if(last==-1) return true;
        else return false;
    }

//Viceversa isEmpty()
    bool List::isFull() const{
        if(last==sizeof(song)-1) return true;
        else return false;
    }

//Validating position
    bool List::isValidPosition(const int& position) const{
        return position>=0 and position<=last+1;
    }


//Insert by position and object, checking if theres space and its ok to enter
//Then putting aside the info by one space
//Setting in that space the info
    void List::insertNewElement(const Song& newSong, const int& position){
        int counter=last+1;

        if(isFull()){
            return;}

        if(position<0 || position>last+1){
            return;}

        while(counter>position){

            song[counter] = song[counter-1];
            counter--;

        }

        song[position]=newSong;
        last=last+1;
        return;
    }

//Same as insert but here we are -1 all the positions after the one eliminated
    void List::deleteElement(const int& position){
        int counter=position;
        if(isEmpty()) return;
        if(!isValidPosition(position)) return;

        while(counter<last){
            song[counter]=song[counter+1];
            counter++;
        }

        last=last-1;

    }

//Gets the first position
    int List::getFirstPosition() const{
        if (isEmpty())return -1; 
        else return 0;
    }

//Return the last position
    int List::getLastPosition() const{
        return last;
    }

//Get the previous position
    int List::getPreviousPosition(const int& position) const{
        if(isEmpty() || position<1 || position>last) return -1;
        else return position-1;
    }

//Gets the next position
    int List::getNextPosition(const int& position) const{
        if(isEmpty() || position<0 || position>last-1) return -1;
        else return position+1;
    }

//Retrive info(object) by  position
    std::string List::getElement(const int& position){
        if(isEmpty() || position<0 || position>last) throw "error";
        else return print(position);
    }

//Not deletes the info just, set the "counter" to -1 to overwrite the info
    void List::deleteAll(){
        last=-1;
    }

//Stores in a string all the list and return that
    std::string List::print() const{
        int counter=0;
        std::string songList;
        while(counter<=last){
            songList+=std::to_string(counter)+" Song: "+song[counter].getTitle()+" |Author: "+song[counter].getAuthor()+
            " |Interpreter: "+song[counter].getInterpreter()+" |Ranking: "+std::to_string(song[counter].getRanking())+"\n\n";
            counter++;
        }
        return songList;
    }

//Store the specific info(position) and returns an object(info)
    std::string List::print(const int& position) const{
        system("cls");
        std::string songInformation;
        songInformation= "Song: "+song[position].getTitle()+" |Author: "+song[position].getAuthor()+
        " |Interpreter: "+song[position].getInterpreter()+" |Ranking: "+std::to_string(song[position].getRanking())+"\n";
        return songInformation;
    }

    void List::editElement(const Song& newSong, const int& position){
        song[position]=newSong;
    }
