#include "../include/product.hpp"
#include <string>


using namespace std;

std::string Product::getBarCode() const
{

    return barCode;

}

std::string Product::getName() const
{

    return name;

}

float Product::getWholesale() const
{

    return wholesale;

}

float Product::getRetail() const
{

    return retail;

}

float Product::getPrice() const
{

    return price;

}

int Product::getStock() const
{

    return stock;

}

Date Product::getDate() const
{

    return entryDate;

}

void Product::setBarCode(const std::string& newBarCode)
{

    barCode=newBarCode;

}

void Product::setName(const std::string& newName)
{

    name=newName;

}

void Product::setWholesale(const float& newWholeSale)
{

    wholesale=newWholeSale;

}

void Product::setRetail(const float& newRetail)
{

    retail=newRetail;

}

void Product::setPrice(const float& newPrice)
{

    price=newPrice;

}

void Product::setStock(const int& newStock)
{

    stock=newStock;

}

void Product::setDate(const Date & newDate)
{

    entryDate=newDate;

}
