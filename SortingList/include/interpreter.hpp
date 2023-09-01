#ifndef _INTERPRETER_HPP_
#define _INTERPRETER_HPP_

#include <iostream>

class Interpreter{

    private:
    //Atributes
    std::string firstName;
    std::string lastName;

    public:
    Interpreter(){}
    Interpreter(const Interpreter& a);

    //Getter and setter
    std::string getFirstName() const;
    std::string getLastName() const;
    void setFirstName(const std::string& );
    void setLastName(const std::string& );

    //Overload
    Interpreter& operator=(const Interpreter &);
    bool operator==(const Interpreter &);
    bool operator!=(const Interpreter &);
    bool operator<(const Interpreter &);
    bool operator<=(const Interpreter &);
    bool operator>(const Interpreter &);
    bool operator>=(const Interpreter &);

    //Other method
    std::string toString() const;

};

#endif // _ITERPRETER_HPP_