#ifndef _DATE_HPP_
#define _DATE_HPP_

class Date
{

private:
    int year;
    int month;
    int day;

public:
    int getYear() const;
    int getMonth() const;
    int getDay() const;

    void setYear(const int&);
    void setMonth(const int&);
    void setDay(const int&);

};

#endif // _DATE_HPP_
