#include "../include/date.hpp"

int Date::getYear() const
{
    return year;
}

int Date::getMonth() const
{
    return month;
}

int Date::getDay() const
{
    return day;
}

void Date::setYear(const int & newYear)
{
    year=newYear;
}

void Date::setMonth(const int & newMonth)
{
    month=newMonth;
}

void Date::setDay(const int & newDay)
{
    day=newDay;
}
