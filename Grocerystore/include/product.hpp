#ifndef _PRODUCT_HPP_
#define _PRODUCT_HPP_

#include <string>
#include "../include/date.hpp"

class Product
{

private:
    std::string barCode;
    std::string name;
    float wholesale, retail, price;
    int stock;
    Date entryDate;

public:
    std::string getBarCode() const ;
    std::string getName() const ;
    float getWholesale() const;
    float getRetail() const;
    float getPrice() const;
    int getStock() const;
    Date getDate() const;

    void setBarCode(const std::string&);
    void setName(const std::string&);
    void setWholesale(const float&);
    void setRetail(const float&);
    void setPrice(const float&);
    void setStock(const int&);
    void setDate(const Date&);

};

#endif // _PRODUCT_HPP_

