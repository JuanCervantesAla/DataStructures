#ifndef _LIST_HPP_
#define _LIST_HPP_
#include <exception>
#include <iostream>
#include <iterator>
#include <ostream>
#include <stdlib.h>
#include <string>
#include "../include/integer.hpp"



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

template<class T=Integer, long long ARRAYSIZE=100002>
class List{

    private:
    T array[ARRAYSIZE];
    long last;

    public:
//Definition
    //Check memory on list;
    void initialize();
    bool isEmpty() const;
    bool isFull() const;
    bool isValidPosition(int&) ;

    //MainFunctions on list
    void insertNewElement(T&,int&);
    void deleteElement(int &);
    void editElement(const T&, const Integer&);

    //Positions on list
    Integer getFirstPosition() const;
    int getLastPosition() const;
    Integer getNextPosition(int&);
    Integer getPreviousPosition(Integer&) const;

    //Localize elements
    Integer localizePosition(const Integer&);
    std::string getElement(const int&);
    T getElementE(const int&);
    Integer findDataLinear(const T&);
    Integer findDataBinary(const T&);
    

    //PrIntegering methods
    std::string print();
    std::string print(const int& position)const;

    //Sorting methods
    void swapData(const int&, const int& );
    void copyArray(Integer*,Integer*);
    bool isSorted();
    bool isEqual();

    void bubbleSort();
    void shellSort();
    void insertSort();
    void selectionSort();
    void mergeSort();
    void mergeSort(const int,const int);
    void quickSort();
    void quickSort(const int, const int);

    void deleteAll();

};

//Implementation 

//Initialize
template<class T, long long ARRAYSIZE>
    void List<T,ARRAYSIZE>::initialize(){
        last=-1;
    }

//If checking by last if -1 means theres nothing on list
template<class T, long long ARRAYSIZE>
    bool List<T,ARRAYSIZE>::isEmpty() const{
        if(last==-1) return true;
        else return false;
    }

//Viceversa isEmpty()
template<class T, long long ARRAYSIZE>
    bool List<T,ARRAYSIZE>::isFull() const{
        if(last==ARRAYSIZE-1) return true;
        else return false;
    }

//Validating position
template<class T, long long ARRAYSIZE>
    bool List<T,ARRAYSIZE>::isValidPosition(int& position) {
        return position>=0 and position<=last+1;
    }


//Insert by position and object, checking if theres space and its ok to enter
//Then putting aside the info by one space
//Setting in that space the info
template<class T, long long ARRAYSIZE>
    void List<T,ARRAYSIZE>::insertNewElement( T& newElement, int& position){
        int counter=last+1;

        if(isFull()){
            throw ListException("Exceding data, insertNewElement");
            }

        if(position<0 || position>last+1){
            throw ListException("Invalid position");
            }

        while(counter>position){
    
            array[counter] = array[counter-1];
            counter--;

        }

        array[position]=newElement;
        last=last+1;
        return;
    }

//Same as insert but here we are -1 all the positions after the one eliminated
template<class T, long long ARRAYSIZE>
    void List<T,ARRAYSIZE>::deleteElement(int& position){

        int counter=position;

        if(isEmpty()){
            throw ListException("No element to delete, deleteElement");
        }

        if(!isValidPosition(position)){
            throw ListException("Invalid position, deleteData");
        }

        while(counter<last){
            array[counter]=array[counter+1];
            counter++;
        }

        last=last-1;

    }

//Gets the first position
template<class T, long long ARRAYSIZE>
    Integer List<T,ARRAYSIZE>::getFirstPosition() const{
        if (isEmpty())return -1; 
        else return 0;
    }

//Return the last position
template<class T, long long ARRAYSIZE>
    int List<T,ARRAYSIZE>::getLastPosition() const{
        return last;
    }

//Get the previous position
template<class T, long long ARRAYSIZE>
    Integer List<T,ARRAYSIZE>::getPreviousPosition( Integer& position) const{
        if(isEmpty() || position<1 || position>last) return -1;
        else return position-1;
    }

//Gets the next position
template<class T, long long ARRAYSIZE>
    Integer List<T,ARRAYSIZE>::getNextPosition(int& position) {
        if(isEmpty() || position<0 || position>last-1) return -1;
        else return position+1;
    }

//Retrive info(object) by  position
template<class T, long long ARRAYSIZE>
std::string List<T,ARRAYSIZE>::getElement(const int& position){
    std::string returnString;

    if(isEmpty() || position<0 || position>last){
        throw ListException("Invalid position, get Element");
    }
    else{
        returnString=print(position);
        return returnString;
    }
}


template<class T, long long ARRAYSIZE>
T List<T,ARRAYSIZE>::getElementE(const int& position){
    Integer newElement;
    if(isEmpty() || position<0 || position>last){
        throw ListException("Invalid position, get Element");
    }
    else{
        newElement=array[position];
        return newElement;
    }
}


//Not deletes the info just, set the "counter" to -1 to overwrite the info
template<class T, long long ARRAYSIZE>
    void List<T,ARRAYSIZE>::deleteAll(){
        last=-1;
    }

//Stores in a string all the list and return that
template<class T, long long ARRAYSIZE>
    std::string List<T,ARRAYSIZE>::print(){
        int position=0;
        std::string elementList;

        while(position<=last){
            elementList+="\n-------------------------------------------------------------------------------------\n";
            elementList+=array[position].toString();
            position++;
        }
        return elementList;
    }

//Store the specific info(position) and returns an object(info)
template<class T, long long ARRAYSIZE>
    std::string List<T,ARRAYSIZE>::print(const int& position) const{

        std::string elementInformation;

        elementInformation= array[position].toString();
        return elementInformation;
    }


