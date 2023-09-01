#ifndef INCLUDED_INTEGER_HPP
#define INCLUDED_INTEGER_HPP

#include <iostream>
#include <istream>
#include <ostream>
#include <string>

class Integer {

    private:
    long long data;
    Integer *arrayData;
    

    public:
    Integer();
    Integer(const Integer&);
    Integer(long long);
    long long intValue() const;
    std::string toString() const;
    static std::string toString(const Integer&);
    Integer& operator ++();
    Integer operator++ (int);
    Integer& operator-- ();
    Integer operator-- (int );
    Integer operator+(const Integer&i);
    Integer operator-(const Integer&);
    Integer operator/(const Integer&);
    Integer operator*(const Integer&);
    Integer operator=(const Integer&) ;
    Integer operator=(const int&) ;
    Integer& operator[](int&);
    Integer& operator[](Integer&);
    Integer operator+=(const Integer&) ;
    Integer operator-=(const Integer&) ;
    Integer operator*=(const Integer&) ;
    Integer operator/=(const Integer&) ;
    bool operator== (const Integer&) const;
    bool operator!= (const Integer&) const;
    bool operator< (const Integer&) const;
    bool operator<= (const Integer&) const;
    bool operator> (const Integer&) const;
    bool operator>= (const Integer&) const;
    int compareTo(const Integer&) const;
    static int compare(const Integer&, const Integer&);
    friend std::istream& operator>> (std::istream&, Integer&);
    friend std::ostream& operator<< (std::ostream&, const Integer&);

};

std::istream& operator>> (std::istream& is, Integer&i){

    is>>i.data;
    return is;

}

std::ostream& operator<< (std::ostream&os, const Integer& i){

    os<<i.data;
    return os;

}

#endif // INCLUDED_INTEGER_HPP