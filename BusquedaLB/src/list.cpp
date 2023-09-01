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
            throw ListException("Exceding data, insertNewElement");
            }

        if(position<0 || position>last+1){
            throw ListException("Invalid position");
            }

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

        if(isEmpty()){
            throw ListException("No element to delete, deleteElement");
        }

        if(!isValidPosition(position)){
            throw ListException("Invalid position, deleteData");
        }

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
    std::string returnString;

    if(isEmpty() || position<0 || position>last){
        throw ListException("Invalid position, get Element");
    }
    else{
        returnString=printMp3(position);
        return returnString;
    }
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
            songList+="-------------------------------------------------------------------------------------\n";
            songList+="|||Song: "+song[counter].getTitle()+" ||Author: "+song[counter].getAuthor()+
            " ||Interpreter: "+song[counter].getInterpreter()+" ||Ranking: "+std::to_string(song[counter].getRanking())+"||FileName: "+song[counter].getFileName()+"|||\n\n";
            counter++;
        }
        return songList;
    }

//Store the specific info(position) and returns an object(info)
    std::string List::print(const int& position) const{

        std::string songInformation;

        songInformation= "|||Song: "+song[position].getTitle()+" |Author: "+song[position].getAuthor()+
        " |Interpreter: "+song[position].getInterpreter()+" |Ranking: "+std::to_string(song[position].getRanking())+"|File: "+song[position].getFileName()+"|||\n";
        return songInformation;
    }

    std::string List::printMp3(const int& position) const{

        std::string songInformation;

        songInformation="|File: "+song[position].getFileName()+"|||\n";
        return songInformation;
    }

void List::editElement(const Song& newSong, const int& position){
    if(isEmpty() or !isValidPosition(position)){
        throw ListException("Not element to edit, editElement");
    }
    else{
        song[position]=newSong;
    }
}

//Linear Search
int List::findDataLinear(const Song& newSong){
    int i(0);

    while (i<=last) {
        if(song[i]==newSong){
            return i;
        }

        i++;
    }

    return -1;
}   

int List::findDataBinary(const Song & newSong){
    int i(0), j(last), m;
    while (i<=j) {
        m=(i+j)/2;

        if(song[m]==newSong){
            return m;
        }

        if(newSong<song[m]){
            j=m-1;
        }
        else{
            i=m+1;
        }
    }
    return -1;
}