template<class T, long long ARRAYSIZE>
void List<T,ARRAYSIZE>::editElement(const T&  newElement, const Integer& position){
    if(isEmpty() or !isValidPosition(position)){
        throw ListException("Not element to edit, editElement");
    }
    else{
        array[position]= newElement;
    }
}

//Linear Search
template<class T, long long ARRAYSIZE>
Integer List<T,ARRAYSIZE>::findDataLinear(const T&  newElement){
    Integer i(0);

    while (i<=last) {
        if(array[i]== newElement){
            return i;
        }

        i++;
    }

    return -1;
}   

template<class T, long long ARRAYSIZE>
Integer List<T,ARRAYSIZE>::findDataBinary(const T & newElement){
    Integer i(0), j(last), m;
    while (i<=j) {
        m=(i+j)/2;

        if(array[m]== newElement){
            return m;
        }

        if( newElement<array[m]){
            j=m-1;
        }
        else{
            i=m+1;
        }
    }
    return -1;
}


///Sorting METHODS////
template<class T, long long ARRAYSIZE>
void List<T,ARRAYSIZE>::swapData(const int& previousPosition, const int& nextPosition){

    T aux;

    aux=array[nextPosition];
    array[nextPosition]=array[previousPosition];
    array[previousPosition]=aux;

}


//This one is sorting by Tittle
template<class T, long long ARRAYSIZE>
void List<T,ARRAYSIZE>::bubbleSort(){

    int i(last),j;

    if(isEmpty()){
        throw ListException("No element to sort, bubbleSort");
    }
    else{
        while (i>0) {
            
            j=0;

            while (j<i) {

                if(array[j]>array[j+1]){
                    swapData(j,j+1);
                }

                j++;
                    
            }

            i--;

        }
    }

}

//This one is sorting by Integererpreter
template<class T, long long ARRAYSIZE>
void List<T,ARRAYSIZE>::shellSort(){

    float factor=(1.0/2.0);
    int differential=(last+1)*factor,i,j;
    if(isEmpty()){
        throw ListException("No element to sort, shellSort");
    }

    else{
        while (differential>0) {
            i=differential;

            while (i<=last) {
            
                j=i;

                while (j>=differential && array[j-differential]  > array[j]) {
                    swapData((j-differential),j);
                    j=j-differential;
                }

                i++;

            }

            differential=differential*factor;

            }
    }

}


//This one is by Integererpreter
template<class T, long long ARRAYSIZE>
void List<T,ARRAYSIZE>::insertSort(){
    int i(1),j;
    Integer aux;

    if(isEmpty()){
        throw ListException("No element to sort, insertSort");
    }
    else{

        while (i<=last) {
            aux=array[i];
            j=i;
            while (j>0 && aux< array[j-1]) {
                swapData(j,j-1);
                j--;
            }

            if (i!=j){
                array[j]=aux;
            }

            i++;

        }

    }
}

//This one is sorted by title
template<class T, long long ARRAYSIZE>
void List<T,ARRAYSIZE>::selectionSort(){
    int i(0),lesser,j;

    if(isEmpty()){
        throw ListException("No element to sort, insertSort");
    }

    else{

        while (i<last) {
            lesser=1;
            j=i+1;
            while (j<=last) {
                
                if(array[j]<array[lesser]){
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
}

template<class T, long long ARRAYSIZE>
void List<T,ARRAYSIZE>::mergeSort(){
    mergeSort(0,last);
}

template<class T, long long ARRAYSIZE>
void List<T,ARRAYSIZE>::mergeSort( int leftEdge, int rightEdge){


    if(isEmpty()){
        throw ListException("No element to sort, insertSort");
    }

    else{
        if(leftEdge>=rightEdge){
            return;
        }

        int m((leftEdge+rightEdge)/2);
        mergeSort(leftEdge,m);
        mergeSort(m+1,rightEdge);

        static T tempArray[ARRAYSIZE];
        for(int n(0);n<=last;n++){
            tempArray[n]=array[n];
        }

        int i(leftEdge),j(m+1),x(leftEdge);

        while (i<=m && j<=rightEdge) {
            while (i<=m && tempArray[i]<=tempArray[j]) {
                array[x++] = tempArray[i++];
            }

            if(i<=m){
                while (j<=rightEdge && tempArray[j]<=tempArray[i]) {
                    array[x++] = tempArray[j++];
                }
            }

        }

        while (i<=m) {
            array[x++] = tempArray[i++];
        }

        while (j<=rightEdge) {
            array[x++]=tempArray[j++];
        }

        
    }
}

template<class T, long long ARRAYSIZE>
void List<T,ARRAYSIZE>::quickSort(){
    quickSort(0,last);
}

template<class T, long long ARRAYSIZE>
void List<T,ARRAYSIZE>::quickSort(int leftEdge, int rigthEdge){

    if(isEmpty()){
        throw ListException("No element to sort, insertSort");
    }
    else{
        if(leftEdge>=rigthEdge){
            return;
        }

        int i(leftEdge), j(rigthEdge);
        while (i<j) {
            while (i<j and array[i]<= array[rigthEdge]) {
                i++;
            }

            while (i<j and array[j] >= array[rigthEdge]) {
                j--;
            }

            if(i!=j){
                swapData(i,j);
            }
        }

        if(i!=rigthEdge){
                swapData(i,rigthEdge);
            }
        quickSort(leftEdge,i-1);
        quickSort(i+1,rigthEdge);

    }

}

template<class T, long long ARRAYSIZE>
bool List<T,ARRAYSIZE>::isSorted(){
    int counter=0;
    while (counter<=100000) {
        if(array[counter]>array[counter+1]&&(array[999999]!=0)){
            return false;
        }
        counter++;
    }
    return true;
}


#endif // _LST_HPP_