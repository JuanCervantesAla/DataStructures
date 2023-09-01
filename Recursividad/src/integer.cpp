#include "../include/integer.hpp"
#include <iterator>
#include <string>


Integer::Integer():data(0){}

Integer::Integer(const Integer& i):data(i.data){}

Integer::Integer(long long i):data(i){}



long long Integer::intValue() const{

    return data;

}

std::string Integer::toString() const{

    std::string returnString;
    returnString= std::to_string(data);
    return returnString;

}

 std::string Integer::toString(const Integer& i){

    std::string returnString;
    returnString = i.data;
    return returnString;

}


Integer Integer::operator++ (int i){
    
    return ++data;

}


Integer& Integer::operator ++(){

    ++data;
    return *this;

}

Integer& Integer::operator-- (){

    --data;
    return *this;

}

Integer Integer::operator-- (int i){

    return --data;

}

Integer Integer::operator+(const Integer&i){

    return data+i.data;

    }


Integer Integer::operator-(const Integer&i){

    return data-i.data;

}

Integer Integer::operator*(const Integer&i){

    return data*i.data;

}

Integer Integer::operator/(const Integer&i){

    return data / i.data;

}

Integer Integer::operator=(const int&i){

    if(data!=i){
        data = i;
    }

    return data;

}

Integer Integer::operator=(const Integer& i){

    if (this == &i)
        return *this;
 
    
    if (data != i.data) {
        data = 0;                     
        data = i.data;
    } 

    return *this;

}

Integer& Integer::operator[](int&i){
    return arrayData[i];
}

Integer& Integer::operator[](Integer&i){
    return arrayData[i.data];
}

Integer Integer::operator+=(const Integer& i){

    data += i.data;
    return data;

}

Integer Integer::operator-=(const Integer& i) {

    data -= i.data;
    return data;

}

Integer Integer::operator*=(const Integer& i) {

    data *= i.data;
    return data;


}

Integer Integer::operator/=(const Integer& i){

    data *= i.data;
    return data;

}


bool Integer::operator== (const Integer& i) const{

    return data == i.data;

}

bool Integer::operator!= (const Integer& i) const{

    return !(data==i.data);

}

bool Integer::operator< (const Integer& i) const{

    return data<i.data;

}

bool Integer::operator<= (const Integer& i) const{

    return (data< i.data) || (data==i.data);

}

bool Integer::operator> (const Integer& i) const{

    return !(data <= i.data);

}

bool Integer::operator >= (const Integer& i) const{

    return !(data < i.data);

}

