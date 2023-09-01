#ifndef _COLLECTION_HPP_
#define _COLLECTION_HPP_

#include "../include/product.hpp"

class Collection
{

private:
    Product product[500];
    int actualProduct;

public:
    int getActualProduct() const;
    void setActualProduct(const int&);
    void setnewProduct(const int&, Product);
    void searchInExistenceProduct(const std::string&, const int&);
    void showProduct(const std::string&);

};

#endif // _COLLECTION_HPP_

