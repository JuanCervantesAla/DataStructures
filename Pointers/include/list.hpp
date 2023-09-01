#ifndef _LIST_HPP_
#define _LIST_HPP_

#include <exception>
#include <iostream>
#include <string>
#include "../include/song.hpp"


class ListException : public std::exception{

    private:
    std::string msg;

    public:
    ListException() noexcept: msg("Undefined error"){}
    ListException( const ListException & ex) noexcept: msg(ex.msg){}
    ListException(const std::string& m) : msg(m){}
    ListException& operator=( const ListException& ex) noexcept{
        msg=ex.msg;
    return *this;
    }
    virtual ~ListException(){}
     
    virtual const char* what() const noexcept{
        return msg.c_str();
    }

};


template<class T=Song, int ARRAYSIZE=100000>
 class List{

    private:
    T* arrayList[100000];
    int last;

    public:
//Definition
    //Check memory on list;
    void initialize();
    ~List();
    bool isEmpty() const;
    bool isFull() const;
    bool isValidPosition(const int&) const;

    //MainFunctions on list
    void insertNewElement(const T&, const int&);
    void deleteElement(const int&);
    void editElement(const T&, const int&);

    //Positions on list
    int getFirstPosition() const;
    int getLastPosition() const;
    int getNextPosition(const int&) const;
    int getPreviousPosition(const int&) const;

    //Localize elements
    int localizePosition(const int&);
    std::string getElement(const int&);
    int findDataLinear(const T&);
    int findDataBinary(const T&);
    

    //Printing methods
    std::string print() const;
    std::string print(const int& position)const;
    std::string printMp3(const int& position) const;

    //Sorting methods
    void swapData(const int&, const int& );
    void bubbleSort();
    void shellSort();
    void insertSort();
    void selectionSort();

    void deleteAll();

    List& operator= (const List&);

};

//Implementation 

//Initialize
template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::initialize(){
    last=-1;
    for (int position = 0; position <ARRAYSIZE; position++) {
        arrayList[position] = nullptr;
    }
}

//Destructor
template<class T, int ARRAYSIZE>
List<T,ARRAYSIZE>::~List(){

    delete arrayList;

}

//If checking by last if -1 means theres nothing on list
template<class T, int ARRAYSIZE>
    bool List<T,ARRAYSIZE>::isEmpty() const{
        if(last==-1) return true;
        else return false;
    }

//Viceversa isEmpty()
template<class T, int ARRAYSIZE>
    bool List<T,ARRAYSIZE>::isFull() const{
        if(last==ARRAYSIZE-1) return true;
        else return false;
    }

//Validating position
template<class T, int ARRAYSIZE>
    bool List<T,ARRAYSIZE>::isValidPosition(const int& position) const{
        return position>=0 and position<=last+1;
    }


//Insert by position and object, checking if theres space and its ok to enter
//Then putting aside the info by one space
//Setting in that space the info
template<class T, int ARRAYSIZE>
    void List<T,ARRAYSIZE>::insertNewElement(const T& newSong, const int& position){
        int counter=last+1;

        if(isFull()){
            throw ListException("Exceding data, insertNewElement");
            }

        if(position<0 || position>last+1){
            throw ListException("Invalid position");
            }

        while(counter>position){

            arrayList[counter] = arrayList[counter-1];
            counter--;

        }

        //Adding 
        arrayList[position]= new T(newSong);
        last=last+1;
        return;
    }

//Same as insert but here we are -1 all the positions after the one eliminated
template<class T, int ARRAYSIZE>
    void List<T,ARRAYSIZE>::deleteElement(const int& position){

        int counter=position;

        if(isEmpty()){
            throw ListException("No element to delete, deleteElement");
        }

        if(!isValidPosition(position)){
            throw ListException("Invalid position, deleteData");
        }

        while(counter<last){
            arrayList[counter]=arrayList[counter+1];
            counter++;
        }
        //Deleting the element on the position
        arrayList[position]=nullptr;
        last=last-1;

    }

//Gets the first position
template<class T, int ARRAYSIZE>
    int List<T,ARRAYSIZE>::getFirstPosition() const{
        if (isEmpty())return -1; 
        else return 0;
    }

//Return the last position
template<class T, int ARRAYSIZE>
    int List<T,ARRAYSIZE>::getLastPosition() const{
        return last;
    }

//Get the previous position
template<class T, int ARRAYSIZE>
    int List<T,ARRAYSIZE>::getPreviousPosition(const int& position) const{
        if(isEmpty() || position<1 || position>last) return -1;
        else return position-1;
    }

//Gets the next position
template<class T, int ARRAYSIZE>
    int List<T,ARRAYSIZE>::getNextPosition(const int& position) const{
        if(isEmpty() || position<0 || position>last-1) return -1;
        else return position+1;
    }

