#ifndef _AUTHOR_HPP_
#define _AUTHOR_HPP_
#include <iostream>
#include <string>

class Author{

    private:
    //Atributes
    std::string firstName;
    std::string lastName;

    public:
    Author(){}
    Author(const Author& a);

    //Getter and setter
    std::string getFirstName() const;
    std::string getLastName() const;
    void setFirstName(const std::string& );
    void setLastName(const std::string& );

    //Overload
    Author& operator=(const Author &);
    bool operator==(const Author &);
    bool operator!=(const Author &);
    bool operator<(const Author &);
    bool operator<=(const Author &);
    bool operator>(const Author &);
    bool operator>=(const Author &);

    //Other method
    std::string toString() const;


};

#endif // _AUTHOR_HPP_
