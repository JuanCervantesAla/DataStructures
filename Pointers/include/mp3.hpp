#ifndef _MP3_HPP_
#define _MP3_HPP_

#include <iostream>

class MP3{

    private:
    //Atributes
    std::string fileName;

    public:
    MP3(){}
    MP3(const MP3& );

    //Getter and setter
    std::string getFileName() const;
    void setFileName(const std::string& );

    //Overload
    MP3& operator=(const MP3 &);
    bool operator==(const MP3 &);
    bool operator!=(const MP3 &);
    bool operator<(const MP3 &);
    bool operator<=(const MP3 &);
    bool operator>(const MP3 &);
    bool operator>=(const MP3 &);

    //Other method
    std::string toString() const;

};

#endif // _MP3_HPP_