//Retrive info(object) by  position
template<class T, int ARRAYSIZE>
std::string List<T,ARRAYSIZE>::getElement(const int& position){
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
template<class T, int ARRAYSIZE>
    void List<T,ARRAYSIZE>::deleteAll(){
        last=-1;
        for (int position = 0; position <ARRAYSIZE; position++) {
            delete arrayList[position] ;
        }
    }

//Stores in a string all the list and return that
template<class T, int ARRAYSIZE>
    std::string List<T,ARRAYSIZE>::print() const{
        int counter=0;
        std::string arrayListList;
        while(counter<=last){
            arrayListList+="-------------------------------------------------------------------------------------\n";
            arrayListList+="|||"+std::to_string(counter)+"°|"+"Song: "+arrayList[counter]->getTitle()+" ||Author: "+arrayList[counter]->getAuthor()+
            " ||Interpreter: "+arrayList[counter]->getInterpreter()+" ||Ranking: "+std::to_string(arrayList[counter]->getRanking())+"||FileName: "+arrayList[counter]->getFileName()+"|||\n\n";
            counter++;
        }
        return arrayListList;
    }

//Store the specific info(position) and returns an object(info)
template<class T, int ARRAYSIZE>
    std::string List<T,ARRAYSIZE>::print(const int& position) const{

        std::string arrayListInformation;

        arrayListInformation= "|||Song: "+arrayList[position]->getTitle()+" |Author: "+arrayList[position]->getAuthor()+
        " |Interpreter: "+arrayList[position]->getInterpreter()+" |Ranking: "+std::to_string(arrayList[position]->getRanking())+"|File: "+arrayList[position]->getFileName()+"|||\n";
        return arrayListInformation;
    }

template<class T, int ARRAYSIZE>
    std::string List<T,ARRAYSIZE>::printMp3(const int& position) const{

        std::string arrayListInformation;

        arrayListInformation="|File: "+arrayList[position]->getFileName()+"|||\n";
        return arrayListInformation;
    }

template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::editElement(const T& newSong, const int& position){
    if(isEmpty() or !isValidPosition(position)){
        throw ListException("Not element to edit, editElement");
    }
    else{
        arrayList[position]=new T(newSong);
    }
}

//Linear Search
template<class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::findDataLinear(const T& newSong){
    int i(0);

    while (i<=last) {
        if(*arrayList[i]==newSong){
            return i;
        }

        i++;
    }

    return -1;
}   

template<class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::findDataBinary(const T & newarrayList){
    int i(0), j(last), m;
    while (i<=j) {
        m=(i+j)/2;

        if(*arrayList[m]==newarrayList){
            return m;
        }

        if(newarrayList<*arrayList[m]){
            j=m-1;
        }
        else{
            i=m+1;
        }
    }
    return -1;
}


///Sorting METHODS////
template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::swapData(const int& previousPosition, const int& nextPosition){

    T* aux;

    aux=arrayList[nextPosition];
    arrayList[nextPosition]=arrayList[previousPosition];
    arrayList[previousPosition]=aux;

}

template<class T, int ARRAYSIZE>
//This one is sorting by Tittle
void List<T,ARRAYSIZE>::bubbleSort(){

    int i(last),j;
    Song auxiliararrayList;

    while (i>0) {
            
        j=0;

        while (j<i) {

            auxiliararrayList.setTitle(arrayList[j]->getTitle());
            if(auxiliararrayList.getTitle()>arrayList[j+1]->getTitle()){
                swapData(j,j+1);
            }

            j++;
                
        }

        i--;

    }

}

//This one is sorting by interpreter
template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::shellSort(){

    float factor=(1.0/2.0);
    int differential=(last+1)*factor,i,j;
    Song auxiliararrayList;


    while (differential>0) {
        i=differential;

        while (i<=last) {
        
            j=i;

            auxiliararrayList.setInterpreter((*arrayList[j]).getInterpreterO());
            while (j>=differential && (*arrayList[j-differential]).getInterpreter()  > auxiliararrayList.getInterpreter()) {
                swapData((j-differential),j);
                j=j-differential;
            }

            i++;

        }

    differential=differential*factor;

    }

}


//This one is by interpreter
template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::insertSort(){
    int i(1),j;
    Song auxiliararrayList;

    while (i<=last) {
        auxiliararrayList.setInterpreter(arrayList[i]->getInterpreterO());
        j=i;
        while (j>0 && auxiliararrayList.getInterpreter() < arrayList[j-1]->getInterpreter()) {
            swapData(j,j-1);
            j--;
        }

        if (i!=j){
            arrayList[j]->setInterpreter(auxiliararrayList.getInterpreterO());
        }

        i++;

    }
}

//This one is sorted by title
template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::selectionSort(){
    int i(0),lesser,j;
    Song auxiliararrayList;

    while (i<last) {
        lesser=1;
        j=i+1;
        while (j<=last) {
            
            auxiliararrayList.setTitle(arrayList[j]->getTitle());
            if(auxiliararrayList.getTitle()<arrayList[lesser]->getTitle()){
                lesser=j;
            }
            j++;
        }

        if(lesser!=i){
            swapData(i,lesser);
        }

        i++;
    }
}


#endif // _LST_HPP_